
#include "Fill.h"


void ChessFill::Fill(TField *f)
{
	int i, j, x, y;
	f->MakeClear();
	x = f->Row();
	y = f->Colmns();
	for (i = 0; i<x; i+=2)
		for (j = 0; j<y; j+=2) f->SetEl(i,j,1);
	for (i = 1; i<x; i+=2)
		for (j = 1; j < y; j+=2) f->SetEl(i,j,1);

}

void IChessFill::Fill(TField *f)
{
	int i, j, x, y;
	f->MakeClear();
	x = f->Row();
	y = f->Colmns();
	for (i = 1; i<x; i+=2)
		for (j = 0; j<y; j+=2) f->SetEl(i,j,1);
	for (i = 0; i<x; i+=2)
		for (j = 1; j < y; j+=2) f->SetEl(i,j,1);

}

void LineFill::Fill(TField *f)
{
	f->MakeClear();
	int i, j, x, y;
	x = f->Row();
	y = f->Colmns();
	for (i = 0; i<x; i+=2)
		for (j = 0; j<y; j++) f->SetEl(i,j,1);

}
void RandomFill::Fill(TField *f)
{
	int i,x,y, number;	
	f->MakeClear();
	x = f->Row();
	y = f->Colmns();
	number = rand()%(x*y)+1;
	for (i = 0; i<number; i++) f->SetEl(rand()%x,rand()%y,1);
	
}

void EmptyFill::Fill(TField* f)
{
	f->MakeClear();
}


void HeartFill::Fill(TField* f)
{
	int i;
	f->SetEl(1,2,1);
	f->SetEl(1,3,1);
	f->SetEl(1,8,1);
	f->SetEl(1,7,1);
	for (i = 1; i< 5;i++)f->SetEl(2,i,1);
	for (i = 6; i< 10;i++)f->SetEl(2,i,1);
	for (i = 0; i< 11;i++)f->SetEl(3,i,1);
	for (i = 0; i< 11;i++)f->SetEl(4,i,1);
	for (i = 1; i< 10;i++)f->SetEl(5,i,1);
	for (i = 2; i< 9;i++)f->SetEl(6,i,1);
	for (i = 3; i< 8;i++)f->SetEl(7,i,1);
	for (i = 4; i< 7;i++)f->SetEl(8,i,1);
	f->SetEl(9,5,1);
}






//*/