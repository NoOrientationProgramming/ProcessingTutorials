
#include <iostream>

#include "Supervising.h"

using namespace std;

Supervising::Supervising()
	: Processing("Supervising")
{}

Success Supervising::process()
{
	procDbgLog(0, "### Process debug message");
	procInfLog("### Process info");
	procWrnLog("### Process warning");
	procErrLog(-1, "### Process error");

	dbgLog(0, "### Static function debug message");
	infLog("### Static function info");
	wrnLog("### Static function warning");
	errLog(-1, "### Static function error");

	procInfLog("### Macro test: %s", "foo");

	return Positive;
}

