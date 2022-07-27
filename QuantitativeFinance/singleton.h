#pragma once

namespace QuantitativeFinance
{
		template<class T>
		class Singleton
		{
		public:
				Singleton(const Singleton&) = delete;
				Singleton(Singleton&&) = delete;
				Singleton& operator=(const Singleton&) = delete;
				Singleton& operator=(Singleton&&) = delete;

				static T& getInstance();
		protected:
				Singleton() = default;
		};

		template<class T>
		inline T& Singleton<T>::getInstance()
		{
				static T instance_;
				return instance_;
		}
}