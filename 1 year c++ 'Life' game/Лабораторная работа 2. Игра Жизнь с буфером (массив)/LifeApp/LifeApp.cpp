// LifeApp.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Observer.h"
#include "Form1.h"
#include "BufferForm.h"
#include "Settings.h"

using namespace LifeApp;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Model1 ^m;
	BaseForm ^f1 = gcnew Form1();
	BaseForm ^set = gcnew Settings();	
	BaseForm ^bf = gcnew BufferForm();

	m = gcnew Model1(f1,set,bf);

	f1->Init(m); bf->Init(m);set->Init(m);


	// �������� �������� ���� � ��� ������
	Application::Run(f1);
	return 0;
}
