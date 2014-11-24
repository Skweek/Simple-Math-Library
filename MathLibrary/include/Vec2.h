///////////////////////////////////////
// File:			Vec2.h
// Author:			Nick Smith
// Creation Date:	22nd April 2013
// Notes:			Vector 2 class
///////////////////////////////////////

#ifndef _VEC2_H_
#define _VEC2_H_

#include "MathUtil.h"

class DECLDIR Vec2
{
public:
	//+===================================+//
	//	Constructors
	//+===================================+//
	Vec2();
	explicit Vec2( float* a_fpV2 );
	Vec2( const float a_fX, const float a_fY );

	//+===================================+//
	//  Convert to float pointer	
	//+===================================+//
	operator		float*	()						{ return static_cast<float*>(m_fVec2);						}
	operator const	float*	() const				{ return static_cast<const float*>(m_fVec2);				}
	
	//+===================================+//
	//	Equals operator overload
	//+===================================+//
	void	operator=		( const Vec2& a_Vec1 )	{	m_fX = a_Vec1.m_fX;		m_fY = a_Vec1.m_fY;				}
	bool	operator==		( const Vec2& a_Vec1 )	{	return ( m_fX == a_Vec1.m_fX && m_fY == a_Vec1.m_fY );	}

	//+===================================+//
	//	Addition operator overload
	//+===================================+//
	Vec2	operator+		( const Vec2& a_Vec1 )	{	return Vec2( m_fX + a_Vec1.m_fX, m_fY + a_Vec1.m_fY );	}
	Vec2	operator+		( const float a_fAdd )	{	return Vec2( m_fX + a_fAdd, m_fY + a_fAdd );			}
	void	operator+=		( const Vec2& a_Vec1 )	{	m_fX += a_Vec1.m_fX;	m_fY += a_Vec1.m_fY;			}
	void	operator+=		( const float a_fAdd )	{	m_fX += a_fAdd;	m_fY += a_fAdd;							}

	//+===================================+//
	//	Subtraction operator overload
	//+===================================+//
	Vec2	operator-		( const Vec2& a_Vec1 )	{	return Vec2( m_fX - a_Vec1.m_fX, m_fY - a_Vec1.m_fY );	}
	Vec2	operator-		( const float a_fSub )	{	return Vec2( m_fX - a_fSub, m_fY - a_fSub );			}
	void	operator-=		( const Vec2& a_Vec1 )	{	m_fX -= a_Vec1.m_fX;	m_fY -= a_Vec1.m_fY;			}
	void	operator-=		( const float a_fSub )	{	m_fX -= a_fSub;	m_fY -= a_fSub;							}

	//+===================================+//
	//	Division operator overload
	//+===================================+//
	Vec2	operator/		( const float a_fDiv )	{	return Vec2( m_fX / a_fDiv, m_fY / a_fDiv );			}
	Vec2	operator/		( const Vec2& a_Vec1 )	{	return Vec2( m_fX / a_Vec1.m_fX, m_fY / a_Vec1.m_fY );	}
	void	operator/=		( const float a_fDiv )	{	m_fX /= a_fDiv;			m_fY /= a_fDiv;					}
	void	operator/=		( const Vec2& a_Vec1 )	{	m_fX /= a_Vec1.m_fX;	m_fY /= a_Vec1.m_fY;			}

	//+===================================+//
	//	Multiply operator overload
	//+===================================+//
	Vec2	operator*		( const float a_fMul )	{	return Vec2( m_fX * a_fMul, m_fY * a_fMul );			}
	Vec2	operator*		( const Vec2& a_Vec1 )	{	return Vec2( m_fX * a_Vec1.m_fX, m_fY * a_Vec1.m_fY );	}
	void	operator*=		( const float a_fMul )	{	m_fX *= a_fMul;			m_fY *= a_fMul;					}
	void	operator*=		( const Vec2& a_Vec1 )	{	m_fX *= a_Vec1.m_fX;	m_fY *= a_Vec1.m_fY;			}

	
	//+===================================+//
	//	Get the magnitude of the Vec2
	//  Returns result as a float	
	//+===================================+//
	float GetMagnitude();

	//+===================================+//
	//	Normalise the Vec2
	//  returns result as a Vec2	
	//+===================================+//
	Vec2 NormaliseVec2();

	//+===================================+//
	//	Linear Interpolation	
	//+===================================+//
	Vec2 LinearInterpolation( const Vec2& a_pVec1, float a_fDest );

	//+===================================+//
	//	Rotate the Vec2
	//  returns result as a Vec2	
	//+===================================+//
	Vec2 RotateVec2( const Vec2& a_pVec1, float a_fRotationInDegrees );

	//+===================================+//
	//	Determine the dot product of two
	//  Vec2s and return as a float
	//+===================================+//
	float DotProduct( const Vec2& a_pVec1 );

	//+===================================+//
	//	Get the angle between two Vec2s
	//  returns a float	as degrees	
	//+===================================+//
	float GetAngle( const Vec2& a_pVec1 );

	union
	{
		struct
		{
			float m_fVec2[2];
		};

		struct
		{
			float m_fX, m_fY;
		};
	};

};

#endif


