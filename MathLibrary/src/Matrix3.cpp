#include "Matrix3.h"

#include "Vec3.h"

// Define a shorthand term for the matrix variable (neatens things up a bit)
#define mat m_fMatrixStructure

Matrix3::Matrix3()
{
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			mat[i][j] = 0.f; 
		}
	}	
}

Matrix3::Matrix3( float a_fMatrixArray[3][3] )
{
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			mat[i][j] = a_fMatrixArray[i][j]; 
		}
	}	
}

Matrix3::Matrix3(	const float& a_f11,  const float& a_f12,  const float& a_f13,  
					const float& a_f21,  const float& a_f22,  const float& a_f23,  
					const float& a_f31,  const float& a_f32,  const float& a_f33 )
{
	m_11 = a_f11;	m_12 = a_f12;	m_13 = a_f13;	
	m_21 = a_f21;	m_22 = a_f22;	m_23 = a_f23;	
	m_31 = a_f31;	m_32 = a_f32;	m_33 = a_f33;	
}
																																																																																																																																						#pragma region Operator Overloads

//+===================================+//
//	Equals operator overload
//+===================================+//
void Matrix3::operator= ( const Matrix3& a_Mat1 )
{
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			mat[i][j] = a_Mat1.mat[i][j]; 
		}
	}	
}
bool Matrix3::operator==	( const Matrix3& a_Mat1 )
{
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			if( mat[i][j] != a_Mat1.mat[i][j] )
			{
				return false;
			}
		}
	}	

	return true;
}

bool Matrix3::operator!=	( const Matrix3& a_Mat1 )
{
	for( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 3; ++j )
		{
			if( mat[i][j] != a_Mat1.mat[i][j] )
			{
				return true;
			}
		}
	}	

	return false;
}
//+===================================+//
//	Addition operator overload
//+===================================+//
Matrix3 Matrix3::operator+ ( const Matrix3& a_Mat1 )
{
	float a_fMatrixArray[3][3] = 
	{
		mat[0][0] + a_Mat1.mat[0][0], mat[0][1] + a_Mat1.mat[0][1], mat[0][2] + a_Mat1.mat[0][2],
		mat[1][0] + a_Mat1.mat[1][0], mat[1][1] + a_Mat1.mat[1][1], mat[1][2] + a_Mat1.mat[1][2],
		mat[2][0] + a_Mat1.mat[2][0], mat[2][1] + a_Mat1.mat[2][1], mat[2][2] + a_Mat1.mat[2][2],
	};

	return Matrix3( a_fMatrixArray );
}

Matrix3 Matrix3::operator+ ( const Vec3& a_Vec3	)
{
	float a_fMatrixArray[3][3] = 
	{
		mat[0][0], mat[0][1], mat[0][2],
		mat[1][0], mat[1][1], mat[1][2],
		mat[2][0] + a_Vec3.m_fX, mat[2][1] + a_Vec3.m_fY, mat[2][2] + a_Vec3.m_fZ,
	};

	return Matrix3( a_fMatrixArray );
}

Matrix3 Matrix3::operator+=	( const Matrix3& a_Mat1 )
{
	*this = *this + a_Mat1;
	return *this;
}

Matrix3 Matrix3::operator+=	( const Vec3& a_Vec3	)
{
	*this = *this + a_Vec3;
	return *this;
}

//+===================================+//
//	Subtraction operator overload
//+===================================+//
Matrix3 Matrix3::operator- ( const Matrix3& a_Mat1 )
{
	float a_fMatrixArray[3][3] = 
	{
		mat[0][0] - a_Mat1.mat[0][0], mat[0][1] - a_Mat1.mat[0][1], mat[0][2] - a_Mat1.mat[0][2],
		mat[1][0] - a_Mat1.mat[1][0], mat[1][1] - a_Mat1.mat[1][1], mat[1][2] - a_Mat1.mat[1][2],
		mat[2][0] - a_Mat1.mat[2][0], mat[2][1] - a_Mat1.mat[2][1], mat[2][2] - a_Mat1.mat[2][2],
	};

	return Matrix3( a_fMatrixArray );
}

Matrix3 Matrix3::operator- ( const Vec3& a_Vec3	)
{
	float a_fMatrixArray[3][3] = 
	{
		mat[0][0], mat[0][1], mat[0][2],
		mat[1][0], mat[1][1], mat[1][2],
		mat[2][0] - a_Vec3.m_fX, mat[2][1] - a_Vec3.m_fY, mat[2][2] - a_Vec3.m_fZ,
	};

	return Matrix3( a_fMatrixArray );
}

Matrix3 Matrix3::operator-=	( const Matrix3& a_Mat1 )
{
	*this = *this - a_Mat1;
	return *this;
}

Matrix3 Matrix3::operator-=	( const Vec3& a_Vec3	)
{
	*this = *this - a_Vec3;
	return *this;
}
//+===================================+//
//	Multiply operator overload
//+===================================+//
Matrix3 Matrix3::operator* ( const Matrix3& a_Mat1 )
{
	float a_fMatrixArray[3][3] = 
	{
		( mat[0][0] * a_Mat1.mat[0][0] ) + ( mat[0][1] * a_Mat1.mat[1][0] ) + ( mat[0][2] * a_Mat1.mat[2][0] ), // 0, 0
		( mat[0][0] * a_Mat1.mat[0][1] ) + ( mat[0][1] * a_Mat1.mat[1][1] ) + ( mat[0][2] * a_Mat1.mat[2][1] ), // 1, 0
		( mat[0][0] * a_Mat1.mat[0][2] ) + ( mat[0][1] * a_Mat1.mat[1][2] ) + ( mat[0][2] * a_Mat1.mat[2][2] ), // 2, 0
											 							  
		( mat[1][0] * a_Mat1.mat[0][0] ) + ( mat[1][1] * a_Mat1.mat[1][0] ) + ( mat[1][2] * a_Mat1.mat[2][0] ), // 0, 1
		( mat[1][0] * a_Mat1.mat[0][1] ) + ( mat[1][1] * a_Mat1.mat[1][1] ) + ( mat[1][2] * a_Mat1.mat[2][1] ), // 1, 1
		( mat[1][0] * a_Mat1.mat[0][2] ) + ( mat[1][1] * a_Mat1.mat[1][2] ) + ( mat[1][2] * a_Mat1.mat[2][2] ), // 2, 1
											 							  
		( mat[2][0] * a_Mat1.mat[0][0] ) + ( mat[2][1] * a_Mat1.mat[1][0] ) + ( mat[2][2] * a_Mat1.mat[2][0] ), // 0, 2
		( mat[2][0] * a_Mat1.mat[0][1] ) + ( mat[2][1] * a_Mat1.mat[1][1] ) + ( mat[2][2] * a_Mat1.mat[2][1] ), // 1, 2
		( mat[2][0] * a_Mat1.mat[0][2] ) + ( mat[2][1] * a_Mat1.mat[1][2] ) + ( mat[2][2] * a_Mat1.mat[2][2] ), // 2, 2
	};

	return Matrix3( a_fMatrixArray );
}

Matrix3 Matrix3::operator* ( const float& a_Float )
{
	float a_fMatrixArray[3][3] = 
	{
		( mat[0][0] * a_Float ), // 0, 0
		( mat[1][0] * a_Float ), // 1, 0
		( mat[2][0] * a_Float ), // 2, 0
											 							  
		( mat[0][1] * a_Float ), // 0, 1
		( mat[1][1] * a_Float ), // 1, 1
		( mat[2][1] * a_Float ), // 2, 1
											 							  
		( mat[0][2] * a_Float ), // 0, 2
		( mat[1][2] * a_Float ), // 1, 2
		( mat[2][2] * a_Float ), // 2, 2
	};

	return Matrix3( a_fMatrixArray );
}

Vec3 Matrix3::operator* ( const Vec3& a_Vec3 )
{
	Vec3 a_fNewVec3 = 
	Vec3(
		( mat[0][0] * a_Vec3.m_fX ) + ( mat[0][1] * a_Vec3.m_fY ) + ( mat[0][2] * a_Vec3.m_fZ ),
		( mat[1][0] * a_Vec3.m_fX ) + ( mat[1][1] * a_Vec3.m_fY ) + ( mat[1][2] * a_Vec3.m_fZ ),
		( mat[2][0] * a_Vec3.m_fX ) + ( mat[2][1] * a_Vec3.m_fY ) + ( mat[2][2] * a_Vec3.m_fZ ) 
	);

	return a_fNewVec3;
}

Matrix3& Matrix3::operator*=	( const Matrix3& a_Mat1 )
{
	*this = *this * a_Mat1;
	return *this;
		
}

Matrix3& Matrix3::operator*=	( const float& a_Float )
{
	*this = *this * a_Float;
	return *this;
		
}

#pragma endregion

//+===================================+//
//	Creates basic matrices
//+===================================+//
Matrix3 Matrix3::IdentityMatrix()
{
	float fMatrixArray[3][3] = 
	{
		1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 0.f, 1.f,
	};

	return Matrix3( fMatrixArray );
}

Matrix3 Matrix3::OrthoView()
{
	float fMatrixArray[3][3] = 
	{
		1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 0.f, 0.f,
	};

	return Matrix3( fMatrixArray );
}

Matrix3 Matrix3::ZeroMatrix()
{
	float fMatrixArray[3][3] = 
	{
		0.f, 0.f, 0.f,
		0.f, 0.f, 0.f,
		0.f, 0.f, 0.f,
	};

	return Matrix3( fMatrixArray );
}


//+===================================+//
//	rotate matrices by a point
//+===================================+//
void Matrix3::RotateMatrixX( float a_fRotation )
{
		m_11 = 1.f;		m_12 = 0.f;						m_13 = 0.f;
		m_21 = 0.f;		m_22 = cos( a_fRotation );		m_23 = -sin( a_fRotation );
		m_31 = 0.f;		m_32 = sin( a_fRotation );		m_33 = cos( a_fRotation );
}

void Matrix3::RotateMatrixY( float a_fRotation )
{
		m_11 = cos( a_fRotation );		m_12 = 0.f;		m_13 = -sin( a_fRotation );
		m_21 = 0.f;						m_22 = 1.f;		m_23 = 0.f;
		m_31 = sin( a_fRotation );		m_32 = 0.f;		m_33 = cos( a_fRotation );
}

void Matrix3::RotateMatrixZ( float a_fRotation )
{
		m_11 = cos( a_fRotation );		m_12 = -sin( a_fRotation );		m_13 = 0.f;
		m_21 = sin( a_fRotation );		m_22 = cos( a_fRotation );		m_23 = 0.f;
		m_31 = 0.f;						m_32 = 0.f;						m_33 = 1.f;
}

//+===================================+//
//	Transform matrix by vector
//+===================================+//
Vec3 Matrix3::TransformPoint( Vec3 a_pVec3 )
{
	Matrix3 temp = Matrix3( *this + a_pVec3 );
	return ( Vec3( temp.m_31, temp.m_32, temp.m_33) );
}