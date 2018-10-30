// LifeApp.cpp: главный файл проекта.

#include "stdafx.h"
#include "Observer.h"
#include "Form1.h"
#include "BufferForm.h"
#include "Settings.h"

using namespace LifeApp;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Model1 ^m;
	BaseForm ^f1 = gcnew Form1();
	BaseForm ^set = gcnew Settings();	
	BaseForm ^bf = gcnew BufferForm();

	m = gcnew Model1(f1,set,bf);

	f1->Init(m); bf->Init(m);set->Init(m);


	// Создание главного окна и его запуск
	Application::Run(f1);
	return 0;
}
