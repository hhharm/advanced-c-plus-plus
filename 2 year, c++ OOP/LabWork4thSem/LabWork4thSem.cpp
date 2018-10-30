// LabWork4thSem.cpp: главный файл проекта.

#include "stdafx.h"
#include "Form1.h"
#include "History.h"
using namespace LabWork4thSem;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Model1 ^m;
	BaseForm ^f1 = gcnew Form1(), ^f2 = gcnew History();

	m = gcnew Model1(f1, f2);
	f1->Init(m);
	f2->Init(m);

	// Создание главного окна и его запуск
	Application::Run(f1);
	

	return 0;
}
