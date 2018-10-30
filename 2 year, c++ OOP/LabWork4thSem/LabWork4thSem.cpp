// LabWork4thSem.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Form1.h"
#include "History.h"
using namespace LabWork4thSem;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Model1 ^m;
	BaseForm ^f1 = gcnew Form1(), ^f2 = gcnew History();

	m = gcnew Model1(f1, f2);
	f1->Init(m);
	f2->Init(m);

	// �������� �������� ���� � ��� ������
	Application::Run(f1);
	

	return 0;
}
