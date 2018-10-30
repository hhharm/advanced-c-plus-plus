#pragma once
#include "Observer.h"
namespace lib3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Settings
	/// </summary>
	public ref class Settings : public BaseForm
	{
	public:
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RadioButton^  radioButton17;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton16;
	private: System::Windows::Forms::RadioButton^  radioButton15;
	private: System::Windows::Forms::RadioButton^  radioButton14;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::RadioButton^  radioButton13;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::RadioButton^  radioButton12;
	private: System::Windows::Forms::RadioButton^  radioButton11;
	private: System::Windows::Forms::Panel^  panel4;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->radioButton16 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton15 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton17 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->radioButton6);
			this->panel1->Controls->Add(this->radioButton5);
			this->panel1->Controls->Add(this->radioButton4);
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->numericUpDown2);
			this->panel1->Controls->Add(this->numericUpDown1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(13, 11);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(472, 249);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Settings::panel1_Paint);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->radioButton9);
			this->panel3->Controls->Add(this->radioButton8);
			this->panel3->Controls->Add(this->radioButton7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Location = System::Drawing::Point(7, 121);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 100);
			this->panel3->TabIndex = 4;
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Location = System::Drawing::Point(9, 76);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(37, 21);
			this->radioButton9->TabIndex = 5;
			this->radioButton9->TabStop = true;
			this->radioButton9->Text = L"7";
			this->radioButton9->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(9, 50);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(37, 21);
			this->radioButton8->TabIndex = 5;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"3";
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(9, 27);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(37, 21);
			this->radioButton7->TabIndex = 5;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"1";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 4);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(116, 17);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Number of colors";
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(275, 175);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(64, 21);
			this->radioButton6->TabIndex = 3;
			this->radioButton6->Text = L"Heart";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Settings::radioButton6_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(275, 150);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(160, 21);
			this->radioButton5->TabIndex = 3;
			this->radioButton5->Text = L"Inverse Chess Board";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(275, 121);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(82, 21);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->Text = L"Random";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(275, 94);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(63, 21);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->Text = L"Lines";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(275, 67);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(110, 21);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->Text = L"Chess Board";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(275, 35);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(68, 21);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->Text = L"Empty";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Validated += gcnew System::EventHandler(this, &Settings::radioButton1_Validated);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(272, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 17);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Filling";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(100, 47);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Colms";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Rows";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(103, 67);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(63, 22);
			this->numericUpDown2->TabIndex = 1;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Settings::numericUpDown2_Paint);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(7, 67);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(63, 22);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Settings::numericUpDown1_ValueChanged);
			this->numericUpDown1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Settings::numericUpDown1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Field";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->radioButton17);
			this->panel2->Controls->Add(this->radioButton10);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Location = System::Drawing::Point(13, 266);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(472, 235);
			this->panel2->TabIndex = 1;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Settings::panel2_Paint);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->radioButton16);
			this->panel4->Controls->Add(this->radioButton15);
			this->panel4->Controls->Add(this->radioButton14);
			this->panel4->Controls->Add(this->label9);
			this->panel4->Controls->Add(this->radioButton13);
			this->panel4->Controls->Add(this->radioButton12);
			this->panel4->Controls->Add(this->radioButton11);
			this->panel4->Location = System::Drawing::Point(262, 37);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(189, 183);
			this->panel4->TabIndex = 4;
			// 
			// radioButton16
			// 
			this->radioButton16->AutoSize = true;
			this->radioButton16->Location = System::Drawing::Point(16, 161);
			this->radioButton16->Name = L"radioButton16";
			this->radioButton16->Size = System::Drawing::Size(64, 21);
			this->radioButton16->TabIndex = 3;
			this->radioButton16->Text = L"Heart";
			this->radioButton16->UseVisualStyleBackColor = true;
			this->radioButton16->CheckedChanged += gcnew System::EventHandler(this, &Settings::radioButton6_CheckedChanged);
			// 
			// radioButton15
			// 
			this->radioButton15->AutoSize = true;
			this->radioButton15->Location = System::Drawing::Point(16, 134);
			this->radioButton15->Name = L"radioButton15";
			this->radioButton15->Size = System::Drawing::Size(160, 21);
			this->radioButton15->TabIndex = 3;
			this->radioButton15->Text = L"Inverse Chess Board";
			this->radioButton15->UseVisualStyleBackColor = true;
			// 
			// radioButton14
			// 
			this->radioButton14->AutoSize = true;
			this->radioButton14->Location = System::Drawing::Point(16, 107);
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->Size = System::Drawing::Size(82, 21);
			this->radioButton14->TabIndex = 3;
			this->radioButton14->Text = L"Random";
			this->radioButton14->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(13, 1);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(44, 17);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Filling";
			// 
			// radioButton13
			// 
			this->radioButton13->AutoSize = true;
			this->radioButton13->Location = System::Drawing::Point(16, 80);
			this->radioButton13->Name = L"radioButton13";
			this->radioButton13->Size = System::Drawing::Size(63, 21);
			this->radioButton13->TabIndex = 3;
			this->radioButton13->Text = L"Lines";
			this->radioButton13->UseVisualStyleBackColor = true;
			// 
			// radioButton12
			// 
			this->radioButton12->AutoSize = true;
			this->radioButton12->Location = System::Drawing::Point(16, 53);
			this->radioButton12->Name = L"radioButton12";
			this->radioButton12->Size = System::Drawing::Size(110, 21);
			this->radioButton12->TabIndex = 3;
			this->radioButton12->Text = L"Chess Board";
			this->radioButton12->UseVisualStyleBackColor = true;
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Location = System::Drawing::Point(16, 21);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(68, 21);
			this->radioButton11->TabIndex = 3;
			this->radioButton11->Text = L"Empty";
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->Validated += gcnew System::EventHandler(this, &Settings::radioButton1_Validated);
			// 
			// radioButton17
			// 
			this->radioButton17->AutoSize = true;
			this->radioButton17->Location = System::Drawing::Point(11, 85);
			this->radioButton17->Name = L"radioButton17";
			this->radioButton17->Size = System::Drawing::Size(59, 21);
			this->radioButton17->TabIndex = 3;
			this->radioButton17->TabStop = true;
			this->radioButton17->Text = L"5 x 5";
			this->radioButton17->UseVisualStyleBackColor = true;
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(12, 58);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(59, 21);
			this->radioButton10->TabIndex = 3;
			this->radioButton10->TabStop = true;
			this->radioButton10->Text = L"3 x 3";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &Settings::radioButton10_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 24);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Template";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(13, 38);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 17);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Size";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(289, 507);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 33);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Settings::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(389, 507);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 33);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Settings::button2_Click);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(503, 551);
			this->ControlBox = false;
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Settings";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Settings";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
			 }
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			  if (GetModel()->GetCurrentField()->fillf == 0) radioButton1->Checked = true;	
			  else if (GetModel()->GetCurrentField()->fillf == 1) radioButton2->Checked = true;			  
			  else if (GetModel()->GetCurrentField()->fillf == 2) radioButton3->Checked = true;
			  else if (GetModel()->GetCurrentField()->fillf == 3) radioButton4->Checked = true;
			  else if (GetModel()->GetCurrentField()->fillf == 4) radioButton5->Checked = true;
			  else if (GetModel()->GetCurrentField()->fillf == 5) radioButton6->Checked = true;
			  
		 }
private: System::Void numericUpDown1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 numericUpDown1->Value = GetModel()->GetField()->Row();
		 }
private: System::Void numericUpDown2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 numericUpDown2->Value = GetModel()->GetField()->Colmns();}
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void radioButton1_Validated(System::Object^  sender, System::EventArgs^  e) {}
		 
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 if (GetModel()->GetArr()[2] == 1) radioButton7->Checked = true;	
			 else if (GetModel()->GetArr()[2] == 2) radioButton8->Checked = true;
			 else if (GetModel()->GetArr()[2] == 3) radioButton9->Checked = true;


			 if (GetModel()->GetArr()[5] == 3) radioButton10->Checked = true;
			  else if (GetModel()->GetArr()[5] == 5) radioButton17->Checked = true;

			 if (GetModel()->GetCurrentField()->fillt == 0) radioButton11->Checked = true;	
			  else if (GetModel()->GetCurrentField()->fillt == 1) radioButton12->Checked = true;			  
			  else if (GetModel()->GetCurrentField()->fillt == 2) radioButton13->Checked = true;
			  else if (GetModel()->GetCurrentField()->fillt == 3) radioButton14->Checked = true;
			  else if (GetModel()->GetCurrentField()->fillt == 4) radioButton15->Checked = true;
			  else if (GetModel()->GetCurrentField()->fillt == 5) radioButton16->Checked = true;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 //number of states
			 if (radioButton7->Checked) GetModel()->GetArr()[2] = 1;	
			 else if (radioButton8->Checked)  GetModel()->GetArr()[2] = 2;
			 else if (radioButton9->Checked) GetModel()->GetArr()[2] = 3;

			 //start filling
			 if (radioButton1->Checked)  GetModel()->GetCurrentField()->fillf = 0;	
			  else if (radioButton2->Checked)  GetModel()->GetCurrentField()->fillf = 1;			  
			  else if (radioButton3->Checked)  GetModel()->GetCurrentField()->fillf  = 2;
			  else if (radioButton4->Checked)  GetModel()->GetCurrentField()->fillf  = 3;
			  else if (radioButton5->Checked)  GetModel()->GetCurrentField()->fillf  = 4;
			  else if (radioButton6->Checked)  GetModel()->GetCurrentField()->fillf  = 5;
			
			  //size
			  GetModel()->GetArr()[0] = (int) numericUpDown1->Value;
			  GetModel()->GetArr()[1] = (int) numericUpDown2->Value;

			  if (radioButton11->Checked)  GetModel()->GetCurrentField()->fillt = 0;	
			  else if (radioButton12->Checked)  GetModel()->GetCurrentField()->fillt = 1;			  
			  else if (radioButton13->Checked)  GetModel()->GetCurrentField()->fillt = 2;
			  else if (radioButton14->Checked)  GetModel()->GetCurrentField()->fillt = 3;
			  else if (radioButton15->Checked)  GetModel()->GetCurrentField()->fillt = 4;
			  else if (radioButton16->Checked)  GetModel()->GetCurrentField()->fillt = 5;

			  if (radioButton10->Checked)  GetModel()->GetArr()[5] = 3;	
			  else if (radioButton17->Checked)  GetModel()->GetArr()[5] = 5;

			  GetModel()->BeginAnew();
			  this->Hide();
		 }
private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
