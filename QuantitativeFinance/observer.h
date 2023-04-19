#pragma once

#include <unordered_set>

#include "type.h"

namespace QuantitativeFinance
{
		class Observable;

		class Observer
		{
		protected:
				friend class Observable;
				Observable* observable_;
				Observer(Observable* observable);
				~Observer();
				virtual void update() = 0;
		};

		inline Observer::Observer(Observable* observable) :
				observable_(observable)
		{
		}

		class Observable
		{
		protected:
				friend class Observer;
				std::unordered_set<Observer*> observers_;

				Observable() = default;
				~Observable();
				void rigister(Observer* observer);
				void unregister(Observer* observer);
				void notisfyAll();
		};

		inline void Observable::rigister(Observer* observer)
		{
				observers_.insert(observer);
		}

		inline void Observable::unregister(Observer* observer)
		{
				observers_.erase(observer);
		}
}