#pragma once
#include "Field.h"



class TAlg
{
	//в переменную sum возвращает кол-во клеток, совпадающих с шаблоном по mod n
	static int CountCell(int i, int j, TField* a, TTemp* b);
public:
	static void NextState(TField* a,TField* res, TTemp* b);
};