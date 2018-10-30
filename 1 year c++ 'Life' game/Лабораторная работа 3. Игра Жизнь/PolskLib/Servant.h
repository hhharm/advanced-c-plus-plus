#pragma once
#include "List.h"
#include "Queue.h"
#include "Stacks.h"
#include "token.h"
#include <list>

//������ ��� ��������������� ��������
class Servant
{
public:
	//������ ���������������� ������ �� �������
	static void MakeExpressNormal(string &buf);
public:
	
	enum state
{
	everything_is_fine,
	empty_expression,
	brackets_error,
	wrong_symbol,
	wrong_last_elem,
	other_error
};

	//��������� �� ������� ������, �������� ������� (��� ��� � ����������)
	static void Parsing (string buf, QueueList <IToken*> &res);
	
	//���������� ������ ���������� ����������, ������� ���� � ������
	//��������� ���� a1...a9
	static void GetVarList(QueueList <IToken*> &q, std::list <VarToken*> *vars);		


	//�������� expression!
	//���������� ������ ������� �����
	//������ ���������  � �������� ������ � ���� �������
	static int MakePolsk(QueueList <IToken*> &expression, QueueList <IToken*> &res);

	//������������ ��������� ( ����� ��������� �� �������, ����������� ���� �������� ���������� � �������)
	static int Calculate(QueueList <IToken *> q, std::list <VarToken *> *var_list,  ArrStack <int> &stack);


	//��������� �������� ������� � ������
	static string GetExpress(QueueList <IToken *> q);

	//��������� ������������
	static state Check(string exp);

};