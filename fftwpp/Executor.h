#pragma once

#ifdef _WIN32
#include "FftwLibraryWin.h"
#endif

#include "fftw3.h"

namespace fftw
{

	typedef fftw_plan (*fftw_plan_dft_1d_func)(int,fftw_complex*,fftw_complex*,int,int); 
	typedef void (*fftw_execute_func)(fftw_plan);
	typedef void* (*fftw_malloc_func)(int);
	typedef void (*fftw_free_func)(void*);
	typedef void (*fftw_destroy_plan_func)(fftw_plan);

	// loads library, manages plans and wisdom, etc.
	class Executor
	{
		FftwLibrary lib;

	public:
		Executor(void)
		{}
		Executor(char* filename)
		{
			// file assumed to be existing
			lib = FftwLibrary(filename);
			this->fftw_execute = (fftw_execute_func)
				lib.GetProcAddress
				("fftw_execute");
			this->fftw_plan_dft_1d = (fftw_plan_dft_1d_func)
				lib.GetProcAddress
				("fftw_plan_dft_1d");
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


		fftw_plan_dft_1d_func fftw_plan_dft_1d;
		fftw_execute_func fftw_execute;
		fftw_malloc_func fftw_malloc;
		fftw_free_func fftw_free;
		fftw_destroy_plan_func fftw_destroy_plan;
	};


}