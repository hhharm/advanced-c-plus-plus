#pragma once
#include <stdlib.h>
#include <string>
using namespace std;

enum op
{	
	plus,			//����
	minus,			//�����
	mult,			//��������
	divide,			//���������
	
	//������ ������ ������ ���� ������ ���� ������ ��������!
	open_bracket,	//������������� ������
	close_bracket	//������������� ������
};

enum token_type 
{	
	number,			//�����
	variable,		//����������
	operation,		//��������
	function		//�������	
};


class IToken 
{
public:
	virtual token_type GetType() = 0;		//���������� ���
	virtual string GetString()   = 0;		//��� �����������
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
	int Op (int a, int b);		//��������� ������ ��������
	string GetString();
};

class VarToken: public IToken
{
	string name;	//��� ����������
	int value;		//��������
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
	static int GetPriority(op a);	//���������� ��������� ��������
};

