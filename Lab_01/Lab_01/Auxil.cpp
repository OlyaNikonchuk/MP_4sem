#include "Auxil.h"
#include <ctime>

namespace auxil
{
	void start()
	{
		srand((unsigned)time(NULL));
	};
	double dget(double dmin, double dmax)
	{
		return ((double)rand() / (double)RAND_MAX) * (dmax - dmin) + dmin;
	};
	int iget(int imin, int imax)
	{
		return (int)dget((double)imin, (double)imax);
	}
}