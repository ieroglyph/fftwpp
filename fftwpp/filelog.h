#pragma once

#include <fstream>
#include <string>

using namespace std;

namespace fl
{

	ofstream log = ofstream("c:\\log.txt",ios::binary);

	template<char const *cn>
	class Loggale
	{
	public:

		bool constructed_with_default;
		static int global_i;
		int local_i;

		Loggale( bool b = false )
		{
			global_i ++;
			local_i = global_i;
			constructed_with_default = b;
			log << cn;
			log << "[" << local_i << "] ";
			if (constructed_with_default)
				log << "(d)";
			log << " constructed";
			log << endl;
		}
		~Loggale()
		{
			log << cn;
			log << "[" << local_i << "] ";
			log << " destructed";
			log << endl;
		}
		void llo( string l )
		{
			log << cn;
			log << "[" << local_i << "] ";
			log << " " << l;
			log << endl;
		}
	};

	template<char const *cn> int Loggale<cn>::global_i = 0;
};

