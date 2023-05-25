
#include "CntSecIncrementing.h"

using namespace std;

CntSecIncrementing::CntSecIncrementing()
	: Processing("CntSecIncrementing")
	, mCounter2(1)
	, mDepth(0)
{}

/* member functions */

Success CntSecIncrementing::initialize()
{
	if (mDepth >= 2)
		return Positive;

	CntSecIncrementing *pInc;

	pInc = CntSecIncrementing::create();
	if (!pInc)
		return procErrLog(-1, "could not create process");

	pInc->mDepth = mDepth + 1;

	start(pInc);

	return Positive;
}

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

