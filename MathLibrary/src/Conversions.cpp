#include "Conversions.h"
#include "Bitset.h"

BitSet* Conversions::HexToBin( unsigned int a_uiHex )
{
	BitSet* result = new BitSet( 32 );
	// TO_DO
	return result;
}

BitSet* Conversions::DecToBin( int a_iDec )
{
	BitSet* result = new BitSet( 32 );
	unsigned char* temp = new unsigned char[32];

	int CurrentBit = 0;
	while ( a_iDec >= 1 )
	{
		temp[CurrentBit] = ( a_iDec % 2 );
		a_iDec /= 2;

		++CurrentBit;
	}

	for( int i = 0, j = 31; j >= 0 && i <= 32; --j, ++i )
	{
		result->ClearAllBits();
		if( temp[j] == 1 )
		{
			result->SetBit( j );
		}
	}

	delete[] temp;
	return result;
}

unsigned int Conversions::DecToHex( int a_iDec )
{
	// TO_DO
	return 0;
}

unsigned int Conversions::BinToHex( BitSet a_pBin )
{
	unsigned int result = 0;

	for( int i = a_pBin.GetSize() - 1, j = 0; i >= 0; --i,++j )
	{

		if( a_pBin[i] )
		{
			result += (int)pow( 2.0, j );
		}
	}

	return result;
}

int Conversions::BinToDec( BitSet a_pBin )
{
	int result = 0;
	
	for( int i = a_pBin.GetSize() - 1, j = 0; i >= 0; --i,++j )
	{

		if( a_pBin[i] )
		{
			result += (int)pow( 2.0, j );
		}
	}

	return result;
}

int Conversions::HexToDec( unsigned int a_uiHex )
{
	// TO_DO
	return 0;
}