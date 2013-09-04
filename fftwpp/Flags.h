#pragma once

#include "fftw3.h"

namespace fftw
{
	namespace Flags
	{
		enum class Direction
		{
			Forward = FFTW_FORWARD,
			Backward = FFTW_BACKWARD
		};

		enum class Planning
		{
			Estimate = FFTW_ESTIMATE,
			Measure = FFTW_MEASURE,
			Patient = FFTW_PATIENT,
			Exhaustive = FFTW_EXHAUSTIVE,
			WisdomOnly = FFTW_WISDOM_ONLY
		};

		enum class Algorithm
		{
			DestroyInput = FFTW_DESTROY_INPUT,
			PreserveInput = FFTW_PRESERVE_INPUT,
			Unaligned = FFTW_UNALIGNED
		};
	}

}