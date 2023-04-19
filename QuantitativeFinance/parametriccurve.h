#pragma once

#include "parametricmodel.h"
#include "curve.h"

namespace QuantitativeFinance
{
		class ParametricCurve : public Curve,
				public ParametricModel
		{
		};
}