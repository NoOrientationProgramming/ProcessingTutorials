
#include <iostream>

#include "Supervising.h"
#include "SystemDebugging.h"

using namespace std;

Supervising::Supervising()
	: Processing("Supervising")
	, mCounter1(0)
	, mpChild(NULL)
	, mResultConsumed(false)
{}

Success Supervising::initialize()
{
	cout << "Data initialized" << endl;
	cout << "Service is running now" << endl;

	SystemDebugging *pDbg = SystemDebugging::create(this);
	if (!pDbg)
		return procErrLog(-1, "could not create process");

	start(pDbg);

	mpChild = CntSecIncrementing::create();
	if (!mpChild)
		return procErrLog(-1, "could not create process");

	start(mpChild);

	return Positive;
}

Success Supervising::process()
{
	Success success;

	++mCounter1;

	success = mpChild->success();
	if (success == Positive and !mResultConsumed)
	{
		cout << "Child counted up to: " << mpChild->mCounter2 << endl;

		// Result consumed
		// Now very important:
		// Child must be repelled.
		// Otherwise Zombie Process
		repel(mpChild);

		mResultConsumed = true;
	}

	return Pending;
}

void Supervising::processInfo(char *pBuf, char *pBufEnd)
{
	dInfo("Counter 1\t\t%d\n", mCounter1);
}

