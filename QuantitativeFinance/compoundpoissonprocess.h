#pragma once

#include "distribution.h"
#include "process.h"

namespace QuantitativeFinance
{
	class CompoundPoissonProcess : public Process
	{
	protected:
		std::shared_ptr<ContinuousDistribution> jumpSizeDist_;
		CompoundPoissonProcess(std::shared_ptr<ContinuousDistribution> jumpSizeDist);

		Real mgf(Real phi, Real lambda) const;
	public:
		std::shared_ptr<ContinuousDistribution> jumpSizeDist();
	};

	inline CompoundPoissonProcess::CompoundPoissonProcess(std::shared_ptr<ContinuousDistribution> jumpSizeDist):
		Process({{"lambda", 0.0}}),
		jumpSizeDist_(jumpSizeDist)
	{}

	inline Real CompoundPoissonProcess::mgf(Real phi, Real lambda) const
	{
		return lambda * (jumpSizeDist_->mgf(phi) - 1.0);
	}

	inline std::shared_ptr<ContinuousDistribution> CompoundPoissonProcess::jumpSizeDist()
	{
		return jumpSizeDist_;
	}
}