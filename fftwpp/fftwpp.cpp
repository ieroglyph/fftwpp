// fftwpp.cpp : Defines the entry point for the console application.
//

#include "fftwpp.h"

#include <iostream>
#include <string>
#include <complex>


using namespace std;
using namespace fftw;

typedef std::complex<double> Complex;

int main( int argc, char* argv[] )
{
	cout << "!!\n" << endl;

	try
	{
		Plan p( wstring(L"c:\\fftw.dll"), 1<<18 );

		Complex* signal = new Complex[1000];

		for (int i = 0; i < 1000; i++)
			signal[i] = 2*i;


		Complex* specter = new Complex[1<<18];

		p.execute( 1000, (void*)signal, (void*)specter );

		p.execute( 1000, (void*)signal, (void*)specter );

		p.execute( 1000, (void*)signal, (void*)specter );

		cout << specter[156];

	}
	catch ( std::exception& e )
	{
		cerr << e.what() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}