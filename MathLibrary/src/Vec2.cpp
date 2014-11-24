#include <cmath>
#include "Maths.h"
#include "Vec2.h"

//+===================================+//
//	Constructors
//+===================================+//
Vec2::Vec2()
{
	m_fX = 0.f;
	m_fY = 0.f;
}

Vec2::Vec2( float* a_fpV2 )
{
	m_fX = a_fpV2[0];
	m_fY = a_fpV2[1];
}


Vec2::Vec2( const float a_fX, const float a_fY )
{
	m_fX = a_fX;
	m_fY = a_fY;
}


//+===================================+//
//	Get the magnitude of the Vec2
//  Returns result as a float	
//+===================================+//
float Vec2::GetMagnitude()
{
	return sqrt( ( m_fX * m_fX ) + ( m_fY * m_fY ) );
}

//+===================================+//
//	Normalise the Vec2
//  returns result as a Vec2	
//+===================================+//
Vec2 Vec2::NormaliseVec2()
{
	float fMag = GetMagnitude();
	if( fMag != 0.f )
	{		
		return Vec2( ( m_fX / fMag ), ( m_fY / fMag ) );
	}
	return Vec2( 0, 0 );
}

//+===================================+//
//	Linear Interpolation	
//+===================================+//
Vec2 Vec2::LinearInterpolation( const Vec2& a_pVec1, float a_fDest )
{
	Vec2 Result = *this + ( a_pVec1 - *this ) * a_fDest;
	return Result;
}

//+===================================+//
//	Determine the dot product of two
//  Vec2s and return as a float
//+===================================+//
float Vec2::DotProduct( const Vec2& a_pVec1 )
{
	return ( a_pVec1.m_fX * m_fX ) + ( a_pVec1.m_fY * m_fY );
}

//+===================================+//
//	Rotate the Vec2 around a point
//  returns result as a Vec2	
//+===================================+//
Vec2 Vec2::RotateVec2( const Vec2& a_pVec1, float a_fRotationInDegrees )
{
	float s = (float)sin( Maths::DegToRad( -a_fRotationInDegrees ) );
	float c = (float)cos( Maths::DegToRad( -a_fRotationInDegrees ) );

	float fNewX = c * ( m_fX - a_pVec1.m_fX ) - s * ( m_fY - a_pVec1.m_fY ) + a_pVec1.m_fX;
	float fNewY = s * ( m_fX - a_pVec1.m_fX ) + c * ( m_fY - a_pVec1.m_fY ) + a_pVec1.m_fY;

	return Vec2( fNewX, fNewY );
}

//+===================================+//
//	Get the angle between two Vec2s
//  returns a float	as degrees	
//+===================================+//
float Vec2::GetAngle( const Vec2& a_pVec1 )
{
	float fAngle;

	Vec2 pVec1;
	pVec1= NormaliseVec2();
	Vec2 pVec2 = a_pVec1;
	pVec2 = pVec2.NormaliseVec2();

	fAngle = acos( pVec1.DotProduct( pVec2 ) );
	fAngle = (float)Maths::RadToDeg( fAngle );

	return fAngle;
}