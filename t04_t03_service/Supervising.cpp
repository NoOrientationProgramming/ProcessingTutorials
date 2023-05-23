
#include <iostream>

#include "Supervising.h"

using namespace std;

Supervising::Supervising()
	: Processing("Supervising")
{}

Success Supervising::initialize()
{
	cout << "Data initialized" << endl;
	cout << "Service is running now" << endl;
	return Positive;
}

Success Supervising::process()
{
	return Pending;
}

