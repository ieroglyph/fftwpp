#pragma once

// hopefully, this will become a multi-platform tool some time
#include <windows.h>

#include <exception>

namespace fftw
{
	class FftwLibrary
	{
		HMODULE module;

	public:
		FftwLibrary(void)
		{
		}

		FftwLibrary(char* lib_path)
		{
			// the path is supposed to be correct and checked before
			this->module = LoadLibrary( LPCTSTR( lib_path ) );
			if ( this->module == 0 )
				throw std::exception("Cannot load library!");
		}

		~FftwLibrary(void)
		{
			if ( this->module != 0 )
				FreeLibrary( this->module );
		}

		void* GetProcAddress(char* proc)
		{
			if ( this->module == 0 )
				throw std::exception("Library is not loaded!");
			void* ProcAddr = ::GetProcAddress( this->module, proc );
			if ( ProcAddr == 0 )
				throw std::exception("Cannot load address!");
			return ProcAddr;
		}
	};

}
