#pragma once
#include "Polynom.h"
#include <string>
#include "Stack.h"		//там хранится стек на кольц. буфере
#define STEP 0.1		//на сколько время увеличивается за 1 шаг
using namespace System;
using namespace System::Windows::Forms;
ref class Model1;


public ref class BaseForm: public System::Windows::Forms::Form
{
	Model1 ^m;
public:
	Model1^ GetModel() {
	return m;
}
	void Init(Model1 ^_m){
	m = _m;
}
	virtual void MyRefresh()
	{}
};

struct MyData 
{
	
	double t;	//время - общее для всех
	MyPoint *arr;	//массив точек
public:
	MyData() 
	{	
		t = 0.0;
	}
	Polynom* GetXPolynom (unsigned i) 
	{
		return &(arr[i].Xpol);
	} 
	Polynom* GetYPolynom (unsigned i) 
	{
		return &(arr[i].Ypol);
	}
	void RestartTime() {t = 0.0;}
	void SetPoint(unsigned i, double _x, double _y) {arr[i].x = _x; arr[i].y = _y;}
	double GetX(unsigned i) {return arr[i].x;}
	double GetY(unsigned i) {return arr[i].y;}
	void IncTime() { t += STEP;}
	void DecTime() { t -= STEP;}
	double GetTime() {return t;}

};

public ref class Model1
{
	BaseForm ^Field;
	BaseForm ^History;
	MyData *data;	//тут располагаются данные
	MyStack **history_stack;	//стеки историй	
	int history_stack_size;
public:

	Model1(BaseForm ^Form1, BaseForm ^HistoryForm): Field(Form1), History(HistoryForm){
		data = new MyData;
		history_stack_size = 20;
		history_stack = new MyStack(history_stack_size);
	}		//сюда надо все формы, используемые
	~Model1()
	{
		delete data;
		delete history_stack;
	}
	
	//действия с формами
	/* none*/
	
	//команды
	void UnDoCommand(unsigned i)
	{
		coord t = history_stack[i]->Pop();
		data->DecTime();
		data->SetPoint(t.x, t.y, i);
	}
	void NextStateCommand(unsigned i)
	{
		history_stack[i]->Push(new coord(data->GetX(i), data->GetY(i)));
		data->IncTime();
		double x = data->GetXPolynom(i)->Calc(data->GetX(i), data->GetY(i), data->GetTime()),
			y = data->GetYPolynom(i)->Calc(data->GetX(i), data->GetY(i), data->GetTime());
		data->SetPoint(i, x,y);	

	}
	void AllRefresh(){	this->Field->MyRefresh();}

	//выбор нужной точки координатам
	unsigned GetPointID(double x, double y)
	{


	}

	//сеты-геты
	MyData* GetData() {return data;}
	int GetStackSize() {return history_stack_size;}
	MyStack* GetStack(unsigned i) {return history_stack[i];}
};


