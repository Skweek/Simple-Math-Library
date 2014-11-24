///////////////////////////////////////
// File:			Maths.h
// Author:			Nick Smith
// Creation Date:	14th May 2013
// Notes:			Other functions
///////////////////////////////////////

#ifndef _MATHS_H_
#define	_MATHS_H_

#include "MathUtil.h"

class DECLDIR Maths
{
public:
	unsigned int NextPowerOfTwo( unsigned int a_uiInput );
	float ScalarInterpolation( const float& a_pF1, const float& a_pF2, float a_fDest );

static	double	DegToRad ( float a_fDegrees );
static	double	RadToDeg ( float a_fRadians );

};

#endif // _MATHS_H_