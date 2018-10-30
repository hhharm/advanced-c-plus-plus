
#include "stdafx.h"
#include "Monom.h"
unsigned Monom::max_deg = 10;

unsigned Monom::CalcHash(int x_deg, int y_deg, int t_deg)
{

	if (abs(x_deg) < max_deg && abs(y_deg) < max_deg && abs(y_deg) < max_deg)
		{
			if (x_deg < 0) { x_deg = max_deg + abs(x_deg) - 1; }
			if (y_deg < 0) { y_deg = max_deg + abs(y_deg) - 1; }
			if (t_deg < 0) { t_deg = max_deg + abs(t_deg) - 1; }
			return (x_deg * 4 * max_deg * max_deg + y_deg * 2 * max_deg + t_deg);
		}
		else throw ("wrong degrees");

}
Monom::Monom (double _coef, int x_deg, int y_deg,  int t_deg)
{
		coef = _coef;
		deg = CalcHash(x_deg, y_deg, t_deg);
}
unsigned int Monom::GetHash(){ return deg; }

int Monom::GetXdeg()
{int x =  deg / (max_deg * 4 * max_deg);
if (x >= max_deg) { x -= (max_deg + 1); }
return x;
}

int Monom::GetYdeg()
{
	int y_deg = (deg % (max_deg * 4 * max_deg)) / (2 * max_deg);
	if (y_deg >= max_deg) { y_deg -= (max_deg + 1); }
	return y_deg;
}

int Monom::GetTdeg()
{
	int t_deg = deg % (max_deg * 2);
	if (t_deg >= max_deg) {  t_deg -= (max_deg + 1); }
	return t_deg;
}


double Monom::Calc (double x, double y, double t)
{
	if (t <= 0) throw ("Time can't be less than 0");
	double res;
	int x_deg = GetXdeg(), y_deg = GetYdeg(), t_deg = GetTdeg();
	res = coef*pow(x, (double)x_deg)*pow(y, (double)y_deg)*pow((double)t, (double) t_deg);
	return res;
}
double Monom::GetCoef(){return coef;}
void Monom::SetCoef(double coef) {this->coef = coef;}
