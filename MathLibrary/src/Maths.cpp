#include "Maths.h"

double	Maths::DegToRad ( float a_fDegrees )
{
	return ( a_fDegrees / 180 ) * PI;	
}

double	Maths::RadToDeg ( float a_fRadians )
{
	return ( a_fRadians / PI ) * 180;
}

unsigned int Maths::NextPowerOfTwo( unsigned int a_iInput )
{
	--a_iInput;

	a_iInput |= a_iInput >> 1;
	a_iInput |= a_iInput >> 2;
	a_iInput |= a_iInput >> 4;
	a_iInput |= a_iInput >> 8;
	a_iInput |= a_iInput >> 16;

	++a_iInput;

	return a_iInput;
}

float ScalarInterpolation( const float& a_pF1, const float& a_pF2, float a_fDest )
{
	float Result = a_pF1 + ( a_pF2 - a_pF1 ) * a_fDest;
	return Result;
}