#include "Alg.h"

void TAlg::NextState (TField *a, TField *res, TTemp* t)
{	
	int i, j, sum;
	 int r = a->Row(), c = a->Colmns();

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			sum = CountCell(i,j,a,t);
			res->SetEl(i,j,sum);
		}
	 for (int i = 0; i < r;i++)
	 for (int j = 0; j<c; j++)
		{
			a->SetEl(i,j,res->GetEl(i,j));
		}
}

int TAlg::CountCell(int i, int j,TField* a, TTemp* t)
{
//переменные счетчиков и индексов
	int _i, i0, _j, j0, k, l, sum = 0;
//полезные переменные
	int row_in_temp,temp, row_in_field,colms_in_field;
	row_in_temp = t->Row();
temp = t->Row()/2;
row_in_field = a->Row();
colms_in_field = a->Colmns();

i0 = i - temp;
j0 = j-temp; 


//printf("\n\n %d i %d j", i,j);
for ( k = 0, _i = i0; k<row_in_temp; _i++, k++)
	{		
		for ( l = 0,_j = j0; l < row_in_temp;l++, _j++)
		{
		//	printf("\n%d ?= %d, i = %d, j = %d, k = %d, l = %d",a->GetBit(_i,_j),t->GetBit(k,l), _i,_j,k,l);
			if ((a->GetEl(_i,_j))&&(t->GetEl(k,l))) sum+=a->GetEl(_i,_j);
			
		}
	}
sum %= a->MaxNumOfStates(); 
return sum;
}


