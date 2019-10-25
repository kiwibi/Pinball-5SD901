#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED

#include <math.h>

#ifndef C_PI

#define C_PI 3.141592f

#endif //C_PI

struct Vector2
{
	float x;
	float y;
};

struct Calculations
{
	static Vector2 Normalize(Vector2 A);		//make the vector 1 in magnitude
   static float Magnitude(Vector2 a);  //Get the length of the vector
	static float Dot(Vector2 A, Vector2 B);	//find the dot product of 2 vectors
	static Vector2 Rotate(Vector2 A, float radians);			//rotate a vector

   static Vector2 Subtraction(Vector2 LHS, Vector2 RHS); // Subtracts 2 vectors
   static Vector2 Addition(Vector2 lhs, Vector2 rhs);    // Adds 2 vectors
   static Vector2 Multiplication(Vector2 LHS, Vector2 RHS); // Multiplies 2 vectors
   static Vector2 Multiplication(Vector2 LHS, float RHS);   // Multiplies a vector by a scalar
};

#endif // !CALCULATIONS_H_INCLUDED