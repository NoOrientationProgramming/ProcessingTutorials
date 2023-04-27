
#include <iostream>
#include <thread>

#include "Supervising.h"

using namespace std;

Supervising *pApp = NULL;

int main(int argc, char *argv[])
{
	levelLogSet(4);

	pApp = Supervising::create();
	if (!pApp)
	{
		cerr << "could not create process" << endl;
		return 1;
	}

	while (1)
	{
		pApp->treeTick();
		this_thread::sleep_for(chrono::milliseconds(2));

		if (pApp->progress())
			continue;

		break;
	}

	Success success = pApp->success();
	Processing::destroy(pApp);

	Processing::applicationClose();

	return !(success == Positive);
}

