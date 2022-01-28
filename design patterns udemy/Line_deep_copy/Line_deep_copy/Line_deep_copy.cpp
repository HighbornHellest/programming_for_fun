// Line_deep_copy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Point
{
	int x{ 0 }, y{ 0 };

	Point() {}

	Point(const int x, const int y) : x{ x }, y{ y }
	{

	}
	~Point()
	{

	}
};

struct Line
{
	Point *start, *end;

	Line(Point* const start, Point* const end)
		: start(start), end(end)
	{
		std::cout << "init line" << std::endl;
	}

	~Line()
	{
		delete start;
		delete end;
		std::cout << "rip in piss line" << std::endl;
	}

	Line deep_copy() 
	{
		Point *start =  new Point(this->start->x, this->start->y);
		Point *end = new Point(this->end->x, this->end->y);
		return Line(start, end);
	}
};

int main()
{
	Line a ( new Point{ 3,4 }, new Point{ 5,6 });
	Line b = a.deep_copy();
	b.start->x = 10;

	std::cout << a.start->x;

}

