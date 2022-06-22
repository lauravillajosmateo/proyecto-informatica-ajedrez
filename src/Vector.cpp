#include "Vector.h"




Vector::Vector()
{
	x = 0;
	y = 0;
}

bool Vector::operator=(Vector vector)
{
	if (vector.x == x && vector.y == y)
	{
		return true;

	}
	else
		return false;
}