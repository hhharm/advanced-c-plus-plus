#include "stdafx.h"
#include "Form1.h"
#include "BufferForm.h"

namespace LifeApp{



void Form1::Paint2D(Graphics ^g, int width,	 int height,  TField *field,int row, int colm)
	{
			 Color PenColor;
			 Color EmptyCellColor;
			 Color FirstStateOfCellColor;
			 Color SecondStateOfCellColor;
			 Color ThirdStateOfCellColor;	
			 Color FourthStateOfCellColor;
			 Color FifthStateOfCellColor;
			 Color SixthStateOfCellColor;			 
			 Color SeventhStateOfCellColor;
			 PenColor = System::Drawing::Color::Black;
			 EmptyCellColor = System::Drawing::Color::WhiteSmoke;
			 FirstStateOfCellColor = System::Drawing::Color::Red;
			 SecondStateOfCellColor = System::Drawing::Color::Orange;
			 ThirdStateOfCellColor = System::Drawing::Color::Yellow;
			 FourthStateOfCellColor = System::Drawing::Color::Green;
			 FifthStateOfCellColor = System::Drawing::Color::DeepSkyBlue;
			 SixthStateOfCellColor = System::Drawing::Color::Blue;			 
			 SeventhStateOfCellColor = System::Drawing::Color::DarkViolet;
			 // создание и инициализация Pen
			 Pen^ MyPen;
			 // Создание и инициализация заливки
			 SolidBrush ^EmptyBrush;
			 SolidBrush ^FirstBrush;
			 SolidBrush ^SecondBrush;
			 SolidBrush ^ThirdBrush;
			 SolidBrush ^FourthBrush;
			 SolidBrush ^FifthBrush;
			 SolidBrush ^SixthBrush;
			 SolidBrush ^SeventhBrush;
			 
			 EmptyBrush = gcnew SolidBrush(EmptyCellColor);
			 FirstBrush = gcnew SolidBrush(FirstStateOfCellColor);
			 SecondBrush = gcnew SolidBrush(SecondStateOfCellColor);
			 ThirdBrush = gcnew SolidBrush(ThirdStateOfCellColor);
			 FourthBrush= gcnew SolidBrush(FourthStateOfCellColor);
			 FifthBrush= gcnew SolidBrush(FifthStateOfCellColor);
			 SixthBrush= gcnew SolidBrush(SixthStateOfCellColor);
			 SeventhBrush= gcnew SolidBrush(SeventhStateOfCellColor);

			 //
			 int CellColor;
			 //
			 //

			 MyPen = gcnew Pen(PenColor,3);
			 
			 int i, j;
			 
					for (j=0;j<row;j++)
						for (i = 0; i<colm;i++)
				 		 {
					 CellColor = field->GetEl(j,i);
					 g->DrawRectangle(MyPen,i*width,j*height,width,height);
					
					 switch (CellColor)
					 {
					 case 0: {g->FillRectangle(EmptyBrush,i*width,j*height,width,height);break;}
					 case 1: {g->FillRectangle(FirstBrush,i*width,j*height,width,height);break;}
					 case 2: {g->FillRectangle(SecondBrush,i*width,j*height,width,height);break;}
					 case 3: {g->FillRectangle(ThirdBrush,i*width,j*height,width,height);break;}
					 case 4: {g->FillRectangle(FourthBrush,i*width,j*height,width,height);break;}
					 case 5: {g->FillRectangle(FifthBrush,i*width,j*height,width,height);break;}
					 case 6: {g->FillRectangle(SixthBrush,i*width,j*height,width,height);break;}
					 case 7: {g->FillRectangle(SeventhBrush,i*width,j*height,width,height);break;}
					}
					 
				 }		 
	}

void BufferForm::Clear_Panel(Graphics^ g, int width, int height)
{
	Color EmptyColor;
	EmptyColor = System::Drawing::Color::WhiteSmoke;
	SolidBrush ^EmptyBrush;
	EmptyBrush = gcnew SolidBrush(EmptyColor);
	g->FillRectangle(EmptyBrush,0,0,width,height);
}
void BufferForm::showline(Graphics^ g, int width,  int height,  TField *field,int row, int colm, int set_h)
	{

		
			 Color PenColor;
			 Color EmptyCellColor;
			 Color CCellColor;
			 PenColor = System::Drawing::Color::Black;
			 EmptyCellColor = System::Drawing::Color::WhiteSmoke;
			 CCellColor = System::Drawing::Color::Red;
			 // создание и инициализация Pen
			 Pen^ MyPen;
			 // Создание и инициализация заливки
			 SolidBrush ^EmptyBrush;
			 SolidBrush ^Brush;
			 
			 EmptyBrush = gcnew SolidBrush(EmptyCellColor);
			 Brush = gcnew SolidBrush(CCellColor);
			 //
			 int CellColor;
			 //
			 //
			 MyPen = gcnew Pen(PenColor,3);
			 
			 int i, j;
			 for (i = 0; i<colm;i++)
					for (j=0;j<row;j++)
						 {
					 CellColor = (*field).GetEl(i,j);
					 g->DrawRectangle(MyPen,(i*colm+j)*width,set_h,width,height);
					 switch (CellColor)
					 {
					 case 0: {g->FillRectangle(EmptyBrush,(i*colm+j)*width,set_h,width,height);break;}
					 default: {g->FillRectangle(Brush,(i*colm+j)*width,set_h,width,height);break;}
					}
					 
				 }
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


/*void BufferForm::StartToEnd(Graphics ^g){//если стек не пуст 
				
				 //узнаем позицию первого и последнего элемента
				int end    = GetModel()->GetStack()->GetEnd(),
					//и размер стека
					size   = GetModel()->GetStack()->GetSize(),
					pos    = (GetModel()->GetStack()->GetStart() - 1 + size)%size,
					i = 0,
				//делим всю имеющуюся высоту панели на 10
					cell_height = panel1->Height/(SIZE_OF_STACK+10),
					cell_draw_height = panel1->Height/(SIZE_OF_STACK+1),
					row,colm,cell_width;
				//и рисуем поля из стека
				//показываем рамку для первого
				pokajiramkuFirst(g,panel1->Width, cell_height+2 ,0);
				while (pos != end)
					{
					//кол-во строк в поле в стеке
					row = GetModel()->GetStack()->ReadEl(pos).Field->Row();
					//кол-во сток в поле в стеке
						colm = GetModel()->GetStack()->ReadEl(pos).Field->Colmns();
					//ширина одной клетки
					cell_width  = panel1->Width/(row*colm);	
					//функция. g рисует полосу из клеточек поля,
					//с некоторого начального места
					showline(g,cell_width,cell_height,
						GetModel()->GetStack()->ReadEl(pos).Field,row,colm,i*cell_draw_height);
					pos = (pos + 1)%size;
					i++;
					}
				//на последнем показываем рамочку
				pokajiramkuLast(g,panel1->Width, cell_height+2 ,i*cell_draw_height-1);
				//и рисуем
				row = GetModel()->GetStack()->ReadEl(pos).Field->Row();
				//кол-во сток в поле в стеке
				colm = GetModel()->GetStack()->ReadEl(pos).Field->Colmns();
				//ширина одной клетки
				cell_width  = panel1->Width/(row*colm);	
				showline(g,cell_width,cell_height,
						GetModel()->GetStack()->ReadEl(pos).Field,row,colm,i*cell_draw_height);
				 
}*/
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
	}
