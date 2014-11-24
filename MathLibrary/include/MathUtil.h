#ifndef _MATHUTIL_H_
#define _MATHUTIL_H_

#include <cmath>
#include <iostream>

#ifndef DECLDIR
#ifdef _DLL_BUILD_
#define DECLDIR __declspec( dllexport )
#elif _STATIC_BUILD_
#define DECLDIR
#else
#define DECLDIR __declspec( dllimport )
#endif //DECLDIR
#endif //DECLDIR

#pragma warning (disable : 4201)

const double PI = 3.14159265358979323846;

#endif //_MATHUTIL_H_