#include "constraints.h"

vector gs_distance_constraint (vector pos1, vector pos2, 
	double w1, double w2, double constraint)
{
	vector r = vector_subt(pos1, pos2);
	vector r_u = vector_unit(r); 
       	double r_m = vector_mag(r);

	vector correction = vector_mult(
			w1, 
			vector_mult(r_u, (r_m - constraint))
			);

	return correction; 	
}
