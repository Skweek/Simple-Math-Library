///////////////////////////////////////
// File:			Vec4.h
// Author:			Nick Smith
// Creation Date:	30th April 2013
// Notes:			Vec4 class
///////////////////////////////////////

#ifndef _Vec4_H_
#define _Vec4_H_

#include "MathUtil.h"

class DECLDIR Vec4
{
public:
	//+===================================+//
	//	Constructors
	//+===================================+//
	Vec4();
	explicit Vec4( float* a_fpV2 );
	Vec4( float a_fX, float a_fY, float a_fZ, float a_fW );
	Vec4( unsigned int a_uiHex );
	

	//+===================================+//
	//  Convert to float pointer	
	//+===================================+//
	operator		float*	()						{ return static_cast<float*>(m_fVec4);						}
	operator const	float*	() const				{ return static_cast<const float*>(m_fVec4);				}

	//+===================================+//
	//	Get the magnitude of the Vec4
	//  Returns result as a float	
	//+===================================+//
	float GetMagnitude();

	//+===================================+//
	//	Normalise the Vec4
	//  returns result as a Vec4	
	//+===================================+//
	Vec4 NormaliseVec4();

	//+===================================+//
	//	Determine the dot product of two
	//  Vec4s and return as a float
	//+===================================+//
	float DotProduct( const Vec4& a_pVec1 );

	//+===================================+//
	//	Determine the cross product of two
	//  Vec4s and return as a vec4
	//+===================================+//
	Vec4 CrossProduct( const Vec4& a_pVec1 );

	//+===================================+//
	//	Equals operator overload
	//+===================================+//
	void	operator=		( const Vec4& a_Vec1 )	{	m_fX = a_Vec1.m_fX;		m_fY = a_Vec1.m_fY;		m_fZ = a_Vec1.m_fZ;		m_fW = a_Vec1.m_fW;				}
	bool	operator==		( const Vec4& a_Vec1 )	{	return ( m_fX == a_Vec1.m_fX && m_fY == a_Vec1.m_fY && m_fZ == a_Vec1.m_fZ && m_fW == a_Vec1.m_fW );	}

	//+===================================+//
	//	Addition operator overload
	//+===================================+//
	Vec4	operator+		( const Vec4& a_Vec1 )	{	return Vec4( m_fX + a_Vec1.m_fX, m_fY + a_Vec1.m_fY, m_fZ + a_Vec1.m_fZ, m_fW + a_Vec1.m_fW );			}
	Vec4&	operator+=		( const Vec4& a_Vec1 )	{	*this = *this + a_Vec1;		return *this;																}

	//+===================================+//
	//	Subtraction operator overload
	//+===================================+//
	Vec4	operator-		( const Vec4& a_Vec1 )	{	return Vec4( m_fX - a_Vec1.m_fX, m_fY - a_Vec1.m_fY, m_fZ - a_Vec1.m_fZ, m_fW - a_Vec1.m_fW );			}
	Vec4&	operator-=		( const Vec4& a_Vec1 )	{	*this = *this - a_Vec1;		return *this;																}

	//+===================================+//
	//	Division operator overload
	//+===================================+//
	Vec4	operator/		( const float a_fDiv )	{	return Vec4( m_fX / a_fDiv, m_fY / a_fDiv, m_fZ / a_fDiv, m_fW / a_fDiv );								}
	Vec4	operator/		( const Vec4& a_Vec1 )	{	return Vec4( m_fX / a_Vec1.m_fX, m_fY / a_Vec1.m_fY, m_fZ / a_Vec1.m_fZ, m_fW / a_Vec1.m_fW );			}
	Vec4&	operator/=		( const float a_fDiv )	{	*this = *this / a_fDiv;		return *this;																}
	Vec4&	operator/=		( const Vec4& a_Vec1 )	{	*this = *this / a_Vec1;		return *this;																}

	//+===================================+//
	//	Multiply operator overload
	//+===================================+//
	Vec4	operator*		( const float a_fMul )	{	return Vec4( m_fX * a_fMul, m_fY * a_fMul, m_fZ * a_fMul, m_fW * a_fMul );										}
	Vec4	operator*		( const Vec4& a_Vec1 )	{	return Vec4( m_fX * a_Vec1.m_fX, m_fY * a_Vec1.m_fY, m_fZ * a_Vec1.m_fZ, m_fW * a_Vec1.m_fW );			}
	Vec4&	operator*=		( const float a_fMul )	{	*this = *this * a_fMul;		return *this;																}
	Vec4&	operator*=		( const Vec4& a_Vec1 )	{	*this = *this * a_Vec1;		return *this;																}

	union
	{
		struct
		{
			float m_fVec4[4];
		};

		struct
		{
			float m_fX, m_fY, m_fZ, m_fW;
		};

		
	};

};

#endif


