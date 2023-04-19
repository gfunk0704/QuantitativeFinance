#pragma once

#include "type.h"
#include "utility.h"

namespace QuantitativeFinance
{
		class ParametricModel
		{
		public:
				virtual Real getParam(const String& name) const;
				virtual std::map<String, Real> getParam() const;
				virtual void setParam(std::vector<Real> params);
				virtual void setParam(std::map<String, Real> params);

				Size nParams() const;
				virtual std::vector<String> paramNames() const = 0;
				virtual std::vector<Real> paramLowerBound() const = 0;
				virtual std::vector<Real> paramUpperBound() const = 0;
		protected:
				ParametricModel(Size nParam);
				std::vector<Real> params_;
				Size getIndex(const String& name) const;
				void validility() const;
				virtual std::vector<Real> mapToParameterSpace(std::vector<Real> values) const;
		};

		inline ParametricModel::ParametricModel(Size nParam)
		:
		params_(nParam)
		{
		}

		inline Real ParametricModel::getParam(const String& name) const
		{
				return params_[getIndex(name)];
		}

		inline void ParametricModel::setParam(std::vector<Real> params)
		{
				ASSERT(params.size() == nParams(), "dimensions are mismatched");
				params_ = mapToParameterSpace(params);
		}

		inline void ParametricModel::setParam(std::map<String, Real> params)
		{
				auto names = paramNames();
				for (Size i = 0; i < nParams(); ++i)
						params_[i] = params[names[i]];
		}

		inline Size ParametricModel::getIndex(const String& name) const
		{
				auto names = paramNames();
				auto parNameIter = std::find(names.begin(), names.end(), name);
				return std::distance(names.begin(), parNameIter);
		}

		inline Size ParametricModel::nParams() const
		{
				return paramNames().size();
		}

		inline std::vector<Real> ParametricModel::mapToParameterSpace(std::vector<Real> values) const
		{
				return values;
		}
}