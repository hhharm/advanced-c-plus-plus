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
}

void BufferForm::MyRefresh()
{
	this->panel1->Refresh();
	
	this->panel6->Refresh();
}

