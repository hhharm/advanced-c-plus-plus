#pragma once
#include "Field.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

class IFill
{	
public:
	virtual void Fill(TField *f) = 0;
};

class ChessFill:public IFill
{
public:
	void Fill(TField *f);
};

class IChessFill:public IFill	//i for invert
{
public:
	void Fill(TField *f);
};


class EmptyFill:public IFill
{
public:
	void Fill(TField *f);
};

class LineFill:public IFill
{
public:
	void Fill(TField *f);
};
//перед использованием в .cpp прописать srand((unsigned)(time(NULL)));
class RandomFill:public IFill
{
public:
	void Fill(TField *f);
};
class HeartFill:public IFill
{
public:
	void Fill(TField *f);
};

//*
class BFill
{
	static IFill *op;
	public:
	
	//пустой  0, шахматное 1, линиями 2, случайное 3, инверс. шахматы 4, 
	static IFill* build(int x);
};
//*/
