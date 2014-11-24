///////////////////////////////////////
// File:			Conversions.h
// Author:			Nick Smith
// Creation Date:	15th May 2013
// Notes:			Data type conversions
///////////////////////////////////////

#ifndef _CONVERSIONS_H_
#define	_CONVERSIONS_H_

class BitSet;

#include "MathUtil.h"

class DECLDIR Conversions
{
public:
	BitSet* HexToBin( unsigned int a_uiHex );
	BitSet* DecToBin( int a_iDec );

	unsigned int DecToHex( int a_iDec );
	unsigned int BinToHex( BitSet a_pBin );

	int BinToDec( BitSet a_pBin );
	int HexToDec( unsigned int a_uiHex );



};

#endif // _CONVERSIONS_H_