#pragma once

#include <complex>
#include <cstdint>
#include <functional>
#include <memory>
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

		using ComplexArray = Eigen::ArrayXcd;
		using ComplexArray1D = Eigen::ArrayXX<Eigen::dcomplex>;
		using IntegerArray = Eigen::ArrayXX<Integer>;
		using IntegerArray1D = Eigen::ArrayX<Integer>;
		using NaturalArray = Eigen::ArrayXX<Natural>;
		using NaturalArray1D = Eigen::ArrayX<Natural>;
		using RealArray = Eigen::ArrayXX<Real>;
		using RealArray1D = Eigen::ArrayXd;

		using ScalarFunction1D = std::function<Real(Real)>;
		using ScalarFunction = std::function<Real(RealArray1D)>;

		template<class T>
		using SharedPtr = std::shared_ptr<T>;
}