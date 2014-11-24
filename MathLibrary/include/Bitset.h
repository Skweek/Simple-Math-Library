///////////////////////////////////////
// File:			Bitset.h
// Author:			Nick Smith
// Creation Date:	14th May 2013
// Notes:			Bitarray
///////////////////////////////////////

#ifndef _BITSET_H_
#define	_BITSET_H_

#include "MathUtil.h"

const int BitsPerByte = 8;

class DECLDIR BitSet
{
public:
	//Constructor/Destructor
	BitSet(unsigned int a_uiSize );
	~BitSet();
	void SetAllBits(); //Sets all the bits in the set to 1
	void ClearAllBits(); //Sets all the bits in the set to 0
	void SetBit( unsigned int a_uiBit ); //Turn on the bit at location a_uiBit
	void ClearBit( unsigned int a_uiBit ); //Turn off the bit at location a_uiBit
	bool operator[](unsigned int a_uiBit ); //Gets the value of a bit at location [a_uiBit]
	int	 GetSize(); //Gets size of bitarray
private:
	unsigned char* m_pcData; //The Bit’s we are storing
	unsigned int m_uiTotalBits; //The total number of bits we want to track
	unsigned int m_uiTotalBytes; //The total bytes that the bits occupy
	

};

#endif // _BITSET_H_