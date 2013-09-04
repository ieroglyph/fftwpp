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
		Complex* signal = new Complex[1000];

		for (int i = 0; i < 1000; i++)
			signal[i] = 2*i;

		Complex* specter = new Complex[1<<18];

		Complex* specter1 = new Complex[1000];


		// test forward with oversampling
		{
			Plan p( wstring(L"c:\\fftw.dll"), 1<<18, Flags::Direction::Forward );

			p.execute( 1000, (void*)signal, (void*)specter );

			cout << specter[499] << endl;
		}

		cout << signal[499] << endl;
		// test forward
		{
			Plan p( wstring(L"c:\\fftw.dll"), 1000, Flags::Direction::Forward );

			p.execute( 1000, (void*)signal, (void*)specter1 );

			cout << specter1[499] << endl;
		}

		// test backward
		{
			Plan p( wstring(L"c:\\fftw.dll"), 1000, Flags::Direction::Backward );

			p.execute( 1000, (void*)specter1, (void*)signal );

			cout << signal[499] << endl;
		}


	}
	catch ( std::exception& e )
	{
		cerr << e.what() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}