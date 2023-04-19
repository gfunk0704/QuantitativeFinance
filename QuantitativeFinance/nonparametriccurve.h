#pragma once

#include "curve.h"
#include "utility.h"

namespace QuantitativeFinance
{

		using Point2D = std::pair<Real, Real>;

		class NonparametricCurve : public Curve
		{
		protected:
				std::vector<Point2D> points_;
				std::vector<Real> cumulativeIntegration_;
				Size firstGreaterEqual(Real x) const;
				virtual Real interpolate(Real x, Size pos) const = 0;
				virtual Real integralPartition(Real x, Size pos) const = 0;
		public:
				NonparametricCurve();
				virtual void clear();
				std::vector<Point2D> points() const;
				virtual void pushBack(Point2D pt);
				virtual void popBack();
		};

		inline NonparametricCurve::NonparametricCurve()
				:
				points_(0),
				cumulativeIntegration_(0)
		{}

		inline void NonparametricCurve::clear()
		{
				points_.clear();
				cumulativeIntegration_.clear();
		}

		inline 	std::vector<Point2D> NonparametricCurve::points() const
		{
				return points_;
		}

		inline void NonparametricCurve::pushBack(Point2D pt)
		{
				if (points_.size())
						ASSERT(points_.back().first < pt.first, "x's must be increasing");
				points_.push_back(pt);
		}

		inline void NonparametricCurve::popBack()
		{
				points_.pop_back();
				cumulativeIntegration_.pop_back();
		}
}