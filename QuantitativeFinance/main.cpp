#include "date.h"
#include "valuedate.h"

using namespace QuantitativeFinance;

int main()
{
		ValueDate::getInstance() = Date(2022, Month::MAY, 14);
		auto d = ValueDate::getInstance().get();
		std::cout << d << std::endl;
		return 0;
}