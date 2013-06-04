// fftwpp.cpp : Defines the entry point for the console application.
//

#include "fftwpp.h"

#include <iostream>
#include <string>

using namespace std;
using namespace fftw;

int main( int argc, char* argv[] )
{
	cout << "!!\n" << endl;

	try
	{
		Plan p = Plan( wstring(L"c:\\fftw.dll"), 1<<18 );
	}
	catch ( std::exception& e )
	{
		cout << e.what() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}