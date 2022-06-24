#pragma once

#include <iostream>

#include "period.h"

namespace QuantitativeFinance
{
	// origin date = 1970-01-01
	using SerialType = std::int_fast32_t;
	using Year = std::int_fast32_t;
	using Day = std::uint_fast32_t;
	enum class Month : std::uint_fast32_t {
		JAN = 1,
		FEB = 2,
		MAR = 3,
		APR = 4,
		MAY = 5,
		JUN = 6,
		JUL = 7,
		AUG = 8,
		SEP = 9,
		OCT = 10,
		NOV = 11,
		DEC = 12
	};

	enum class Weekday : std::uint_fast8_t
	{
		SUN = 0,
		MON = 1,
		TUE = 2,
		WEN = 3,
		THU = 4,
		FRI = 5,
		SAT = 6
	};

	class Date
	{
		using Unsigned = std::uint_fast32_t;

		SerialType serialNumber_;
		bool updateYmd_ = false;
		Year year_;
		Month month_;
		Day day_;

		Date shiftMonths(SerialType n);
		Date shiftYears(SerialType n);
		void update();

	public:
		explicit Date(SerialType serialNumber);
		Date(Year yyyy, Month mm, Day dd);
		Date(Year yyyy, std::uint_fast32_t mm, Day dd);

		Year year();
		Month month();
		Day day();
		SerialType serialNumber() const;
		Weekday weekday() const;
		SerialType operator-(const Date& rhs) const;
		Date operator+(const Period& period);
		Date operator-(const Period& period);
		bool operator>(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		Date& operator++();
		Date& operator--();
		Date operator++(int);
		Date operator--(int);

		static const Date origin();
		static bool isLeap(const Date&);
		static bool isLeap(Year yyyy);
		static Day endOfMonth(const Date&);
		static Day endOfMonth(Year yyyy, Month mm);
	};

	inline Date::Date(SerialType serialNumber):
		serialNumber_(serialNumber),
		updateYmd_(false)
	{}

	inline Date::Date(Year yyyy, std::uint_fast32_t mm, Day dd):
		Date(yyyy, static_cast<Month>(mm), dd)
	{}

	inline Date Date::shiftYears(SerialType n)
	{
		Year yyyy = year() + n;
		Month mm = month();
		Day dd = std::min(day(), endOfMonth(yyyy, mm));
		return Date(yyyy, mm, dd);
	}

	inline Year Date::year()
	{
		if (!updateYmd_)
			update();
		return year_;
	}

	inline Month Date::month()
	{
		if (!updateYmd_)
			update();
		return month_;
	}

	inline Day Date::day()
	{
		if (!updateYmd_)
			update();
		return day_;
	}

	inline SerialType Date::serialNumber() const
	{
		return serialNumber_;
	}

	inline Weekday Date::weekday() const
	{
		return Weekday((serialNumber_ >= -4 )? ((serialNumber_ + 4) % 7) : ((serialNumber_ + 5) % 7 + 6));
	}

	inline SerialType Date::operator-(const Date& rhs) const
	{
		return serialNumber_ - rhs.serialNumber();
	}

	inline Date Date::operator-(const Period& period) 
	{
		return *this + Period(-period.number(), period.unit());
	}

	inline bool Date::operator>(const Date& rhs) const
	{
		return serialNumber_ > rhs.serialNumber_;
	}

	inline bool Date::operator>=(const Date& rhs) const
	{
		return serialNumber_ >= rhs.serialNumber_;
	}

	inline bool Date::operator==(const Date& rhs) const
	{
		return serialNumber_ == rhs.serialNumber_;
	}

	inline bool Date::operator!=(const Date& rhs) const
	{
		return serialNumber_ != rhs.serialNumber_;
	}

	inline bool Date::operator<=(const Date& rhs) const
	{
		return serialNumber_ <= rhs.serialNumber_;
	}

	inline bool Date::operator<(const Date& rhs) const
	{
		return serialNumber_ < rhs.serialNumber_;
	}

	inline Date& Date::operator++()
	{
		++serialNumber_;
		updateYmd_ = false;
		return *this;
	}

	inline Date& Date::operator--()
	{
		--serialNumber_;
		updateYmd_ = false;
		return *this;
	}

	inline Date Date::operator++(int)
	{
		Date old(*this);
		++*this;
		update();
		return old;
	}

	inline Date Date::operator--(int)
	{
		Date old(*this);
		--*this;
		return old;
	}

	inline const Date Date::origin()
	{
		static const Date o(1970, Month::JAN, 1);
		return o;
	}

	inline bool Date::isLeap(const Date& d)
	{
		return isLeap(d.year_);
	}

	inline bool Date::isLeap(Year yyyy)
	{
		return  (yyyy % 4 == 0) && ((yyyy % 100 != 0) || (yyyy % 400 == 0));
	}

	inline Day Date::endOfMonth(const Date& d)
	{
		return endOfMonth(d.year_, d.month_);
	}

	inline std::ostream& operator<<(std::ostream& out, Date& d)
	{
		std::uint_fast32_t mm = static_cast<std::uint_fast32_t>(d.month());
		out << d.year() << "-" << mm << "-" << d.day();
		return out;
	}
}