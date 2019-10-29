#include "Calculations.h"

Vector2 Calculations::Normalize(Vector2 A)
{
   Vector2 result = { 0,0 };
	float magnitude = sqrtf((A.x * A.x) + (A.y * A.y));
   if (magnitude > 0.0f)
   {
	result.x = A.x / magnitude;
	result.y = A.y / magnitude;
   }
   return result;
}

float Calculations::Magnitude(Vector2 a)
{
   return sqrtf(( a.x * a.x ) + ( a.y * a.y ));
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
   Vector2 result;
   result.x = LHS.x - RHS.x;
   result.y = LHS.y - RHS.y;
   return result;
}

Vector2 Calculations::Addition(Vector2 lhs, Vector2 rhs)
{
   Vector2 result;
   result.x = lhs.x + rhs.x;
   result.y = lhs.y + rhs.y;
   return result;
}

Vector2 Calculations::Multiplication(Vector2 LHS, Vector2 RHS)
{
   Vector2 result;
   result.x = LHS.x * RHS.x;
   result.y = LHS.y * RHS.y;
   return result;
}

Vector2 Calculations::Multiplication(Vector2 LHS, float RHS)
{
   Vector2 result;
   result.x = LHS.x * RHS;
   result.y = LHS.y * RHS;
   return result;
}

float Calculations::CollisionAngle(Vector2 lhs, Vector2 rhs)
{
   float dot = Dot(lhs, rhs);
   float lhsMagnitude = Magnitude(lhs);
   float rhsMagnitude = Magnitude(rhs);
   float result = acosf(( dot / ( lhsMagnitude * rhsMagnitude ) ));
   return result;
}