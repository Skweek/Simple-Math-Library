///////////////////////////////////////
// File:			Vec3.h
// Author:			Nick Smith
// Creation Date:	22nd April 2013
// Notes:			Vec3 3 class
///////////////////////////////////////

#ifndef _VEC3_H_
#define _VEC3_H_

#include "MathUtil.h"

class DECLDIR Vec3
{
public:
	//+===================================+//
	//	Constructors
	//+===================================+//
	Vec3();
	explicit Vec3( float* a_fpV2 );
	Vec3( float a_fX, float a_fY, float a_fZ );

	//+===================================+//
	//  Convert to float pointer	
	//+===================================+//
	operator		float*	()						{ return static_cast<float*>(m_fVec3);						}
	operator const	float*	() const				{ return static_cast<const float*>(m_fVec3);				}

	//+===================================+//
	//	Get the magnitude of the Vec3
	//  Returns result as a float	
	//+===================================+//
	float GetMagnitude();

	//+===================================+//
	//	Normalise the Vec3
	//  returns result as a Vec3	
	//+===================================+//
	Vec3 NormaliseVec3();

	//+===================================+//
	//	Linear Interpolation	
	//+===================================+//
	Vec3 LinearInterpolation( const Vec3& a_pVec1, float a_fDest );

	//+===================================+//
	//	Determine the dot product of two
	//  Vec3s and return as a float
	//+===================================+//
	float DotProduct( const Vec3& a_pVec1 );

	//+===================================+//
	//	Get the angle between two Vec3s
	//  returns a float	as degrees	
	//+===================================+//
	float GetAngle( const Vec3& a_pVec1 );
	
	//+===================================+//
	//	Equals operator overload
	//+===================================+//
	void	operator=		( const Vec3& a_Vec1 )	{	m_fX = a_Vec1.m_fX;		m_fY = a_Vec1.m_fY;		m_fZ = a_Vec1.m_fZ;				}
	bool	operator==		( const Vec3& a_Vec1 )	{	return ( m_fX == a_Vec1.m_fX && m_fY == a_Vec1.m_fY && m_fZ == a_Vec1.m_fZ );	}

	//+===================================+//
	//	Addition operator overload
	//+===================================+//
	Vec3	operator+		( const Vec3& a_Vec1 )	{	return Vec3( m_fX + a_Vec1.m_fX, m_fY + a_Vec1.m_fY, m_fZ + a_Vec1.m_fZ );		}
	Vec3	operator+		( const float a_fAdd )	{	return Vec3( m_fX + a_fAdd, m_fY + a_fAdd, m_fZ + a_fAdd				);		}
	void	operator+=		( const Vec3& a_Vec1 )	{	m_fX += a_Vec1.m_fX;	m_fY += a_Vec1.m_fY;		m_fZ += a_Vec1.m_fZ;		}
	void	operator+=		( const float a_fAdd )	{	m_fX += a_fAdd;	m_fY += a_fAdd;	m_fZ += a_fAdd;									}

	//+===================================+//
	//	Subtraction operator overload
	//+===================================+//
	Vec3	operator-		( const Vec3& a_Vec1 )	{	return Vec3( m_fX - a_Vec1.m_fX, m_fY - a_Vec1.m_fY, m_fZ - a_Vec1.m_fZ );		}
	Vec3	operator-		( const float a_fSub )	{	return Vec3( m_fX - a_fSub, m_fY - a_fSub, m_fZ - a_fSub				);		}
	void	operator-=		( const Vec3& a_Vec1 )	{	m_fX -= a_Vec1.m_fX;	m_fY -= a_Vec1.m_fY;		m_fZ -= a_Vec1.m_fZ;		}
	void	operator-=		( const float a_fSub )	{	m_fX -= a_fSub;	m_fY -= a_fSub;		m_fZ -= a_fSub;								}

	//+===================================+//
	//	Division operator overload
	//+===================================+//
	Vec3	operator/		( const float a_fDiv )	{	return Vec3( m_fX / a_fDiv, m_fY / a_fDiv, m_fZ / a_fDiv );						}
	Vec3	operator/		( const Vec3& a_Vec1 )	{	return Vec3( m_fX / a_Vec1.m_fX, m_fY / a_Vec1.m_fY, m_fZ / a_Vec1.m_fZ );		}
	void	operator/=		( const float a_fDiv )	{	m_fX /= a_fDiv;			m_fY /= a_fDiv;			m_fZ /= a_fDiv;					}
	void	operator/=		( const Vec3& a_Vec1 )	{	m_fX /= a_Vec1.m_fX;	m_fY /= a_Vec1.m_fY;		m_fZ /= a_Vec1.m_fZ;		}

	//+===================================+//
	//	Multiply operator overload
	//+===================================+//
	Vec3	operator*		( const float a_fMul )	{	return Vec3( m_fX * a_fMul, m_fY * a_fMul, m_fZ * a_fMul );						}
	Vec3	operator*		( const Vec3& a_Vec1 )	{	return Vec3( m_fX * a_Vec1.m_fX, m_fY * a_Vec1.m_fY, m_fZ * a_Vec1.m_fZ );		}
	void	operator*=		( const float a_fMul )	{	m_fX *= a_fMul;			m_fY *= a_fMul;			m_fZ /= a_fMul;					}
	void	operator*=		( const Vec3& a_Vec1 )	{	m_fX *= a_Vec1.m_fX;	m_fY *= a_Vec1.m_fY;		m_fZ *= a_Vec1.m_fZ;		}

	union
	{
		float m_fVec3[3];
		struct
		{
			float m_fX, m_fY, m_fZ;
		};
	};

};

#endif


