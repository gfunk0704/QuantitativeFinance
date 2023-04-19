#include "observer.h"

namespace QuantitativeFinance
{
		

		Observer::~Observer()
		{
				observable_->unregister(this);
		}

		Observable::~Observable()
		{
				if (!observers_.empty())
				{
						for (auto observer : observers_)
								unregister(observer);
				}
		}

		void Observable::notisfyAll()
		{
				if (!observers_.empty())
				{
						for (auto observer : observers_)
								observer->update();
				}
		}
}