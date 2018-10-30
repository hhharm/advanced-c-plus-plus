#pragma once
#include "Observer.h"

namespace LifeApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для BufferForm
	/// </summary>
	public ref class BufferForm : public BaseForm
	{
	public:
		BufferForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		
virtual void MyRefresh() override;
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BufferForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel4;

	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  CloseButton;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->panel3->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gainsboro;
			this->panel1->Location = System::Drawing::Point(9, 18);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(622, 408);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BufferForm::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BufferForm::panel1_MouseClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 452);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(237, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Можем ли мы повторить действия:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(188, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 17);
			this->label3->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(271, 452);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"label4";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Location = System::Drawing::Point(450, 432);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(181, 88);
			this->panel3->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(85, 2);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 17);
			this->label6->TabIndex = 7;
			this->label6->Text = L"First";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::LightCoral;
			this->panel4->Location = System::Drawing::Point(3, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(76, 10);
			this->panel4->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(85, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Last";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::DarkViolet;
			this->panel5->Location = System::Drawing::Point(3, 28);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(76, 10);
			this->panel5->TabIndex = 6;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Gainsboro;
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Location = System::Drawing::Point(637, 19);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(320, 408);
			this->panel6->TabIndex = 8;
			this->panel6->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BufferForm::panel6_Paint);
			// 
			// panel7
			// 
			this->panel7->Location = System::Drawing::Point(883, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(265, 536);
			this->panel7->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(319, -2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Основной стек";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(773, -2);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 17);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Стек отмены";
			// 
			// CloseButton
			// 
			this->CloseButton->Location = System::Drawing::Point(743, 500);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(214, 46);
			this->CloseButton->TabIndex = 10;
			this->CloseButton->Text = L"Hide";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &BufferForm::CloseButton_Click);
			// 
			// BufferForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(975, 558);
			this->ControlBox = false;
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Name = L"BufferForm";
			this->Text = L"Buffer";
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//функции для рисования
		//рисует поле в полоску
		void showline(Graphics^ g, int width,  int height,  IField *field,int row, int colm, int set_h);
		//показывает рамку
		void pokajiramkuFirst(Graphics^ g, int width, int height, int y);
		//показывает рамку
		void pokajiramkuLast(Graphics^ g, int width, int height, int y);
		//очищает панель
		void Clear_Panel(Graphics^ g, int width, int height);
		//функция, рисующая основной стек
		void FirstPosToLastPos(Graphics ^g);
		//функция, рисующая стек отмены действий
		void ShowDoStack(Graphics ^g);
//перерисовка
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Graphics^ g = e->Graphics;
				 g = panel1->CreateGraphics();

				 Clear_Panel(g, panel1->Width,panel1->Height);

				 FirstPosToLastPos(g);
							
				 if (!GetModel()->GetDoStack()->IsEmpty())	

				 label4->Text = "ДА";
				 else label4->Text = "НЕТ";
			 }
private: System::Void panel6_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Graphics^ g = e->Graphics;
				 g = panel6->CreateGraphics();

				 Clear_Panel(g, panel6->Width,panel6->Height);

				 ShowDoStack(g);
		 }

//нажатие
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int c,
			cell_draw_height = panel1->Height/(SIZE_OF_STACK+1),
			cur = e->Y/cell_draw_height;
			try
			{
			 				
				  while (GetModel()->GetStack()->GetEnd() != cur)
						GetModel()->UnDoCommand();
				 GetModel()->AllRefresh();
				
			}
			catch (...)
			{
					MessageBox::Show("Sorry, this memory is not avaliable");
					GetModel()->ReDoCommand();
			}
		 }
private: System::Void BufferForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 this->Hide();
		 }
private: System::Void BufferForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 this->Hide();
		 }
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
		 }
};
}
