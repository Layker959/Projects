#pragma once
#include <cmath>

class Rectangle
{
public:
	Rectangle(double x1, double y1, double x2, double y2) :
		x1(x1), y1(y1), x2(x2), y2(y2) {}

	double get_width() const
	{
		return abs(x2 - x1);
	}
	double get_height() const
	{
		return abs(y2 - y1);
	}
	double get_area() const
	{
		return get_width() * get_height();
	}
	double get_perimeter() const
	{
		return 2 * (get_width() + get_height());
	}
private:
	double x1, y1;
	double x2, y2;
};
