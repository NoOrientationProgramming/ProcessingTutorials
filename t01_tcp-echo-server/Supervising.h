
#ifndef SUPERVISING_H
#define SUPERVISING_H

#include "Processing.h"
#include "TcpListening.h"
#include "UserInteracting.h"

class Supervising : public Processing
{

public:

	static Supervising *create()
	{
		return new (std::nothrow) Supervising;
	}

protected:

	Supervising();
	virtual ~Supervising() {}

private:

	Supervising(const Supervising &) = delete;
	Supervising &operator=(const Supervising &) = delete;

	Success process();
	Success shutdown();
	void processInfo(char *pBuf, char *pBufEnd);

	bool servicesStart();
	void usersAdd();
	void usersRemove();
	void usersCancel();
	bool usersDone();

	uint32_t mStateSd;
	TcpListening *mpList;
	std::list<UserInteracting *> mListUsers;

};

#endif

