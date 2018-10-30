#include "stdafx.h"

#include "CalcAlg.h"


void CalcAlg::NextState(TField* a, TField* res, TTemp* b, 
		QueueList <IToken *> &q, std::list <VarToken *> *var_list, int size_stack)
{
	ArrStack <int> stack (size_stack);
	int i, j, sum;
	 int r = a->Row(), c = a->Colmns();

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			sum = CountCell(i,j,a,b, q, var_list, stack);
			res->SetEl(i,j,sum);
		}
	 for (int i = 0; i < r;i++)
	 for (int j = 0; j<c; j++)
		{
			a->SetEl(i,j,res->GetEl(i,j));
		}

}


int CalcAlg::CountCell(int i, int j, TField* a, TTemp* b, QueueList <IToken *> &q,
					   std::list <VarToken *> *var_list,  ArrStack <int> &stack)
{
	
//переменные счетчиков и индексов
	int _i, i0, _j, j0, k, l;
//полезные переменные
	int row_in_temp,temp, row_in_field,colms_in_field;
	int value;
temp = b->Row()/2;
row_in_field = a->Row();
colms_in_field = a->Colmns();

i0 = i - temp;
j0 = j-temp; 
{
int id_in_list;
std::list <VarToken*> ::iterator it = var_list->begin();
for ( k = 0, _i = i0; k<3; _i++, k++)
	{		
		for ( l = 0,_j = j0; l < 3;l++, _j++)
		{
			//если значения совпадают, устанавливаем в a i-ое значение 1
			if ((a->GetEl(_i,_j))&&(b->GetEl(k,l))) value = 1;
			else value = 0;				
			(*it)->InitValue(value);
			it++;
					
		}
	}
}

	int sum = Servant::Calculate(q,var_list,stack);
	
	//вдруг отрицательные числа 
	sum = (sum%a->MaxNumOfStates() + a->MaxNumOfStates()) 
			%a->MaxNumOfStates(); 

	return sum;
};