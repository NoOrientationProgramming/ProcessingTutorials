
#include <iostream>

#include "Supervising.h"
#include "SystemDebugging.h"

#define dForEach_ProcState(gen) \
		gen(StStart) \
		gen(StMain) \

#define dGenProcStateEnum(s) s,
dProcessStateEnum(ProcState);

#if 1
#define dGenProcStateString(s) #s,
dProcessStateStr(ProcState);
#endif

#define dForEach_SdState(gen) \
		gen(StSdStart) \
		gen(StSdUsersDoneWait) \

#define dGenSdStateEnum(s) s,
dProcessStateEnum(SdState);

#if 1
#define dGenSdStateString(s) #s,
dProcessStateStr(SdState);
#endif

using namespace std;

bool shutdownRequested = false;

Supervising::Supervising()
	: Processing("Supervising")
	, mStateSd(StSdStart)
	, mpList(NULL)
	, mListUsers()
{
	mState = StStart;
}

Success Supervising::process()
{
	bool ok;
#if 0
	dStateTrace;
#endif
	switch (mState)
	{
	case StStart:

		ok = servicesStart();
		if (!ok)
			return Positive;

		mState = StMain;

		break;
	case StMain:

		usersAdd();
		usersRemove();

		if (shutdownRequested)
			return Positive;

		break;
	default:
		break;
	}

	return Pending;
}

Success Supervising::shutdown()
{
	switch (mStateSd)
	{
	case StSdStart:

		if (!mListUsers.size())
			return Positive;

		usersCancel();

		procWrnLog("shutdown initiated. all users must accept first");

		mStateSd = StSdUsersDoneWait;

		break;
	case StSdUsersDoneWait:

		if (!usersDone())
			return Pending;

		return Positive;

		break;
	default:
		break;
	}

	return Pending;
}

bool Supervising::servicesStart()
{
	Processing *pProc;

	pProc = SystemDebugging::create(this);
	if (!pProc)
	{
		procWrnLog("could not create process");
		return false;
	}

	pProc->procTreeDisplaySet(false);
	start(pProc);

	mpList = TcpListening::create();
	if (!mpList)
	{
		procWrnLog("could not create process");
		return false;
	}

	uint16_t port = 5000;
	mpList->portSet(port);

	start(mpList); // start in main thread

	cout << "Listening on " << port << endl;

	return true;
}

void Supervising::usersAdd()
{
	PipeEntry<int> peerFdEntry;
	int peerFd;

	if (mpList->ppPeerFd.get(peerFdEntry) < 1)
		return;
	peerFd = peerFdEntry.particle;

	procInfLog("Peer connected");

	UserInteracting *pUser;

	pUser = UserInteracting::create(peerFd);
	if (!pUser)
	{
		procWrnLog("could not create process");
		return;
	}

	start(pUser, DrivenByNewInternalDriver); // start in new thread

	mListUsers.push_back(pUser);
}

void Supervising::usersRemove()
{
	list<UserInteracting *>::iterator iUser;
	UserInteracting *pUser;

	iUser = mListUsers.begin();
	while (iUser != mListUsers.end())
	{
		pUser = *iUser;

		if (pUser->progress())
		{
			++iUser;
			continue;
		}

		repel(pUser);

		iUser = mListUsers.erase(iUser);
	}
}

void Supervising::usersCancel()
{
	list<UserInteracting *>::iterator iUser;

	iUser = mListUsers.begin();
	for (; iUser != mListUsers.end(); ++iUser)
		cancel(*iUser);
}

bool Supervising::usersDone()
{
	list<UserInteracting *>::iterator iUser;

	iUser = mListUsers.begin();
	for (; iUser != mListUsers.end(); ++iUser)
	{
		if((*iUser)->progress())
			return false;
	}

	return true;
}

void Supervising::processInfo(char *pBuf, char *pBufEnd)
{
#if 1
	dInfo("State\t\t\t%s\n", ProcStateString[mState]);
	dInfo("State shutdown\t%s\n", SdStateString[mStateSd]);
#endif
}

