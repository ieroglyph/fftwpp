#pragma once

#ifdef _WIN32
#include "FftwLibraryWin.h"
#endif

#include "fftw3.h"

namespace fftw
{

	// loads library, manages plans and wisdom, etc.

	class Executor
	{
		FftwLibrary lib;

		Executor(Executor& p2)
		{
			// just to make copy constructor unaccessible
		}
	public:
		Executor(void)
		{
			// ???
		}

		Executor( std::wstring filename ):
			lib(filename.c_str())
		{
			// file assumed to be existing

#define F(f) 	this->f = (f##_func)lib.GetProcAddress(#f);

			F( fftw_plan_dft_1d );
			F( fftw_execute );
			F( fftw_malloc );
			F( fftw_free );
			F( fftw_destroy_plan );
		}

		~Executor(void)
		{}

#pragma region FFTW functions

#define F(f) f##_func f;

		typedef fftw_plan (__cdecl *fftw_plan_dft_1d_func)
			(int,fftw_complex*,fftw_complex*,int,int); 
		F( fftw_plan_dft_1d );

		typedef void (__cdecl *fftw_execute_func)
			(fftw_plan);
		F( fftw_execute );

		typedef void* (__cdecl *fftw_malloc_func)
			(int);
		F( fftw_malloc );

		typedef void (__cdecl *fftw_free_func)
			(void*);
		F( fftw_free );

		typedef void (__cdecl *fftw_destroy_plan_func)
			(fftw_plan);
		F( fftw_destroy_plan );

#pragma endregion

	};


}