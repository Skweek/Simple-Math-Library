///////////////////////////////////////
// File:			Vector.h
// Author:			Nick Smith
// Creation Date:	22nd April 2013
// Notes:			Vector2 class
///////////////////////////////////////

#ifndef _VECTOR_OVERLOADS_H_
#define _VECTOR_OVERLOADS_H_

	/* Operator Overloads				*/
	bool operator== (const Vector& a_Vec1 )
	{
		return ( m_fX == a_Vec1.m_fX && m_fY == a_Vec1.m_fY );
	}

	void operator+ (const Vector& a_Vec1 )
	{
		m_fX += a_Vec1.m_fX;
		m_fY += a_Vec1.m_fY;
	}

	void operator- (const Vector& a_Vec1 )
	{
		m_fX -= a_Vec1.m_fX;
		m_fY -= a_Vec1.m_fY;
	}

#endif