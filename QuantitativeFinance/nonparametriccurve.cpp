#include "nonparametriccurve.h"

namespace QuantitativeFinance
{
		// use binary search
		Size NonparametricCurve::firstGreaterEqual(Real x) const
		{
				Size length = points_.size();
				Size median;
				Size first = 0;
				while (length > 0)
				{
						median = length >> 1;
						if (x > points_[median].first)
						{
								first = median + 1;
								length -= (median + 1);
						}
						else
								length = median;
				}
				return first;
		}

		Real NonparametricCurve::integral(Real x) const
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
}