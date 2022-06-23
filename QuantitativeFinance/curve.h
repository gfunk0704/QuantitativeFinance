#pragma once

#include "type.h"

namespace QuantitativeFinance
{
	class Curve
	{
	public:
		virtual Real interpolate(Real x) = 0;
		virtual Real integral(Real x) = 0;
	};
}