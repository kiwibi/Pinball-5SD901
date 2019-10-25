#include "Calculations.h"

Vector2 Calculations::Normalize(Vector2 A)
{
	Vector2 result;
	float magnitude = sqrtf((A.x * A.x) + (A.y * A.y));
	result.x = A.x / magnitude;
	result.y = A.y / magnitude;
	return result;
}

float Calculations::Dot(Vector2 A, Vector2 B)
{
	float result;
	result = ((A.x * B.x) + (A.y * B.y));
	return result;
}

Vector2 Calculations::Rotate(Vector2 A, float radian)
{
	Vector2 result;
	result.x = ((A.x * cosf(radian)) - (A.y * sinf(radian)));
	result.y = ((A.x * sinf(radian)) + (A.y * cosf(radian)));
	return result;
}

Vector2 Calculations::Subtraction(Vector2 LHS, Vector2 RHS)
{
   Vector2 Result;
   Result.x = LHS.x - RHS.x;
   Result.y = LHS.y - RHS.y;
   return Result;
}