#pragma once

#ifdef _WIN32
#include "FftwLibraryWin.h"
#endif

#include "filelog.h"

#include "fftw3.h"

namespace fftw
{

	// loads library, manages plans and wisdom, etc.

	char executorstr[] = "Executor";

	class Executor: public fl::Loggale<executorstr>
	{
		FftwLibrary lib;

	public:
		Executor(void): Loggale(true)
		{
		}

		Executor( std::wstring filename ):
			lib(filename.c_str())
		{
			// file assumed to be existing

			this->fftw_plan_dft_1d = (fftw_plan_dft_1d_func)
				lib.GetProcAddress
				("fftw_plan_dft_1d");
			this->fftw_execute = (fftw_execute_func)
				lib.GetProcAddress
				("fftw_execute");
			this->fftw_malloc = (fftw_malloc_func)
				lib.GetProcAddress
				("fftw_malloc");
			this->fftw_free = (fftw_free_func)
				lib.GetProcAddress
				("fftw_free");
			this->fftw_destroy_plan = (fftw_destroy_plan_func)
				lib.GetProcAddress
				("fftw_destroy_plan");
		}

		~Executor(void)
		{}

#pragma region FFTW functions

		typedef fftw_plan (__cdecl *fftw_plan_dft_1d_func)
			(int,fftw_complex*,fftw_complex*,int,int); 
		fftw_plan_dft_1d_func fftw_plan_dft_1d;

		typedef void (__cdecl *fftw_execute_func)
			(fftw_plan);
		fftw_execute_func fftw_execute;

		typedef void* (__cdecl *fftw_malloc_func)
			(int);
		fftw_malloc_func fftw_malloc;

		typedef void (__cdecl *fftw_free_func)
			(void*);
		fftw_free_func fftw_free;

		typedef void (__cdecl *fftw_destroy_plan_func)
			(fftw_plan);
		fftw_destroy_plan_func fftw_destroy_plan;

#pragma endregion

	};


}