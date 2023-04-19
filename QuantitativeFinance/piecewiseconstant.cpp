#include "piecewiseconstant.h"

namespace QuantitativeFinance
{
		Real PiecewiseConstant::getY(Real x) const
		{
				if (x <= points_.front().first)
						return points_.front().second;
				else if (x >= points_.back().first)
						return points_.back().second;
				else
						return interpolate(x, firstGreaterEqual(x));
		}

		Real PiecewiseConstant::integral(Real x) const
		{
				if (x <= points_.front().first)
						return points_.front().second * x;
				else if (x >= points_.back().first)
						return (cumulativeIntegration_.back() + points_.front().second * (x - points_.front().first));
				else
				{
						Size rhsPos = firstGreaterEqual(x);
						return integralPartition(x, rhsPos) + cumulativeIntegration_[rhsPos - 1];
				}
		}

		void PiecewiseConstant::pushBack(Point2D pt)
		{
				NonparametricCurve::pushBack(pt);
				Real  interval = pt.second;
				if (!cumulativeIntegration_.empty())
						interval -= points_[points_.size() - 2].first;
				cumulativeIntegration_.push_back(pt.second * interval);
		}
}