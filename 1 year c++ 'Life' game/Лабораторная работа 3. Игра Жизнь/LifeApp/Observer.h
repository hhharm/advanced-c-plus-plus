#pragma once
#include "Stack.h"
#include <string>

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
	virtual void SetExpressionError(Servant::state state){}
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
	string *expres;
	string *polsk_expres;
	QueueList <IToken *> *q_exp, *q_polsk;	//очередь: начальное выражение, переделанное в польское
	std::list <VarToken *> *vars;	//список имен переменных и их значений
	int size_of_stack;	
	Servant::state expression_state;
public:
	Model1(BaseForm ^Field, BaseForm ^Settintgs, BaseForm ^Buf);
	~Model1();
	
	void UnDoCommand();
	void ReDoCommand();

	void NextStateCommand();

	void ConvertCommand();

	
	void BeginAnew();

	MyStack* GetStack();
	CurrentField* GetCurrentField();
	TField* GetField();
	TTemp* GetTemp();
	TField *GetRes();
	int* GetArr(){return p;};
	MyStack* GetDoStack();
	string GetPolskExpression();
	std::list <VarToken*> * GetVarList();

	void ShowBuf();
	void ShowSettings();

	void AllRefresh();

	void SetFieldSize(int x, int y);
	void SetFieldFilling(int i);
	void SetNumberOfColorInField(int x);
	void SetTempSize(int x);
	void SetTempFilling(int i);
	void SetExpression(string s);
};