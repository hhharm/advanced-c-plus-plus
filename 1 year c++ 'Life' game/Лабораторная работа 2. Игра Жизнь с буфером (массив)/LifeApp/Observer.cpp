#include "stdafx.h"
#include "Observer.h"


Model1^ BaseForm::GetModel()
{
	return m;
}
void BaseForm::Init(Model1 ^_m)
{
	m = _m;
}
MyStack*  Model1::GetDoStack()
{
	return UndoStack;
}

Model1::Model1(BaseForm ^Field, BaseForm ^Settintgs, BaseForm ^Buf)
{
	this->Buf = Buf;
	this->Settings = Settintgs;
	this->Field = Field;
	s = new MyStack(SIZE_OF_STACK);
	UndoStack = new MyStack(SIZE_OF_STACK);
	p = new int[6];
	curfield = new CurrentField;
	//Default
	p[0] = 12;			//количество строк	
	p[1] = 12;			//количество столбцов
	p[2] = 1;			//режим (2\4\8 цвета) , значения 1 и 2, 3
	curfield->fillf = 5;//способ заполнения поля
	
	curfield->fillt = 2;//способ заполнения шаблона
	p[5] = 3;			// размер шаблона
			
	curfield->Field = BField::build(p[2],p[0],p[1]);
	curfield->Res = BField::build(p[2],p[0],p[1]);
	curfield->Temp = BTemp::build(curfield->fillt,p[5]);
	fill = BFill::build(curfield->fillf);
	fill->Fill(curfield->Field);
}
Model1::~Model1(){
	delete s;
	delete curfield;
	delete fill; 
	delete UndoStack;
}


void Model1::ShowBuf(){
	this->Buf->Show();
}



void Model1::ShowSettings()
{
	this->Settings->Show();
}

void Model1::AllRefresh()
{
	this->Field->MyRefresh();
	this->Buf->MyRefresh();
}

MyStack* Model1::GetStack()
{
	return s;
}

IField* Model1::GetField()
{
	return curfield->Field;
}

CurrentField* Model1::GetCurrentField(){return curfield;}
IField* Model1::GetRes()
{
	return curfield->Res;
}

ITemp* Model1::GetTemp()
{
	return curfield->Temp;
}

void Model1::SetFieldSize(int x, int y){	p[0] = x; p[1] = y;}
void Model1::SetFieldFilling(int i)	   {	curfield->fillf = i;}
void Model1::SetNumberOfColorInField(int x) {p[2] = x;}
void Model1::SetTempSize(int x){p[5] = x;}
void Model1::SetTempFilling(int i){ curfield->fillt = i;}


void Model1::UnDoCommand()
{
	
	UndoStack->Push(&s->Pop());
	*curfield = s->ReadEl(s->GetEnd());
}

void Model1::ReDoCommand()
{
	s->Push(&UndoStack->Pop());
	*curfield = s->ReadEl(s->GetEnd());
}


void Model1::BeginAnew()
{
	delete fill;
	delete curfield->Field;
	delete curfield->Res;
	delete curfield->Temp;
	curfield->Field = BField::build(p[2],p[0],p[1]);
	curfield->Res = BField::build(p[2],p[0],p[1]);
	curfield->Temp = BTemp::build(curfield->fillt,p[5]);
	fill = BFill::build(curfield->fillf);
	fill->Fill(curfield->Field);
	GetStack()->Push(curfield);
	GetDoStack()->Clean();
	AllRefresh();	
}