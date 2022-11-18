#include <stdlib.h>
#include "fields.h"

#define H 2.00

void uniform_magnetic (config manifold, vector *force)
{
	for (int n = 0; n < manifold.N; n++)
	{
		force[n].coordinate[1] += 
			manifold.particle[n].mass * -H;
	}
}	

