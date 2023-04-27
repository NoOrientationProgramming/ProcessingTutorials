
#include <iostream>

#include "Supervising.h"

using namespace std;

Supervising::Supervising()
	: Processing("Supervising")
{}

Success Supervising::process()
{
	cout << "Hello World! You finished your first process successfully!" << endl;
	return Positive;
}

