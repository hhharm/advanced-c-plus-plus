#pragma once

#include "stdafx.h"
#include <math.h>
class Monom 
{
	static unsigned int max_deg;
	unsigned deg;
	double coef;
	unsigned CalcHash(int x_deg, int y_deg, int t_deg);
public:
	Monom (double _coef = 0.0, int x_deg = 0, int y_deg = 0, int t_deg = 0);
	unsigned int GetHash();
	double Calc (double x, double y, double t);
	double GetCoef();
	void SetCoef(double coef);
	int GetXdeg();
	int GetYdeg();
	int GetTdeg();
};