#pragma once

#include <exception>
#include <iostream>

#define ASSERT(condition, message) \
	if (!(condition)) throw std::exception(message);

#define WARNING(message) std::cout << "Warning: " << (message) << std::endl;

namespace QuantitativeFinance
{
	template <typename T> 
	inline Integer sign(T value) {
		return (T(0) < value) - (value < T(0));
	}
}