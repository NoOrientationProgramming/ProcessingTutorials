
#ifndef SUPERVISING_H
#define SUPERVISING_H

#include "Processing.h"
#include "TcpListening.h"

class Supervising : public Processing
{

public:

	static Supervising *create()
	{
		return new (std::nothrow) Supervising;
	}

protected:

	Supervising();
	virtual ~Supervising() {}

private:

	Supervising(const Supervising &) = delete;
	Supervising &operator=(const Supervising &) = delete;

	Success initialize();
	Success process();

	TcpListening *mpList;

};

#endif

