#pragma once
#include "stdafx.h"
#include "Observer.h"


class CalcAlg
{
public:
	//����������� ���� ������
	static int CountCell(int i, int j, TField* a, TTemp* b, QueueList <IToken *> &q,
					   std::list <VarToken *> *var_list,  ArrStack <int> &stack);
public:
	static void NextState(TField* a, TField* res, TTemp* b, 
		QueueList <IToken *> &q, std::list <VarToken *> *var_list, int size_stack);

	//��� ����� ����� ����������. ����� �� � ���� ���-������ �������?

};