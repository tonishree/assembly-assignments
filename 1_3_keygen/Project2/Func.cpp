#include "Func.h"

bool RightUsername(string& a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < 'A')
			return false;
		if( 'Z' < a[i] && a[i] < 'a' )
			return false;
		if (a[i] > 'z')
			return false;
		if (a[i] > 'X')
		{
			a[i] = toupper(a[i]);
		}
	}
	return true;
}

unsigned int SumASCII(string a)
{
	unsigned int S = 0;
	for (int i = 0; i < a.length(); i++)
	{
		S += a[i];
	}
	return S;
}

unsigned int RightPassword(unsigned int s)
{
	s = s ^ 0x5678 ^ 0x1234;
	return s;
}

