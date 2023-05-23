
#ifndef SUPERVISING_H
#define SUPERVISING_H

#include "Processing.h"

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

	Supervising(const Supervising &) : Processing("") {}
	Supervising &operator=(const Supervising &) { return *this; }

	Success initialize();
	Success process();
	void processInfo(char *pBuf, char *pBufEnd);

	void cntSecProcess();

	uint32_t mCounter1;
	uint32_t mCounter2;

};

#endif

