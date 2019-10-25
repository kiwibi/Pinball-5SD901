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
