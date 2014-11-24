#include <cmath>
#include "Maths.h"
#include "Vec3.h"

//+===================================+//
//	Constructors
//+===================================+//
Vec3::Vec3()
{
	m_fX = 0.f;
	m_fY = 0.f;
	m_fZ = 0.f;
}

Vec3::Vec3( float* a_fpV2 )
{
	m_fX = a_fpV2[0];
	m_fY = a_fpV2[1];
	m_fZ = a_fpV2[2];
}

Vec3::Vec3( float a_fX, float a_fY, float a_fZ )
{
	m_fX = a_fX;
	m_fY = a_fY;
	m_fZ = a_fZ;
}


//+===================================+//
//	Get the magnitude of the Vec3
//  Returns result as a float	
//+===================================+//
float Vec3::GetMagnitude()
{
return sqrt( ( m_fX * m_fX ) + ( m_fY * m_fY ) + ( m_fZ * m_fZ ) );
}

//+===================================+//
//	Linear Interpolation	
//+===================================+//
Vec3 Vec3::LinearInterpolation( const Vec3& a_pVec1, float a_fDest )
{
	Vec3 Result = *this + ( a_pVec1 - *this ) * a_fDest;
	return Result;
}

//+===================================+//
//	Normalise the Vec3
//  returns result as a Vec3	
//+===================================+//
Vec3 Vec3::NormaliseVec3()
{
	float fMag = GetMagnitude();
	if( fMag != 0 )
	{		
		return Vec3( ( m_fX / fMag ), ( m_fY / fMag ), ( m_fZ / fMag ) );
	}
	return Vec3( 0, 0, 0 );
}

//+===================================+//
//	Determine the dot product of two
//  Vec3s and return as a float
//+===================================+//
float Vec3::DotProduct( const Vec3& a_pVec1 )
{
return ( a_pVec1.m_fX * m_fX ) + ( a_pVec1.m_fY * m_fY ) + ( a_pVec1.m_fZ * m_fZ );
}

//+===================================+//
//	Get the angle between two Vec3s
//  returns a float	as degrees	
//+===================================+//
float Vec3::GetAngle( const Vec3& a_pVec1 )
{
	float fAngle;
	Vec3 Vec1; 
	Vec1 = NormaliseVec3 ();
	Vec3 Vec2 = a_pVec1;
	Vec2 = Vec2.NormaliseVec3 ();

	fAngle = acos( Vec1.DotProduct( Vec2 ) );
	fAngle = (float)Maths::RadToDeg( fAngle );

	return fAngle;
}
