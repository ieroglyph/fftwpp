// fftwpp.cpp : Defines the entry point for the console application.
//

#include "fftwpp.h"

#include <iostream>

using namespace std;
using namespace fftw;

int main(int argc, char* argv[])
{
	cout << "!!" << endl;
	try
	{
		Plan p("d:\\coding\\fftw-3.3.3-dll32\\libfftw3-3.dll",1<<18);
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

