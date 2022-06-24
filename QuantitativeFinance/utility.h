#pragma once

#include <exception>

#define ASSERT(condition, message) \
	if (!(condition)) throw std::exception(message);

#define WARNING(message) std::count << "Warning: " << (message) << std::endl;