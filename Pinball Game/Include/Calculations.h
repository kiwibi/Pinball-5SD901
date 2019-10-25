#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED
#define M_PI 3.141592f
#include <math.h>

struct Vector2
{
	float x;
	float y;
};

struct Calculations
{
	Vector2 Normalize(Vector2 A);		//make the vector 1 in magnitude
	float Dot(Vector2 A, Vector2 B);	//find the dot product of 2 vectors
	Vector2 Rotate(Vector2 A, float degrees);			//rotate a vector
};

#endif // !CALCULATIONS_H_INCLUDED