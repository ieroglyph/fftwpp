﻿#pragma once

// hopefully, this will become a multi-platform tool some time
#include <windows.h>

#include "filelog.h"

#include <exception>
#include <iostream>
#include <string>

namespace fftw
{
	char fftwlibrarystr[] = "FftwLibrary";

	class FftwLibrary: public fl::Loggale<fftwlibrarystr>
	{

		HMODULE module;

	public:

		FftwLibrary(void): Loggale(true)
		{
		};

		FftwLibrary( const wchar_t* lib_path )
		{
			// the path is supposed to be correct and checked before
			this->module = ::LoadLibrary( (lib_path) );
			if ( this->module == 0 )
			{
				std::wstring s;
				s += L"Cannot load library!\n";
				s += lib_path;
				std::wcerr << s;
				throw std::exception();
			}
		};

		~FftwLibrary(void)
		{
			if ( this->module != 0 )
				FreeLibrary( this->module );
			this->module = 0;
		};

		void* GetProcAddress( char* proc )
		{
			llo("GetProcAddress");
			if ( this->module == 0 )
				throw std::exception("Library is not loaded!");
			void* ProcAddr = ::GetProcAddress( this->module, proc );
			if ( ProcAddr == 0 )
			{
				std::string s;
				s += "Cannot get address!\n";
				s += proc;
				throw std::exception( s.c_str() );
			}
			return ProcAddr;
		};
	};
}