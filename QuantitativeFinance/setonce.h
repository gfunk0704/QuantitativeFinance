#pragma once

#include "utility.h"

namespace QuantitativeFinance
{
		template<class T>
		class SetOnce
		{
		public:
				void set(T value);
				T get() const;
				SetOnce<T>& operator=(T value);
		private:
				T value_;
				bool onceFlag_ = false;
		};

		template<class T>
		void SetOnce<T>::set(T value)
		{
				if (!onceFlag_)
				{
						value_ = value;
						onceFlag_ = true;
				}
				else
				{
						throw std::runtime_error("value is already set up");
				}
		}

		template<class T>
		T SetOnce<T>::get() const
		{
				ASSERT(onceFlag_, "value is not set up yet");
				return value_;
		}

		template<class T>
		SetOnce<T>& SetOnce<T>::operator=(T value)
		{
				set(value);
				return *this;
		}
}