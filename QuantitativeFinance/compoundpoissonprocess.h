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
	public:

	};

	inline CompoundPoissonProcess::CompoundPoissonProcess(std::shared_ptr<ContinuousDistribution> jumpSizeDist):
		Process({{"lambda", 0.0}}),
		jumpSizeDist_(jumpSizeDist)
	{}
}