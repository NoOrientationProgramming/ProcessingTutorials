
#include <iostream>

#include "Supervising.h"
#include "UserInteracting.h"
#include "SystemDebugging.h"

using namespace std;

Supervising::Supervising()
	: Processing("Supervising")
	, mpList(NULL)
{}

Success Supervising::initialize()
{
	Processing *pProc;

	pProc = SystemDebugging::create(this);
	if (!pProc)
		return procErrLog(-1, "could not create process");

	pProc->procTreeDisplaySet(false);
	start(pProc);

	mpList = TcpListening::create();
	if (!mpList)
		return procErrLog(-1, "could not create process");

	uint16_t port = 5000;
	mpList->portSet(port);

	start(mpList); // keep in main thread

	cout << "Listening on " << port << endl;

	return Positive;
}

Success Supervising::process()
{
	PipeEntry<int> peerFdEntry;
	int peerFd;

	if (mpList->ppPeerFd.get(peerFdEntry) < 1)
		return Pending;
	peerFd = peerFdEntry.particle;

	procInfLog("Peer connected");

	Processing *pUser;

	pUser = UserInteracting::create(peerFd);
	if (!pUser)
	{
		procWrnLog("could not create process");
		return Pending;
	}

	start(pUser, DrivenByNewInternalDriver); // start in new thread
	whenFinishedRepel(pUser); // detached

	return Pending;
}

