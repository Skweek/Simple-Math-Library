#include "Bitset.h"

BitSet::BitSet( unsigned int a_uiSize )
{
	m_uiTotalBits = a_uiSize;
	m_uiTotalBytes = (a_uiSize + (BitsPerByte - (a_uiSize % BitsPerByte )));
	m_uiTotalBytes /= BitsPerByte;
	m_pcData = new unsigned char[m_uiTotalBytes];
	//Set all bits to be off
	memset(m_pcData, 0, sizeof(unsigned char) * m_uiTotalBytes);
}

BitSet::~BitSet()
{
	delete[] m_pcData;
}

void BitSet::SetAllBits()
{
	memset(m_pcData, 0xFF, sizeof(unsigned char) * m_uiTotalBytes);
}
void BitSet::ClearAllBits()
{
	memset(m_pcData, 0, sizeof(unsigned char) * m_uiTotalBytes);
}

void BitSet::SetBit( unsigned int a_uiBit )
{
	unsigned int uiByte = a_uiBit/8;
	unsigned int uiBitInByte = a_uiBit % 8;
	unsigned char ucMask = 1 << uiBitInByte;
	m_pcData[uiByte] |= ucMask;
}

void BitSet::ClearBit( unsigned int a_uiBit )
{
	unsigned int uiByte = a_uiBit/8;
	unsigned int uiBitInByte = a_uiBit % 8;
	unsigned char ucMask = 1 << uiBitInByte;
	m_pcData[uiByte] &= ~ucMask;
}

bool BitSet::operator[]( unsigned int a_uiBit )
{
	unsigned int uiByte = a_uiBit/8;
	unsigned int uiBitInByte = a_uiBit % 8;
	unsigned char ucMask = 1 << uiBitInByte;
	return ( ( m_pcData[uiByte] & ucMask ) ? true : false );
}

int BitSet::GetSize()
{
	return m_uiTotalBits;
}