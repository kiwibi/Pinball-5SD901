#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED
#include <math.h>

struct Calculations
{
	Vector2 Normalize(Vector2 A);		//make the vector 1 in magnitude
	float Dot(Vector2 A, Vector2 B);	//find the dot product of 2 vectors
};

struct Vector2
{
	float x;
	float y;
};

#endif // !CALCULATIONS_H_INCLUDED

