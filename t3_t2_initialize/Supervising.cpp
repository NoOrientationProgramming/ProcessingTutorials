
#include <iostream>

#include "Supervising.h"

using namespace std;

Supervising::Supervising()
	: Processing("Supervising")
{}

Success Supervising::initialize()
{
	cout << "Data initialized" << endl;
	return Positive;
}

Success Supervising::process()
{
	cout << "Data processed" << endl;
	return Positive;
}

