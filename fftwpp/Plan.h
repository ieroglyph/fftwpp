#pragma once

#include "filelog.h"

#include "Executor.h"

namespace fftw
{

	char planstr[] = "Plan";

	class Plan: fl::Loggale<planstr>
	{
		fftw_complex* in;
		fftw_complex* out;
		fftw_plan p;
		int n;
		Executor e;

		Plan(Plan& p2)
		{
			// just to make copy constructor unaccessible
		}
	public:
		Plan(void)
		{
			// ???
		}
		Plan( std::wstring filepath, int N, char* wisdompath = 0 ):
			e(filepath)
		{
			this->n = N;
			this->in = 
				(fftw_complex*)
				this->e.fftw_malloc( sizeof(fftw_complex) * N );
			this->out = 
				(fftw_complex*)
				this->e.fftw_malloc( sizeof(fftw_complex) * N );
			memset( this->in, 0, sizeof(fftw_complex) * N );
			memset( this->out, 0, sizeof(fftw_complex) * N );
			this->p = this->e.fftw_plan_dft_1d
				( N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
		}
		~Plan(void)
		{
			if (this->in)
				this->e.fftw_free(this->in);
			if (this->out)
				this->e.fftw_free(this->out);
			this->e.fftw_destroy_plan(this->p);
		}
		int N()
		{
			return this->n;
		}
		void execute(int insize, void *in, void *out)
		{
			if (this->n < insize)
				throw std::exception("Size too big!");
			memset(this->in,0,sizeof(fftw_complex)*this->n);
			memcpy(this->in,in,sizeof(fftw_complex)*insize);
			this->e.fftw_execute(this->p);
			memcpy(out,this->out,sizeof(fftw_complex)*this->n);
		}
	};
}