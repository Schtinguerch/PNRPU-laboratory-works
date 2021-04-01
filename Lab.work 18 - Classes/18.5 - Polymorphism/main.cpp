#include <iostream>
#include "Triad.h"
#include "Time.h"
#include "Vector.h"
using namespace std;



int main()
{
	Vector vtr(10);
	
	Triad tr(253, 539, 5369);
	Time tm(23, 59, 59);
	Time tm2(11, 5, 12);
	
	vtr.AddTriad(&tr);
	vtr.AddTriad(&tm);
	vtr.AddTriad(&tm2);

	vtr.Print();
	
	return 0;
}