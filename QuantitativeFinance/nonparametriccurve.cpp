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

		
}