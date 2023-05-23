
#include <iostream>

#include "Supervising.h"
#include "SystemDebugging.h"

using namespace std;

Supervising::Supervising()
	: Processing("Supervising")
	, mCounter1(0)
{}

Success Supervising::initialize()
{
	cout << "Data initialized" << endl;
	cout << "Service is running now" << endl;

	SystemDebugging *pDbg = SystemDebugging::create(this);
	if (!pDbg)
		return procErrLog(-1, "could not create process");

	start(pDbg);

	return Positive;
}

Success Supervising::process()
{
	++mCounter1;
	return Pending;
}

void Supervising::processInfo(char *pBuf, char *pBufEnd)
{
	dInfo("Counter 1\t\t%d\n", mCounter1);
}

