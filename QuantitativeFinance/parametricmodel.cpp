#include "parametricmodel.h"

namespace QuantitativeFinance
{
		std::map<String, Real> ParametricModel::getParam() const
		{
				std::map<String, Real> params;
				auto names = paramNames();
				for (Size i = 0; i < nParams(); ++i)
						params[names[i]] = params_[i];
				return params;
		}

		void ParametricModel::validility() const
		{
				for (Size i = 0; i < nParams(); ++i)
				{
						auto name = paramNames()[i];
						auto par = params_[i];
						ASSERT((par < paramLowerBound()[i]) || par > paramUpperBound()[i],
										"parameter " + name + " is out of boundary");
				}
		}
}