///////////////////////////////////////
// File:			Trig.h
// Author:			Nick Smith
// Creation Date:	22nd April 2013
// Notes:			Trigonometry class
///////////////////////////////////////

#ifndef _TRIG_H_
#define _TRIG_H_

class Trig
{
public:
	/*	Constructors					*/
	Vector();
	Vector( float a_fX, float a_fY );


	/*	Get the magnitude of the vector		
		Returns result as a float		*/
	float GetMagnitude();

	/*	Normalise the vector
		returns result as a float		*/
	Vector NormaliseVector();

	/*	Determine the dot product of two
		vectors and return as a float	*/
	float DotProduct( Vector* a_pVec1, Vector* a_pVec2 );

	/*	Get the angle between two vectors
		returns a float	as degrees		*/
	float GetAngle( Vector* a_pVec1, Vector* a_pVec2 );
	
	/* Operator Overloads				*/
	bool	operator==		(const Vector& a_Vec1 )	{	return ( m_fX == a_Vec1.m_fX && m_fY == a_Vec1.m_fY );		}

	Vector	operator+		(const Vector& a_Vec1 )	{	return Vector( m_fX + a_Vec1.m_fX, m_fY + a_Vec1.m_fY );	}
	void	operator+=		(const Vector& a_Vec1 )	{	m_fX += a_Vec1.m_fX;	m_fY += a_Vec1.m_fY;				}

	Vector	operator-		(const Vector& a_Vec1 )	{	return Vector( m_fX - a_Vec1.m_fX, m_fY - a_Vec1.m_fY );	}
	void	operator-=		(const Vector& a_Vec1 )	{	m_fX -= a_Vec1.m_fX;	m_fY -= a_Vec1.m_fY;				}

	Vector	operator/		(const float a_fDiv	)	{	return Vector( m_fX / a_fDiv, m_fY / a_fDiv );				}
	void	operator/=		(const float a_fDiv )	{	m_fX /= a_fDiv;			m_fY /= a_fDiv;						}

	Vector	operator*		(const float a_fMul )	{	return Vector( m_fX * a_fMul, m_fY * a_fMul );				}
	void	operator*=		(const float a_fMul )	{	m_fX *= a_fMul;			m_fY *= a_fMul;						}

private:
	float m_fX;
	float m_fY;

};

#endif