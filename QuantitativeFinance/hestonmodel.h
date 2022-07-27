#pragma once

#include "virtualhestonmodel.h"

namespace QuantitativeFinance
{
		class HestonModel : public VirtualHestonModel
		{
		public:
				StochasticVolatilityModel()
		};

		class HestonModel : public StochasticVolatilityModel,
				public Observable
		{
		public:
				class CharacteristicFunction : public Observer,
						public Observable
				{
				public:
						void setOmega(ComplexArray1D omega);
						virtual void update() override;
				protected:
						Real tau_;
						ComplexArray1D omega_;

						CharacteristicFunction(ParametricStochasticProcess* process, Real tau);
				};

				virtual void setParam(std::vector<Real> params) override;
				virtual void setParam(std::map<String, Real> params) override;
		};

		inline void ParametricStochasticProcess::setParam(std::vector<Real> params)
		{
				ParametricModel::setParam(params);
				notisfyAll();
		}

		inline void ParametricStochasticProcess::setParam(std::map<String, Real> params)
		{
				ParametricModel::setParam(params);
				notisfyAll();
		}

		inline 	ParametricStochasticProcess::CharacteristicFunction::CharacteristicFunction(
				ParametricStochasticProcess* process,
				Real tau)
				:
				Observer(process),
				tau_(tau)
		{}

		inline void ParametricStochasticProcess::CharacteristicFunction::setOmega(ComplexArray1D omega)
		{
				omega_ = omega;
				update();
		}

		inline void ParametricStochasticProcess::CharacteristicFunction::update()
		{
				notisfyAll();
		}
}