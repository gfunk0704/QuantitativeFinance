#pragma once

#include "diffusionmodel.h"

namespace QuantitativeFinance
{
		class Heston : public DiffusionModel
		{
		public:
				class CharacteristicFunction : public DiffusionModel::CharacteristicFunction
				{
						friend class Heston;
				protected:
						CharacteristicFunction(Heston* model, Real tau);
				};

				Heston(Real initialValue,
						SharedPtr<DeterministicRiskFreeRate> r,
						SharedPtr<DeterministicRiskFreeRate> q);
				virtual std::vector<String> paramNames() const override;
				virtual std::vector<Real> paramLowerBound() const override;
				virtual std::vector<Real> paramUpperBound() const override;
		private:
				Real& v0_;
				Real& kappa_;
				Real& theta_;
				Real& sigma_;
				Real& rho_;
		};

		inline Heston::Heston(Real initialValue,
				SharedPtr<DeterministicRiskFreeRate> r,
				SharedPtr<DeterministicRiskFreeRate> q)
				:
				DiffusionModel(5, initialValue, r, q)
		{
		}

		inline std::vector<String> Heston::paramNames() const
		{
				return { "v0", "kappa", "theta", "sigma", "rho" };
		}

		inline std::vector<Real> Heston::paramLowerBound() const
		{
				return { SQRT_EPSILON, SQRT_EPSILON , SQRT_EPSILON , SQRT_EPSILON - 1.0 };
		}

		inline std::vector<Real> Heston::paramUpperBound() const
		{
				return { 1.0, 10.0, 1.0, 1.0, 1.0 };
		}
}