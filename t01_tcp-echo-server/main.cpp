
#include <iostream>
#include <thread>

#include "Supervising.h"
#ifdef __unix__
#include "signal.h"
#endif

using namespace std;

Processing *pApp = NULL;

#ifdef __unix__
void applicationCloseRequest(int signum)
{
	(void)signum;

	if (!pApp)
		return;

	cout << endl;
	pApp->unusedSet();
}
#endif

int main(int argc, char *argv[])
{
#ifdef __unix__
	signal(SIGINT, applicationCloseRequest);
	signal(SIGTERM, applicationCloseRequest);
#endif
	(void)argc;
	(void)argv;

	pApp = Supervising::create();
	if (!pApp)
	{
		cerr << "could not create process" << endl;
		return 1;
	}

	while (1)
	{
		pApp->treeTick();
		this_thread::sleep_for(chrono::milliseconds(10));

		if (pApp->progress())
			continue;

		break;
	}

	Success success = pApp->success();
	Processing::destroy(pApp);

	Processing::applicationClose();

	return !(success == Positive);
}

