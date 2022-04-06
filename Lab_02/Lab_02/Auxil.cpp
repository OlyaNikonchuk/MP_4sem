#include "pch.h" 
#include "Auxil.h" 
#include <ctime>
// ctime -         
namespace auxil
{
	void start() //   . 
	{
		srand((unsigned)time(NULL));
		// time -    1  1970 
		// srand -     rand,     ,      
	};
	double dget(double rmin, double rmax) //     
	{
		return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
	};
	int iget(int rmin, int rmax) //     
	{
		return (int)dget((double)rmin, (double)rmax);
	};
}