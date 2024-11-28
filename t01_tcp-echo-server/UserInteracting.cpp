
#include <iostream>

#include "UserInteracting.h"

using namespace std;

UserInteracting::UserInteracting(int fdPeer)
	: Processing("UserInteracting")
	, mFdPeer(fdPeer)
	, mpConn(NULL)
	, mMsgLast("")
	, mConnIsDown(false)
	, mQuitByUser(false)
	, mInfoShutdownSent(false)
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
	Success success;
	string msg;

	success = msgReceive(msg);
	if (success == Pending)
		return Pending;

	if (success != Positive)
	{
		mConnIsDown = true;
		return Positive;
	}

	if (msg == "quit")
	{
		procInfLog("Peer quit");
		mQuitByUser = true;
		return Positive;
	}

	mMsgLast = msg;
	msg += "\r\n";

	mpConn->send(msg.c_str(), msg.size());

	return Pending;
}

Success UserInteracting::shutdown()
{
	if (mConnIsDown)
		return Positive;

	string msg;

	if (mQuitByUser)
	{
		msg = "Bye bye!\r\n";
		mpConn->send(msg.c_str(), msg.size());
		return Positive;
	}

	if (!mInfoShutdownSent)
	{
		mInfoShutdownSent = true;

		msg = "Server wants to say good bye!\r\n";
		msg += "Send a last message <3 :-*\r\n";

		mpConn->send(msg.c_str(), msg.size());

		return Pending;
	}

	Success success;

	success = msgReceive(msg);
	if (success == Pending)
		return Pending;

	if (success != Positive)
		return Positive;

	msg = "Bye bye!\r\n";
	mpConn->send(msg.c_str(), msg.size());

	return Positive;
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

	return Positive;
}

void UserInteracting::processInfo(char *pBuf, char *pBufEnd)
{
	dInfo("Last message\t\t%s",
			mMsgLast.size() ? mMsgLast.c_str() : "-");
}

