#pragma once

#include "curve.h"

namespace QuantitativeFinance
{

	struct Point2D
	{
	public:
		Real x;
		Real y;
		Point2D(Real x, Real y):
			x(x),
			y(y)
		{}
	};

	class NonparametricCurve : public Curve
	{
	protected:
		List<Point2D> points_;
		List<Real> cumulativeIntegration_;
		Size firstGreaterEqual(Real x);
	public:
		void pushBack(Point2D pt);
		void popBack();
	};

	inline void NonparametricCurve::pushBack(Point2D pt)
	{
		if (points_.size())
			assert(points_.back().x < pt.x);
		points_.push_back(pt);
	}

	inline void NonparametricCurve::popBack()
	{
		points_.pop_back();
	}
}