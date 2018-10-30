#pragma once
#include "Field.h"
#include "Fill.h"

using namespace std;

TField* BField::t = NULL;
TTemp* BTemp::t = NULL;
IFill* BFill::op = NULL;

TField* BField::build(int x, int row,int colms)
{
	t = new TField(x,row,colms); return t;	
}


TTemp* BTemp::build(int x, int y)
{
	IFill *f;
	t = new TTemp(1, y, y);
	switch (x)
	{
	case 1: {f = BFill::build(1);break; }
	case 2: {f = BFill::build(2);break;}
	case 4: {f = BFill::build(4);break;}
	case 5: {f = BFill::build(5);break;}

	case 3: {f = BFill::build(3);break;}
	case 0: {f = BFill::build(0);break;}
	default:
		{f = BFill::build(1);break;}
	}
	f->Fill(t); 
	return t;
}


IFill* BFill::build(int x)
{

	switch (x)
	{
	case 0: {op = new EmptyFill;
		return op;}
	case 1: {
		op = new ChessFill;
		return op;}
	case 2: {
		op = new LineFill;
		return op;}
	case 3: { 
		op = new RandomFill;
		return op;}
	case 4:
		{op = new IChessFill;
		return op;}
	case 5: 
		{
			op = new HeartFill;
		return op;
		}
	default:
		break;
	}

}