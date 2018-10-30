#include "stdafx.h"
#include "Observer.h"
#include "CalcAlg.h"


void CCopy (TField *a, TField &b)
{
	delete a;
	int i;
	switch (b.MaxNumOfStates())
	{case 2: {i  = 1; break;}
	case 4: {i = 2; break;}
	case 8: {i = 3; break;}
	}
	a = new TField(i,b.Row(),b.Colmns());

	int j;
	for (i = 0; i < b.Row(); i++)
		for (j = 0; j < b.Colmns(); j++)
			a->SetEl(i,j,b.GetEl(i,j));
};

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
	p = new int[7];
	curfield = new CurrentField;
	//Default
	p[0] = 12;			//количество строк	
	p[1] = 12;			//количество столбцов
	p[2] = 1;			//режим (2\4\8 цвета) , значения 1 и 2, 3
	curfield->fillf = 3;//способ заполнения поля
	
	curfield->fillt = 3;//способ заполнения шаблона
	p[5] = 3;			// размер шаблона
	p[6] = 1;			//текущий алгоритм
			
	curfield->Field = BField::build(p[2],p[0],p[1]);
	curfield->Res = BField::build(p[2],p[0],p[1]);
	curfield->Temp = BTemp::build(curfield->fillt,p[5]);
	fill = BFill::build(curfield->fillf);
	fill->Fill(curfield->Field);

	expres = new string;
	q_exp = new QueueList <IToken *>;
	q_polsk = new QueueList <IToken *> ;
	vars = new std::list <VarToken *> ;	//список имен переменных и их значений
	polsk_expres = new string;
}
Model1::~Model1(){
	delete s, UndoStack;
	delete curfield;
	delete fill;
	delete expres, polsk_expres;
	delete q_exp, q_polsk, vars;
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

TField* Model1::GetField()
{
	return curfield->Field;
}

CurrentField* Model1::GetCurrentField(){return curfield;}
TField* Model1::GetRes()
{
	return curfield->Res;
}

TTemp* Model1::GetTemp()
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


void Model1::SetExpression(string s)
{
	*expres = s;
}



void Model1::NextStateCommand()
{
	if (p[6] == 0)
	TAlg::NextState(curfield->Field, curfield->Res, curfield->Temp);
	else 
	if (expression_state == Servant::everything_is_fine)
	{	
	if (p[6] == 1) 
		CalcAlg::NextState(curfield->Field, curfield->Res, curfield->Temp, (*q_polsk),vars,size_of_stack);

	
	}
	else MessageBox::Show("Check you expression");
	
	
	s->Push(curfield);
	UndoStack->Clean();
	AllRefresh();
	
}


void Model1::ConvertCommand()
{
	expression_state = Servant::Check(*expres);
	Field->SetExpressionError(expression_state);
	if (expression_state == Servant::everything_is_fine)
	{
	Servant::Parsing(*expres, *q_exp);
	size_of_stack = Servant::MakePolsk(*q_exp, *q_polsk);
	Servant::GetVarList(*q_polsk,vars);
	*polsk_expres = Servant::GetExpress(*q_polsk);
	Field->MyRefresh();
	}
}

string  Model1::GetPolskExpression(){return *polsk_expres;}

std::list <VarToken*>* Model1::GetVarList() {return vars;}