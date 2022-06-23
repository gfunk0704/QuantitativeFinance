#pragma once

#include <complex>
#include <cstdint>
#include <vector>

#include "./include/eigen-3.4.0/Eigen/Eigen"

namespace QuantitativeFinance
{
	using Complex = std::complex<double>;
	using Integer = std::int32_t;
	using Natural = std::uint32_t;
	using Real = double;
	using Size = std::size_t;
	using String = std::string;

	template<typename T>
	using List = std::vector<T>;

	using ComplexArray = Eigen::ArrayXcd;
	using ComplexArray1D = Eigen::ArrayXX<Eigen::dcomplex>;
	using IntegerArray = Eigen::ArrayXX<Integer>;
	using IntegerArray1D = Eigen::ArrayX<Integer>;
	using NaturalArray = Eigen::ArrayXX<Natural>;
	using NaturalArray1D = Eigen::ArrayX<Natural>;
	using RealArray = Eigen::ArrayXX<Real>;
	using RealArray1D = Eigen::ArrayXd;
}