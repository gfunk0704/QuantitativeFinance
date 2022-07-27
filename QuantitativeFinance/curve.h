#pragma once

#include "type.h"

namespace QuantitativeFinance
{
		class Curve
		{
		public:
				virtual Real getY(Real x) const = 0;
				virtual Real integral(Real x)  const = 0;
		};
}