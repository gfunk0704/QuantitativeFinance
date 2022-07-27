#pragma once

#include "nonparametriccurve.h"

namespace QuantitativeFinance
{
		class PiecewiseConstant : public NonparametricCurve
		{
		public:
				PiecewiseConstant();
		protected:
				Real interpolate(Real x, Size rhsPos) const override;
				Real integralPartition(Real x, Size rhsPos) const override;
		};

		inline PiecewiseConstant::PiecewiseConstant()
				:
				NonparametricCurve()
		{}

		inline Real PiecewiseConstant::interpolate(Real x, Size rhsPos) const
		{
				return points_[rhsPos].second;
		}

		inline Real PiecewiseConstant::integralPartition(Real x, Size rhsPos) const
		{
				Size lhsPos = rhsPos - 1;
				return cumulativeIntegration_[lhsPos] + points_[rhsPos].second * (x - points_[lhsPos].first);
		}
}