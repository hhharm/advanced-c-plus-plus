#pragma once
#include "Stack.h"

const int SIZE_OF_STACK = 5;

using namespace System;

using namespace System::Windows::Forms;

ref class Model1;

public ref class BaseForm: public System::Windows::Forms::Form
{
	Model1 ^m;
public:
	Model1^ GetModel();
	void Init(Model1 ^_m);
	virtual void MyRefresh()
	{}
};

public ref class Model1
{
	BaseForm ^Field;
	BaseForm ^Settings;
	BaseForm ^Buf;

	CurrentField *curfield;
	IFill *fill;
	MyStack *s;
	MyStack *UndoStack;
	int *p;//массив для управления состоянием. строки, столбцы, кол-во цветов, заполнение, заполнениеш, размер ш
public:
	Model1(BaseForm ^Field, BaseForm ^Settintgs, BaseForm ^Buf);
	~Model1();
	
	void UnDoCommand();
	void ReDoCommand();
	
	void BeginAnew();

	MyStack* GetStack();
	CurrentField* GetCurrentField();
	IField* GetField();
	ITemp* GetTemp();
	IField *GetRes();
	int* GetArr(){return p;};
	MyStack* GetDoStack();

	void ShowBuf();
	void ShowSettings();

	void AllRefresh();

	void SetFieldSize(int x, int y);
	void SetFieldFilling(int i);
	void SetNumberOfColorInField(int x);
	void SetTempSize(int x);
	void SetTempFilling(int i);
};