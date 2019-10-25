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

Vector2 Calculations::Rotate(Vector2 A, float Radian)
{
	Vector2 result;
	result.x = ((A.x * cosf(Radian)) - (A.y * sinf(Radian)));
	result.y = ((A.x * sinf(Radian)) + (A.y * cosf(Radian)));
	return result;
}

