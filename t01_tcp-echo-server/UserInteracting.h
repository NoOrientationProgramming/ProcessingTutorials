
#ifndef USER_INTERACTING_H
#define USER_INTERACTING_H

#include "Processing.h"
#include "TcpTransfering.h"

class UserInteracting : public Processing
{

public:

	static UserInteracting *create(int fdPeer)
	{
		return new dNoThrow UserInteracting(fdPeer);
	}

	UserInteracting(int fdPeer);

protected:

	UserInteracting() = delete;
	virtual ~UserInteracting() {}

private:

	UserInteracting(const UserInteracting &) = delete;
	UserInteracting &operator=(const UserInteracting &) = delete;

	Success initialize();
	Success process();

	int mFdPeer;
	TcpTransfering *mpConn;

};

#endif

