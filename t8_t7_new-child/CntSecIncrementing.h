
#ifndef CNT_SEC_INCREMENTING_H
#define CNT_SEC_INCREMENTING_H

#include "Processing.h"

class CntSecIncrementing : public Processing
{

public:

	static CntSecIncrementing *create()
	{
		return new (std::nothrow) CntSecIncrementing;
	}

protected:

	CntSecIncrementing();
	virtual ~CntSecIncrementing() {}

private:

	CntSecIncrementing(const CntSecIncrementing &) : Processing("") {}
	CntSecIncrementing &operator=(const CntSecIncrementing &) { return *this; }

	/*
	 * Naming of functions:  objectVerb()
	 * Example:              peerAdd()
	 */

	/* member functions */
	Success process();
	void processInfo(char *pBuf, char *pBufEnd);

	/* member variables */
	uint32_t mCounter2;

	/* static functions */

	/* static variables */

	/* constants */

};

#endif

