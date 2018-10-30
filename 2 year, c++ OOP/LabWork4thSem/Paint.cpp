#include "stdafx.h"
#include "History.h"
#include "BaseForm.h"
using namespace LabWork4thSem;
void History::showline(Graphics^ g, int width,  int height, int row, int colm, int set_h)
	{	
	}

void BufferForm::pokajiramkuLast(Graphics^ g, int width, int height, int y)
			{
				Color PenColor;
				PenColor = System::Drawing::Color::DarkViolet;
					// �������� � ������������� Pen
				Pen^ MyPen;
				SolidBrush ^Brush;
					// �������� � ������������� �������
				MyPen = gcnew Pen(PenColor,5);
				Brush = gcnew SolidBrush (PenColor);
				g->DrawRectangle(MyPen,0,y,width,height);
				g->FillRectangle(Brush,0,y,width,height);
					 
			}		
void BufferForm::pokajiramkuFirst(Graphics^ g, int width, int height, int y)
			{
				Color PenColor;
				PenColor = System::Drawing::Color::LightCoral;
					// �������� � ������������� Pen
				Pen^ MyPen;
					// �������� � ������������� �������
				MyPen = gcnew Pen(PenColor,5);
				g->DrawRectangle(MyPen,0,y,width,height);
					 
			}		
void BufferForm::ShowDoStack(Graphics ^g)
{//���� ���� �� ���� 
				 try {
				 //������ ���������� ���������
				int end   = GetModel()->GetDoStack()->GetEnd(),
					i,
				//����� ��� ��������� ������ ������ �� max ���-�� ���������
					cell_height = panel6->Height/(SIZE_OF_STACK+10),
					cell_draw_height = panel6->Height/(SIZE_OF_STACK+1),
					row,colm,cell_width;
				//� ������ ���� �� �����
				pokajiramkuFirst(g,panel6->Width, cell_height+4 ,0);
						for (i = 0; i <= end; i++)
					{
					//���-�� ����� � ���� � �����
					row = GetModel()->GetDoStack()->ReadEl(i).Field->Row();
					//���-�� ���� � ���� � �����
					colm = GetModel()->GetDoStack()->ReadEl(i).Field->Colmns();
					//������ ����� ������
					cell_width  = panel6->Width/(row*colm);	
					//�������. g ������ ������ �� �������� ����,
					//� ���������� ���������� �����
					if (i == end) pokajiramkuLast(g,panel6->Width, cell_height+4 ,i*cell_draw_height-2);
					showline(g,cell_width,cell_height,
						GetModel()->GetDoStack()->ReadEl(i).Field,row,colm,i*cell_draw_height);
					}
				 }
				 catch (...)
				 {}
				
				 }


void BufferForm::FirstPosToLastPos(Graphics ^g)
{//���� ���� �� ���� 
				 
				 //������ �������  ���������� ��������
				int end   = GetModel()->GetStack()->GetEnd(),
					start = GetModel()->GetStack()->GetStart(),
					size   = GetModel()->GetStack()->GetSize(),
					i,
				//����� ��� ��������� ������ ������ �� ������ �����
					cell_height = panel1->Height/(SIZE_OF_STACK+10),
					cell_draw_height = panel1->Height/(SIZE_OF_STACK+1),
					row,colm,cell_width;
				//� ������ ���� �� �����
						for (i = 0; i < size; i++)
					{
					//���-�� ����� � ���� � �����
					row = GetModel()->GetStack()->ReadEl(i).Field->Row();
					//���-�� ���� � ���� � �����
					colm = GetModel()->GetStack()->ReadEl(i).Field->Colmns();
					//������ ����� ������
					cell_width  = panel1->Width/(row*colm);	
					//�������. g ������ ������ �� �������� ����,
					//� ���������� ���������� �����
					if (i == end) pokajiramkuLast(g,panel1->Width, cell_height+4 ,i*cell_draw_height-2);
					if (i == start) pokajiramkuFirst(g,panel1->Width, cell_height+4 ,i*cell_draw_height-2);

					showline(g,cell_width,cell_height,
						GetModel()->GetStack()->ReadEl(i).Field,row,colm,i*cell_draw_height);
					}
				
				 }