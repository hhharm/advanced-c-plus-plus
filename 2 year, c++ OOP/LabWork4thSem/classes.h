#pragma once
#include "stdafx.h"

#include "Polynom.h"

struct coord
{
	double x, y;
	coord(double _x, double _y): x(_x), y(_y) {}
};

struct MyPoint
{
	Polynom Xpol, Ypol;
	double x, y;
};