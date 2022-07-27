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
		virtual void update(Observable* observable) = 0;
	};

	inline Observer::Observer(Observable* observable):
		observable_(observable)
	{}

	inline Observer::~Observer() 
	{ 
		observable_->unregister(this);
		delete observable_;
	}


	class Observable
	{
	protected:
		friend class Observer;
		std::unordered_set<Observer*> observers_;
		~Observable();
		void rigister(Observer* observer);
		void unregister(Observer* observer);
		void notisfyAll();
	};

	inline Observable::~Observable()
	{
		if (!observers_.empty())
		{
			for (auto observer : observers_)
				unregister(observer);
		}
	}

	inline void Observable::rigister(Observer* observer)
	{
		observers_.insert(observer);
	}

	inline void Observable::unregister(Observer* observer)
	{
		observers_.erase(observer);
	}

	inline void Observable::notisfyAll()
	{
		if (!observers_.empty())
		{
			for (auto observer : observers_)
				observer->update(this); 
		}
	}
}