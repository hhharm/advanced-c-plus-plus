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
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public BaseForm
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		
		virtual void MyRefresh()override;
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	protected: 
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Bisque;
			this->flowLayoutPanel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->flowLayoutPanel1->Location = System::Drawing::Point(525, 40);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(176, 162);
			this->flowLayoutPanel1->TabIndex = 0;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::flowLayoutPanel1_Paint);
			this->flowLayoutPanel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::flowLayoutPanel1_MouseClick);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel2->AutoSize = true;
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::White;
			this->flowLayoutPanel2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->flowLayoutPanel2->Location = System::Drawing::Point(22, 40);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(500, 500);
			this->flowLayoutPanel2->TabIndex = 1;
			this->flowLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::flowLayoutPanel2_Paint);
			this->flowLayoutPanel2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::flowLayoutPanel2_MouseClick);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button1->Location = System::Drawing::Point(586, 208);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(49, 48);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Play/Stop";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button2->Location = System::Drawing::Point(525, 208);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 48);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Next State";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button3->Location = System::Drawing::Point(641, 208);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 48);
			this->button3->TabIndex = 2;
			this->button3->Text = L"New Game";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button4->Location = System::Drawing::Point(542, 262);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(146, 22);
			this->button4->TabIndex = 3;
			this->button4->Text = L"UnDo";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button5->Location = System::Drawing::Point(542, 290);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(145, 24);
			this->button5->TabIndex = 4;
			this->button5->Text = L"ReDo";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			this->button5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::button5_Paint);
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button6->Location = System::Drawing::Point(542, 403);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(143, 53);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Настройки";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button7->Location = System::Drawing::Point(542, 474);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(143, 53);
			this->button7->TabIndex = 5;
			this->button7->Text = L"History";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(583, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Template";
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PowderBlue;
			this->ClientSize = System::Drawing::Size(713, 560);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"Form1";
			this->Text = L" Game";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void Paint2D(Graphics^ g, int width,  int height,  TField *field,int row, int colm);

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			this->GetModel()->ShowBuf();
		 }
private: System::Void flowLayoutPanel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ g = e->Graphics;
			g = flowLayoutPanel2->CreateGraphics();
			int width = flowLayoutPanel2->Width/(GetModel()->GetField()->Row());
			int height = flowLayoutPanel2->Height/(GetModel()->GetField()->Colmns());
			Paint2D(g,width,height, GetModel()->GetField(), GetModel()->GetField()->Row(), GetModel()->GetField()->Colmns());
		 }
private: System::Void flowLayoutPanel2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int x, y, value;
			  y = e->X/(flowLayoutPanel2->Width/(GetModel()->GetField()->Row()));
			  x = e->Y/(flowLayoutPanel2->Height/(GetModel()->GetField()->Colmns()));
			  value =  (GetModel()->GetField()->GetEl(x,y)+1)%GetModel()->GetField()->MaxNumOfStates();
			  GetModel()->GetField()->SetEl(x,y,value);			  
			  GetModel()->GetStack()->Push(GetModel()->GetCurrentField());
			  GetModel()->GetDoStack()->Clean();
			  GetModel()->AllRefresh();
		 }
private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ g = e->Graphics;
			g = flowLayoutPanel1->CreateGraphics();
			
			int width = flowLayoutPanel1->Width/(GetModel()->GetTemp()->Row());
			int height = flowLayoutPanel1->Height/(GetModel()->GetTemp()->Colmns());
			Paint2D(g,width,height, GetModel()->GetTemp(), GetModel()->GetTemp()->Row(), GetModel()->GetTemp()->Colmns());
		 }
private: System::Void flowLayoutPanel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int x, y, value;
			  y = e->X/(flowLayoutPanel1->Width/(GetModel()->GetTemp()->Row()));
			  x = e->Y/(flowLayoutPanel1->Height/(GetModel()->GetTemp()->Colmns()));
			  value =  (GetModel()->GetTemp()->GetEl(x,y)+1)%GetModel()->GetTemp()->MaxNumOfStates();
			  GetModel()->GetTemp()->SetEl(x,y,value);
			  GetModel()->GetStack()->Push(GetModel()->GetCurrentField());
			  GetModel()->GetDoStack()->Clean();
			  GetModel()->AllRefresh();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 
			 TAlg::NextState(
				 GetModel()->GetField(), GetModel()->GetRes(), GetModel()->GetTemp());
			 *GetModel()->GetField() = *GetModel()->GetRes();
			  GetModel()->GetStack()->Push(GetModel()->GetCurrentField());
			  GetModel()->GetDoStack()->Clean();
			  GetModel()->AllRefresh();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!timer1->Enabled) timer1->Start();
			 else timer1->Stop();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (timer1->Enabled) timer1->Stop();
			 this->GetModel()->BeginAnew();			 
			 flowLayoutPanel1->Refresh();
			 flowLayoutPanel2->Refresh();
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			  
			 TAlg::NextState(
				 GetModel()->GetField(), GetModel()->GetRes(), GetModel()->GetTemp());
			 *(GetModel()->GetField()) = *(GetModel()->GetRes());
			 GetModel()->GetStack()->Push(GetModel()->GetCurrentField());
			 GetModel()->GetDoStack()->Clean();
			 GetModel()->AllRefresh();
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 GetModel()->ShowSettings();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			
				 
			 try{
				 GetModel()->UnDoCommand();
			 }
			 catch (...)
			 {
				 MessageBox::Show("Sorry, there is no history.");
				 GetModel()->ReDoCommand();
			 }
			 GetModel()->AllRefresh();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 GetModel()->ReDoCommand();
			 }
			 catch (...)
			 {
				 MessageBox::Show("Sorry, but I can not do this");
			 }		 
			 GetModel()->AllRefresh();
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			GetModel()->GetStack()->Push(GetModel()->GetCurrentField());
		 }
private: System::Void button5_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 if (GetModel()->GetDoStack()->IsEmpty())
				 button5->Enabled = false;
			 else button5->Enabled = true;
		 }
};
}

