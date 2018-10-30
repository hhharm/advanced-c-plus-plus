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
					// создание и инициализация Pen
				Pen^ MyPen;
				SolidBrush ^Brush;
					// Создание и инициализация заливки
				MyPen = gcnew Pen(PenColor,5);
				Brush = gcnew SolidBrush (PenColor);
				g->DrawRectangle(MyPen,0,y,width,height);
				g->FillRectangle(Brush,0,y,width,height);
					 
			}		
void BufferForm::pokajiramkuFirst(Graphics^ g, int width, int height, int y)
			{
				Color PenColor;
				PenColor = System::Drawing::Color::LightCoral;
					// создание и инициализация Pen
				Pen^ MyPen;
					// Создание и инициализация заливки
				MyPen = gcnew Pen(PenColor,5);
				g->DrawRectangle(MyPen,0,y,width,height);
					 
			}		
void BufferForm::ShowDoStack(Graphics ^g)
{//если стек не пуст 
				 try {
				 //узнаем количество элементов
				int end   = GetModel()->GetDoStack()->GetEnd(),
					i,
				//делим всю имеющуюся высоту панели на max кол-во элементов
					cell_height = panel6->Height/(SIZE_OF_STACK+10),
					cell_draw_height = panel6->Height/(SIZE_OF_STACK+1),
					row,colm,cell_width;
				//и рисуем поля из стека
				pokajiramkuFirst(g,panel6->Width, cell_height+4 ,0);
						for (i = 0; i <= end; i++)
					{
					//кол-во строк в поле в стеке
					row = GetModel()->GetDoStack()->ReadEl(i).Field->Row();
					//кол-во сток в поле в стеке
					colm = GetModel()->GetDoStack()->ReadEl(i).Field->Colmns();
					//ширина одной клетки
					cell_width  = panel6->Width/(row*colm);	
					//функция. g рисует полосу из клеточек поля,
					//с некоторого начального места
					if (i == end) pokajiramkuLast(g,panel6->Width, cell_height+4 ,i*cell_draw_height-2);
					showline(g,cell_width,cell_height,
						GetModel()->GetDoStack()->ReadEl(i).Field,row,colm,i*cell_draw_height);
					}
				 }
				 catch (...)
				 {}
				
				 }


void BufferForm::FirstPosToLastPos(Graphics ^g)
{//если стек не пуст 
				 
				 //узнаем позицию  последнего элемента
				int end   = GetModel()->GetStack()->GetEnd(),
					start = GetModel()->GetStack()->GetStart(),
					size   = GetModel()->GetStack()->GetSize(),
					i,
				//делим всю имеющуюся высоту панели на размер стека
					cell_height = panel1->Height/(SIZE_OF_STACK+10),
					cell_draw_height = panel1->Height/(SIZE_OF_STACK+1),
					row,colm,cell_width;
				//и рисуем поля из стека
						for (i = 0; i < size; i++)
					{
					//кол-во строк в поле в стеке
					row = GetModel()->GetStack()->ReadEl(i).Field->Row();
					//кол-во сток в поле в стеке
					colm = GetModel()->GetStack()->ReadEl(i).Field->Colmns();
					//ширина одной клетки
					cell_width  = panel1->Width/(row*colm);	
					//функция. g рисует полосу из клеточек поля,
					//с некоторого начального места
					if (i == end) pokajiramkuLast(g,panel1->Width, cell_height+4 ,i*cell_draw_height-2);
					if (i == start) pokajiramkuFirst(g,panel1->Width, cell_height+4 ,i*cell_draw_height-2);

					showline(g,cell_width,cell_height,
						GetModel()->GetStack()->ReadEl(i).Field,row,colm,i*cell_draw_height);
					}
				
				 }