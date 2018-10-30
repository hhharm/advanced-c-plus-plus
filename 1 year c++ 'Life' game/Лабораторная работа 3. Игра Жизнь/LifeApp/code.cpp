#include "stdafx.h"
#include "Settings.h"
#include "Form1.h"
#include "BufferForm.h"

using namespace LifeApp;

void Form1::MyRefresh()
{
	this->flowLayoutPanel1->Refresh();
	this->flowLayoutPanel2->Refresh();
	this->button5->Refresh();
	this->PolskExpressionLabel->Refresh();
}

void Form1::SetExpressionError(Servant::state state)
{
	switch (state)
	{
	case Servant::everything_is_fine:
		{
			this->ExpressionStateLabel->Text = "Correct";
			break;
		}
	case Servant::empty_expression:
		{
			this->ExpressionStateLabel->Text = "Error! Empty expression is not allowed.";
			break;
		}
	case Servant::brackets_error:
		{
			this->ExpressionStateLabel->Text = "Error! Check your brackets.";
			break;
		}
	case Servant::wrong_symbol:
		{
			this->ExpressionStateLabel->Text = "Error! Wrong symbol.";
			break;
		}
	case Servant::wrong_last_elem:
		{
			this->ExpressionStateLabel->Text = "Error! Wrong last symbol";
			break;
		}
	case Servant::other_error:
		{
			this->ExpressionStateLabel->Text = "incorrect";
			break;
		}
	default:
		break;
	}
	if (state != Servant::everything_is_fine)
		this->ExpressionStateLabel->BackColor = Color::Red;
	else 
		ExpressionStateLabel->BackColor = Color::White;
}

void BufferForm::MyRefresh()
{
	this->panel1->Refresh();
	
	this->panel6->Refresh();
}


void Form1::ChangeTable()
{
	int num_cells_in_temp = 9;
	(*dataGridView1).Rows->Clear();
	std::list <VarToken*> vars = *(GetModel()->GetVarList());
	//удаляем первые 9 переменных (переменные шаблона)
	for (int i = 0; i < num_cells_in_temp; i++) vars.pop_front();
	std::list <VarToken*>::iterator it;
	String ^name;
	int i;
	for (i = 0, it = vars.begin(); it != vars.end(); it++, i++)
	{
	(*dataGridView1).Rows->Add();
	name = gcnew System::String(((*it)->GetName()).c_str());
	((*dataGridView1)[0, i])->Value = name;
	((*dataGridView1)[1, i])->Value = (*it)->GetValue();
	delete name;
	}



}