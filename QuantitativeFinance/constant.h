#pragma once

#include <limits>

#include "type.h"

namespace QuantitativeFinance
{
	const Real EPSILON = std::numeric_limits<Real>::epsilon();
	const Real SQRT_EPSILON = std::sqrt(EPSILON);
	const Complex I = { 0.0, 1.0 };
	const Real PI = 3.14159265358979323846;
}