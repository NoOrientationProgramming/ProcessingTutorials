
#include "CntSecIncrementing.h"

using namespace std;

CntSecIncrementing::CntSecIncrementing()
	: Processing("CntSecIncrementing")
	, mCounter2(1)
{}

/* member functions */

Success CntSecIncrementing::process()
{
	mCounter2 += 5;

	if (mCounter2 >= 30000)
		return Positive;

	return Pending;
}

void CntSecIncrementing::processInfo(char *pBuf, char *pBufEnd)
{
	dInfo("Counter 2\t\t%d\n", mCounter2);
}

/* static functions */

