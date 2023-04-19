#pragma once

#include "nonparametriccurve.h"

namespace QuantitativeFinance
{
		class PiecewiseLinear : public NonparametricCurve
		{
		public:
				PiecewiseLinear();
				void clear() override;
				void pushBack(Point2D pt) override;
				void popBack() override;
				
		protected:
				Real interpolate(Real x, Size pos) const  override;
				Real integralPartition(Real x, Size pos) const override;
		};

		inline PiecewiseLinear::PiecewiseLinear()
				:
				NonparametricCurve()
		{
		}

		inline Real PiecewiseLinear::interpolate(Real x, Size pos) const
		{
				auto rhsPt = points_[pos];
				auto lhsPt = points_[pos - 1];
				return lhsPt.second + (rhsPt.second - lhsPt.second) * (x - lhsPt.first) / (rhsPt.first - lhsPt.first);
		}

		inline Real PiecewiseLinear::integralPartition(Real x, Size pos) const
		{
				auto lhsPt = points_[pos - 1];
				return 0.5 * (x - lhsPt.first) * (lhsPt.second + interpolate(x, pos));
		}
}