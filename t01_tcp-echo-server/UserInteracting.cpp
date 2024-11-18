
#include <iostream>

#include "UserInteracting.h"

using namespace std;

UserInteracting::UserInteracting(int fdPeer)
	: Processing("UserInteracting")
	, mFdPeer(fdPeer)
	, mpConn(NULL)
{}

Success UserInteracting::initialize()
{
	mpConn = TcpTransfering::create(mFdPeer);
	if (!mpConn)
		return procErrLog(-1, "could not create process");

	start(mpConn);

	procInfLog("Peer initialized");

	return Positive;
}

Success UserInteracting::process()
{
	ssize_t numBytesRead;
	char buf[59];

	numBytesRead = mpConn->read(buf, sizeof(buf) - 1);
	if (!numBytesRead)
		return Pending;

	if (numBytesRead < 0)
	{
		procInfLog("Peer disconnected");
		return Positive;
	}

	buf[numBytesRead] = 0;

	procInfLog("Data received: %zu bytes", numBytesRead);

	mpConn->send(buf, numBytesRead);

	return Pending;
}

