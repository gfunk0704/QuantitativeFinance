#pragma once

#include "constant.h"
#include "deterministicriskfreerate.h"
#include "observer.h"
#include "parametricmodel.h"

namespace QuantitativeFinance
{
		class DiffusionModel : public ParametricModel,
				public Observable
		{
		public:
				class CharacteristicFunction : public Observer
				{
				public:
						CharacteristicFunction(DiffusionModel* model, Real tau);
						Real tau() const;
						virtual ComplexArray1D evaluate(RealArray1D omega, Real x) const;
						virtual ComplexArray1D varphiLevy(RealArray1D omega) const = 0;
				protected:
						Real tau_;
				};

				virtual void  setInitialvalue(Real value);
				Real initialValue() const;
				const SharedPtr<DeterministicRiskFreeRate>& r() const;
				const SharedPtr<DeterministicRiskFreeRate>& q() const;
				virtual SharedPtr<CharacteristicFunction> characteristicFunction(Real tau) = 0;
		protected:
				SharedPtr<DeterministicRiskFreeRate> r_;
				SharedPtr<DeterministicRiskFreeRate> q_;
				Real initialValue_;
				bool isCalibrated_;

				DiffusionModel(Size nParam,
						Real initialValue,
						SharedPtr<DeterministicRiskFreeRate> r,
						SharedPtr<DeterministicRiskFreeRate> q);
		};

		inline DiffusionModel::DiffusionModel(Size nParam,
				Real initialValue,
				SharedPtr<DeterministicRiskFreeRate> r,
				SharedPtr<DeterministicRiskFreeRate> q)
				:
				ParametricModel(nParam),
				r_(r),
				q_(q)
		{
				setInitialvalue(initialValue);
		}

		inline void DiffusionModel::setInitialvalue(Real value)
		{
				initialValue_ = value;
		}

		inline Real DiffusionModel::initialValue() const
		{
				return initialValue_;
		}

		inline const SharedPtr<DeterministicRiskFreeRate>& DiffusionModel::r() const
		{
				return r_;
		}

		inline const SharedPtr<DeterministicRiskFreeRate>& DiffusionModel::q() const
		{
				return q_;
		}

		inline DiffusionModel::CharacteristicFunction::CharacteristicFunction(DiffusionModel* model,
				Real tau)
				:
				Observer(model),
				tau_(tau)
		{
				ASSERT(tau > 0, "tau must be a positive real number");
		}

		inline Real DiffusionModel::CharacteristicFunction::tau() const
		{
				return tau_;
		}

		inline ComplexArray1D DiffusionModel::CharacteristicFunction::evaluate(RealArray1D omega,
				Real x) const
		{
				return varphiLevy(omega) * Eigen::exp(I * omega * x);
		}
}