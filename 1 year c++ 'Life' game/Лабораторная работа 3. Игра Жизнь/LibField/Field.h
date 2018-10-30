#pragma once
#include <stdlib.h>
const int OUR_SIZE = sizeof(int)*8;
const int OUR_SIZE_TWO = sizeof(int)*4;
const int OUR_SIZE_THREE = ((sizeof(int))*8)/3;


class IBitField
{
protected:
	int n; //кол-во элементов
	int m; //кол-во байтов
	unsigned int *p;
	virtual unsigned int GetMask(int i, int value) =0;
public:
	virtual int MaxNumOfStates() =0;
	virtual unsigned int* GetP() = 0;
	virtual int GetM() = 0;
	//операции с отдельными битами
	virtual void SetBit(int i, int value) =0;
	virtual unsigned int GetBit(int i) =0;
	virtual void SetSize(int i) =0;
	virtual void MakeClear() =0;
	//возвращает размер
	virtual int Size() =0;
	//возвращает 0 - нечистое, возвращает 1 - чистое
	virtual int IsItClear() =0;
	
	virtual void operator =(IBitField *b) =0;
};
class OneBitField: public IBitField{
protected:
	int n; //кол-во элементов
	int m; //кол-во байтов
	unsigned int *p;
	unsigned int GetMask(int i, int value);
public:
	OneBitField(int _n = 5);
	OneBitField(const OneBitField &a);
	~OneBitField(void); 
	unsigned int* GetP();
	int GetM() {return m;}
	int MaxNumOfStates();
	//операции с отдельными битами
	void SetBit(int i, int value);
	unsigned int GetBit(int i);
	void SetSize(int i);
	void MakeClear();
	//возвращает размер
	int Size();
	//возвращает 0 - нечистое, возвращает 1 - чистое
	int IsItClear();
	void operator =(IBitField *b);

};
class TwoBitField: public IBitField{protected:
	int n; //кол-во элементов
	int m; //кол-во байтов
	unsigned int *p;
	unsigned int GetMask(int i, int value);
public:
	TwoBitField(int _n=5);
	TwoBitField(const TwoBitField &a);
	~TwoBitField(void); 
	unsigned int* GetP();
	int GetM() {return m;}
	int MaxNumOfStates();
	//операции с отдельными битами
	void SetBit(int i, int value);
	unsigned int GetBit(int i);
	void SetSize(int i);
	void MakeClear();
	//возвращает размер
	int Size();
	//возвращает 0 - нечистое, возвращает 1 - чистое
	int IsItClear();
	void operator =(IBitField *b);
};
class ThreeBitField: public IBitField{
protected:
	int n; //кол-во элементов
	int m; //кол-во байтов
	unsigned int *p;
	unsigned int GetMask(int i, int value);
public:
	 unsigned int* GetP();
	 int GetM() {return m;}
	ThreeBitField(int _n=5);
	ThreeBitField(const ThreeBitField &a);
	~ThreeBitField(void); 
	int MaxNumOfStates();
	//операции с отдельными битами
	void SetBit(int i, int value);
	unsigned int GetBit(int i);
	void SetSize(int i);
	void MakeClear();
	//возвращает размер
	int Size();
	//возвращает 0 - нечистое, возвращает 1 - чистое
	int IsItClear();
	void operator =(IBitField *b);
};

class TField
{
	IBitField *pole;	
	int str,stb;	
public:
	TField(int i = 1,	int x = 5, int y = 5); //выбрать размеры поля и модель
	TField(const TField &a);
	~TField();
	
	void SetSize(int x, int y);

	void SetEl(int _x, int _y, int value);
	unsigned int GetEl(int x, int y);

	int MaxNumOfStates();
	int Row();
	int Colmns();

	void MakeClear();
	int IsItClear();
	
	void operator=(TField b);
};

typedef  TField TTemp;

class BField{
	static TField* t;
public:
	static TField* build(int x, int row = 5, int colms = 5);
};

class BTemp{
	static TTemp* t;
public:
	//x = 1 chessBoard, 2 Random, 3 invers chess, 4 empty; y = 0 3x3, y!=0 5x5
	static TTemp* build(int x, int y);
};
struct CurrentField
{
	TField *Field;
	TField *Res;
	TField *Temp;

	CurrentField();
	int fillf;
	int fillt;
	void operator=(CurrentField a);

};