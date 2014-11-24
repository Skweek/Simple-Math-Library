///////////////////////////////////////
// File:			Matrix4.h
// Author:			Nick Smith
// Creation Date:	30th April 2013
// Notes:			Matrix4 class
///////////////////////////////////////

#ifndef _Matrix4_H_
#define	_Matrix4_H_

class Vec3;

#include "Vec4.h"

#include "MathUtil.h"

class DECLDIR Matrix4
{
public:
	//+===================================+//
	//	Constructors
	//+===================================+//
	Matrix4();
	Matrix4( float a_fMatrixArray[4][4] );
	Matrix4( float* a_fMatrix );
	Matrix4(	const float& a_f11,  const float& a_f12,  const float& a_f13,  const float& a_f14,  
				const float& a_f21,  const float& a_f22,  const float& a_f23,  const float& a_f24,  
				const float& a_f31,  const float& a_f32,  const float& a_f33,  const float& a_f34,  
				const float& a_f41,  const float& a_f42,  const float& a_f43,  const float& a_f44  );

	//+===================================+//
	//  Convert to float pointer	
	//+===================================+//
	operator		float*	()						{ return static_cast<float*>(m_fMatrixStructure_s);					}
	operator const	float*	() const				{ return static_cast<const float*>(m_fMatrixStructure_s);				}

	//+===================================+//
	//	Creates basic matrices
	//+===================================+//
	static const Matrix4 IdentityMatrix;
	static const Matrix4 OrthoView;
	static const Matrix4 ZeroMatrix;

	//+===================================+//
	//	Camera/View/Projection/Whatever matrices
	//+===================================+//
	void Perspective( float a_fFOV, float a_fAspect, float a_fNear, float a_fFar );
	void Ortho( const float& a_fLeft, const float& a_fRight, const float& a_fTop, const float& a_fBottom, const float& a_fNear, const float& a_fFar );
	void Camera( Vec4 pCameraLocation, Vec4 pLookingAt, Vec4 pUp );
	Matrix4 LookAt();

	//+===================================+//
	//	rotate matrices by a point
	//+===================================+//
	void RotateMatrixX( float a_fRotation );
	void RotateMatrixY( float a_fRotation );
	void RotateMatrixZ( float a_fRotation );
	
	//+===================================+//
	//	transform matrix by vector
	//+===================================+//
	Vec3 TransformPoint( Vec3 a_pVec3 );

	//+===================================+//
	//	Equals operator overload
	//+===================================+//
	void		operator=		( const Matrix4& a_Mat1 );
	bool		operator==		( const Matrix4& a_Mat1 );
	bool		operator!=		( const Matrix4& a_Mat1 );
	//+===================================+//
	//	Addition operator overload
	//+===================================+//
	Matrix4		operator+		( const Matrix4& a_Mat1 );
	Matrix4		operator+		( const Vec3& a_Vec3	);
	Matrix4		operator+=		( const Matrix4& a_Mat1 );
	Matrix4		operator+=		( const Vec3& a_Vec3	);
	//+===================================+//
	//	Subtraction operator overload
	//+===================================+//
	Matrix4		operator-		( const Matrix4& a_Mat1 );
	Matrix4		operator-		( const Vec3& a_Vec3	);
	Matrix4		operator-=		( const Matrix4& a_Mat1 );
	Matrix4		operator-=		( const Vec3& a_Vec3	);
	//+===================================+//
	//	Multiply operator overload
	//+===================================+//
	Matrix4		operator*		( const Matrix4& a_Mat1 );
	Matrix4&	operator*=		( const Matrix4& a_Mat1 );
	Matrix4		operator*		( const float& a_Float	);
	Matrix4&	operator*=		( const float& a_Float	);
	Vec4		operator*		( const Vec4& a_Vec4	);

	union
	{
		struct
		{
			float m_fMatrixStructure[4][4];
		};

		struct
		{
			float m_fMatrixStructure_s[16];
		};

		struct
		{
			float m_11, m_12, m_13, m_14;
			float m_21, m_22, m_23, m_24;
			float m_31, m_32, m_33, m_34;
			float m_41, m_42, m_43, m_44;
		};
		
		struct
		{
			Vec4 row0;
			Vec4 row1;
			Vec4 row2;
			Vec4 row3;
		};
	};
};

#endif