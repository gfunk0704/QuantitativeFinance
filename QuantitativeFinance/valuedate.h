#pragma once

#include "date.h"
#include "daycount.h"
#include "setonce.h"
#include "singleton.h"
#include "utility.h"

namespace QuantitativeFinance
{
		class ValueDate : public Singleton<SetOnce<Date>>
		{
				friend class  Singleton<SetOnce<Date>>;
				ValueDate() = default;
		};
}