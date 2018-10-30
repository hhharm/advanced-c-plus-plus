#include "Field.h"

unsigned int* OneBitField::GetP() {return p;}
unsigned int* TwoBitField::GetP() {return p;}
unsigned int* ThreeBitField::GetP() {return p;}

TField::TField(int i, int _x, int _y)
{	if ((_x > 0)&&(_y >0)){
	switch (i)
	{case 1:	{pole = new OneBitField(_x*_y); break;}
	 case 2: {pole = new TwoBitField(_x*_y); break;}
	 case 3:{pole = new ThreeBitField(_x*_y); break;}
	}
		str = _x;
	stb = _y;
	pole->MakeClear();
}
}
TField::~TField(void)
{
	delete pole;
}

TField::TField(const TField &b)
{
	str = b.str;
	stb = b.stb;
	int m = b.pole->GetM();
	this-> pole = new OneBitField(m);
	*pole = b.pole;
}


void TField::SetEl(int _x, int _y, int value)
{
	int i;
	int modx = ((_x%stb)+stb)%stb;
    int mody = ((_y%str)+str)%str;
	i = (modx)*stb+mody;
	pole->SetBit(i,value);
}

unsigned int TField::GetEl(int x, int y){ 
	int modx = ((x%stb)+stb)%stb;
    int mody = ((y%str)+str)%str;
	int i = (modx)*stb+mody; 
	return pole->GetBit(modx*stb+mody);}

void TField::MakeClear(){pole->MakeClear();}


int TField::Colmns(){return this->stb;}
int TField::Row(){return this->str;}

int TField::IsItClear(){return pole->IsItClear();}

void TField::SetSize(int x, int y)
{ 
	pole->SetSize(x*y);
	str = x;
	stb = y;

}


void TField::operator=(TField b)
{
	
	*pole = b.pole;

	str = b.str;
	stb = b.stb;
}

int TField::MaxNumOfStates(){return pole->MaxNumOfStates();}
void CurrentField::operator=(CurrentField a)
	{
		

		(*Field) = (*a.Field);
		(*Res) = (*a.Res);
		(*Temp) = (*a.Temp);
		fillf = a.fillf;
		fillt = a.fillt;
}

CurrentField::CurrentField()
{
	Field = new TField;
	Res = new TField;
	Temp = new TField;
}