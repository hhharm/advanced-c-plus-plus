#pragma once
#include <stdlib.h>
#include <string>
using namespace std;

enum op
{	
	plus,			//плюс
	minus,			//минус
	mult,			//умножить
	divide,			//разделить
	
	//скобки должны всегда быть больше всех других операций!
	open_bracket,	//открывающаяся скобка
	close_bracket	//закрывающаяся скобка
};

enum token_type 
{	
	number,			//число
	variable,		//переменная
	operation,		//операция
	function		//функция	
};


class IToken 
{
public:
	virtual token_type GetType() = 0;		//возвращает тип
	virtual string GetString()   = 0;		//для отображения
};

class NumToken: public IToken
{
	int value;
public:
	NumToken(int val);
	token_type GetType();
	int GetValue();
	void Init(int* val);
	string GetString();
};

class OpToken: public IToken
{	
	op value;
public:
	OpToken(op val);
	token_type GetType();
	op GetValue();
	void Init(op* val);
	int Op (int a, int b);		//выполняет нужную операцию
	string GetString();
};

class VarToken: public IToken
{
	string name;	//имя переменной
	int value;		//значение
public:
	VarToken(string n, int val = 0);
	~VarToken();
	token_type GetType();

	string GetName();		
	int GetValue();

	void InitName(string n);
	void InitValue(int v);

	string GetString();
};



class HelpWithToken
{
public:
	static int GetPriority(op a);	//возвращает приоритет операции
};

