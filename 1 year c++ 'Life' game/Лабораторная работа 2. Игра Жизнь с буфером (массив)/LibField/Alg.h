#pragma once
#include "Field.h"



class TAlg
{
	//� ���������� sum ���������� ���-�� ������, ����������� � �������� �� mod n
	static int CountCell(int i, int j, TField* a, TTemp* b);
public:
	static void NextState(TField* a,TField* res, TTemp* b);
};