
#include <iostream>

#include "UserInteracting.h"

#define dForEach_ProcState(gen) \
		gen(StStart) \
		gen(StMain) \

#define dGenProcStateEnum(s) s,
dProcessStateEnum(ProcState);

#define dForEach_SdState(gen) \
		gen(StSdStart) \
		gen(StSdUserAckWait) \

#define dGenSdStateEnum(s) s,
dProcessStateEnum(SdState);

using namespace std;

extern bool shutdownRequested;

UserInteracting::UserInteracting(int fdPeer)
	: Processing("UserInteracting")
	, mStateSd(StSdStart)
	, mFdPeer(fdPeer)
	, mpConn(NULL)
	, mMsgLast("")
	, mQuitByUser(false)
{
	mState = StStart;
}

Success UserInteracting::process()
{
	Success success;
	string msg;
#if 0
	dStateTrace;
#endif
	switch (mState)
	{
	case StStart:

		mpConn = TcpTransfering::create(mFdPeer);
		if (!mpConn)
			return procErrLog(-1, "could not create process");

		start(mpConn);

		procInfLog("Peer initialized");

		mState = StMain;

		break;
	case StMain:

		success = msgReceive(msg);
		if (success == Pending)
			return Pending;

		if (success != Positive)
			return Positive;

		if (msg == "quit")
		{
			procInfLog("Peer quit");
			mQuitByUser = true;
			return Positive;
		}

		if (msg == "shutdown")
		{
			procInfLog("Shutdown requested");
			shutdownRequested = true;
			return Positive;
		}

		break;
	default:
		break;
	}

	if (!msg.size())
		return Pending;

	msg += "\r\n";
	mpConn->send(msg.c_str(), msg.size());

	return Pending;
}

Success UserInteracting::shutdown()
{
	Success success;
	string msg;

	switch (mStateSd)
	{
	case StSdStart:

		if (mQuitByUser)
		{
			msg = "Bye bye!\r\n";
			mpConn->send(msg.c_str(), msg.size());
			return Positive;
		}

		msg = "Server wants to say good bye!\r\n";
		msg += "Send a last message <3 :-*\r\n";

		mpConn->send(msg.c_str(), msg.size());

		mStateSd = StSdUserAckWait;

		break;
	case StSdUserAckWait:

		success = msgReceive(msg);
		if (success == Pending)
			return Pending;

		if (success != Positive)
			return Positive;

		msg = "Bye bye!\r\n";
		mpConn->send(msg.c_str(), msg.size());

		return Positive;

		break;
	default:
		break;
	}

	return Pending;
}

Success UserInteracting::msgReceive(string &msg)
{
	ssize_t numBytesRead;
	char buf[59];

	numBytesRead = mpConn->read(buf, sizeof(buf) - 1);
	if (!numBytesRead)
		return Pending;

	if (numBytesRead < 0)
	{
		procInfLog("Peer disconnected");
		return -1;
	}

	buf[numBytesRead] = 0;

	if (!isprint(buf[0]))
		return Pending;

	msg = buf;

	if (msg.size() && msg.back() == '\n')
		msg.pop_back();

	if (msg.size() && msg.back() == '\r')
		msg.pop_back();

	procInfLog("Message received: '%s'", msg.c_str());

	mMsgLast = msg;

	return Positive;
}

void UserInteracting::processInfo(char *pBuf, char *pBufEnd)
{
	dInfo("Last message\t\t%s",
			mMsgLast.size() ? mMsgLast.c_str() : "-");
}

