#pragma once
#include "BaseForm.h"
#define POINT_RAD 3
namespace LabWork4thSem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 :  public BaseForm
	{
		
	public:
		Form1(void)
		{
			InitializeComponent();
			
		}
	virtual void MyRefresh()override
		{
			this->PointPanel->Refresh();
		}


	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBoxSetting;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBoxPoint;
	private: System::Windows::Forms::GroupBox^  groupBoxButtons;
	private: System::Windows::Forms::GroupBox^  groupBoxFormules;
	private: System::Windows::Forms::Panel^  PointPanel;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBoxYfunc;
	private: System::Windows::Forms::GroupBox^  groupBoxXfunc;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::TextBox^  textBoxYCoef;


	private: System::Windows::Forms::Label^  labelXpolynom;
	private: System::Windows::Forms::Button^  buttonAddX;



	private: System::Windows::Forms::TextBox^  textBoxXCoef;
	private: System::Windows::Forms::Label^  labelYfunc;
	private: System::Windows::Forms::Label^  labelXFunc;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Button^  RefreshButton;
	private: System::Windows::Forms::Button^  ClearYButton;
	private: System::Windows::Forms::Button^  ClearXButton;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownXDegX;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownXdegT;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownXdegY;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownYdegT;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownYdegY;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownYdegX;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Y;



	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->groupBoxSetting = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxButtons = (gcnew System::Windows::Forms::GroupBox());
			this->RefreshButton = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBoxFormules = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxYfunc = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDownYdegT = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownYdegY = (gcnew System::Windows::Forms::NumericUpDown());
			this->ClearYButton = (gcnew System::Windows::Forms::Button());
			this->numericUpDownYdegX = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->labelYfunc = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxYCoef = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxXfunc = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDownXdegT = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownXdegY = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownXDegX = (gcnew System::Windows::Forms::NumericUpDown());
			this->ClearXButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelXFunc = (gcnew System::Windows::Forms::Label());
			this->labelXpolynom = (gcnew System::Windows::Forms::Label());
			this->buttonAddX = (gcnew System::Windows::Forms::Button());
			this->textBoxXCoef = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxPoint = (gcnew System::Windows::Forms::GroupBox());
			this->PointPanel = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBoxSetting->SuspendLayout();
			this->groupBoxButtons->SuspendLayout();
			this->panel2->SuspendLayout();
			this->groupBoxFormules->SuspendLayout();
			this->groupBoxYfunc->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownYdegT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownYdegY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownYdegX))->BeginInit();
			this->groupBoxXfunc->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownXdegT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownXdegY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownXDegX))->BeginInit();
			this->groupBoxPoint->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBoxSetting
			// 
			this->groupBoxSetting->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->groupBoxSetting->Controls->Add(this->groupBoxButtons);
			this->groupBoxSetting->Controls->Add(this->groupBoxFormules);
			this->groupBoxSetting->Location = System::Drawing::Point(489, 45);
			this->groupBoxSetting->Name = L"groupBoxSetting";
			this->groupBoxSetting->Size = System::Drawing::Size(468, 453);
			this->groupBoxSetting->TabIndex = 0;
			this->groupBoxSetting->TabStop = false;
			this->groupBoxSetting->Text = L"Settings";
			// 
			// groupBoxButtons
			// 
			this->groupBoxButtons->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBoxButtons->Controls->Add(this->RefreshButton);
			this->groupBoxButtons->Controls->Add(this->panel2);
			this->groupBoxButtons->Location = System::Drawing::Point(6, 382);
			this->groupBoxButtons->Name = L"groupBoxButtons";
			this->groupBoxButtons->Size = System::Drawing::Size(315, 64);
			this->groupBoxButtons->TabIndex = 1;
			this->groupBoxButtons->TabStop = false;
			this->groupBoxButtons->Text = L"Control Buttons";
			// 
			// RefreshButton
			// 
			this->RefreshButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"RefreshButton.Image")));
			this->RefreshButton->Location = System::Drawing::Point(260, 20);
			this->RefreshButton->Name = L"RefreshButton";
			this->RefreshButton->Size = System::Drawing::Size(49, 38);
			this->RefreshButton->TabIndex = 3;
			this->RefreshButton->UseVisualStyleBackColor = true;
			this->RefreshButton->Click += gcnew System::EventHandler(this, &Form1::RefreshButton_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(43, 20);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(172, 38);
			this->panel2->TabIndex = 2;
			// 
			// button4
			// 
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(133, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(39, 38);
			this->button4->TabIndex = 0;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(42, 38);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(93, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(38, 38);
			this->button3->TabIndex = 0;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(48, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(39, 38);
			this->button2->TabIndex = 0;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// groupBoxFormules
			// 
			this->groupBoxFormules->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->groupBoxFormules->Controls->Add(this->groupBoxYfunc);
			this->groupBoxFormules->Controls->Add(this->groupBoxXfunc);
			this->groupBoxFormules->Location = System::Drawing::Point(6, 68);
			this->groupBoxFormules->Name = L"groupBoxFormules";
			this->groupBoxFormules->Size = System::Drawing::Size(449, 308);
			this->groupBoxFormules->TabIndex = 0;
			this->groupBoxFormules->TabStop = false;
			this->groupBoxFormules->Text = L"Formules";
			// 
			// groupBoxYfunc
			// 
			this->groupBoxYfunc->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBoxYfunc->Controls->Add(this->numericUpDownYdegT);
			this->groupBoxYfunc->Controls->Add(this->numericUpDownYdegY);
			this->groupBoxYfunc->Controls->Add(this->ClearYButton);
			this->groupBoxYfunc->Controls->Add(this->numericUpDownYdegX);
			this->groupBoxYfunc->Controls->Add(this->label8);
			this->groupBoxYfunc->Controls->Add(this->label7);
			this->groupBoxYfunc->Controls->Add(this->labelYfunc);
			this->groupBoxYfunc->Controls->Add(this->label6);
			this->groupBoxYfunc->Controls->Add(this->button5);
			this->groupBoxYfunc->Controls->Add(this->label5);
			this->groupBoxYfunc->Controls->Add(this->textBoxYCoef);
			this->groupBoxYfunc->Location = System::Drawing::Point(6, 160);
			this->groupBoxYfunc->Name = L"groupBoxYfunc";
			this->groupBoxYfunc->Size = System::Drawing::Size(437, 142);
			this->groupBoxYfunc->TabIndex = 0;
			this->groupBoxYfunc->TabStop = false;
			this->groupBoxYfunc->Text = L"y = f(x, y, t)";
			this->groupBoxYfunc->Enter += gcnew System::EventHandler(this, &Form1::groupBoxYfunc_Enter);
			// 
			// numericUpDownYdegT
			// 
			this->numericUpDownYdegT->Location = System::Drawing::Point(171, 50);
			this->numericUpDownYdegT->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->numericUpDownYdegT->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, System::Int32::MinValue});
			this->numericUpDownYdegT->Name = L"numericUpDownYdegT";
			this->numericUpDownYdegT->Size = System::Drawing::Size(44, 22);
			this->numericUpDownYdegT->TabIndex = 3;
			// 
			// numericUpDownYdegY
			// 
			this->numericUpDownYdegY->Location = System::Drawing::Point(116, 50);
			this->numericUpDownYdegY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->numericUpDownYdegY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, System::Int32::MinValue});
			this->numericUpDownYdegY->Name = L"numericUpDownYdegY";
			this->numericUpDownYdegY->Size = System::Drawing::Size(44, 22);
			this->numericUpDownYdegY->TabIndex = 2;
			// 
			// ClearYButton
			// 
			this->ClearYButton->Location = System::Drawing::Point(371, 90);
			this->ClearYButton->Name = L"ClearYButton";
			this->ClearYButton->Size = System::Drawing::Size(60, 46);
			this->ClearYButton->TabIndex = 5;
			this->ClearYButton->Text = L"Clear";
			this->ClearYButton->UseVisualStyleBackColor = true;
			this->ClearYButton->Click += gcnew System::EventHandler(this, &Form1::ClearYButton_Click);
			// 
			// numericUpDownYdegX
			// 
			this->numericUpDownYdegX->Location = System::Drawing::Point(60, 51);
			this->numericUpDownYdegX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->numericUpDownYdegX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, System::Int32::MinValue});
			this->numericUpDownYdegX->Name = L"numericUpDownYdegX";
			this->numericUpDownYdegX->Size = System::Drawing::Size(44, 22);
			this->numericUpDownYdegX->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(169, 29);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 17);
			this->label8->TabIndex = 4;
			this->label8->Text = L"deg(t)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(113, 29);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 17);
			this->label7->TabIndex = 4;
			this->label7->Text = L"deg(y)";
			// 
			// labelYfunc
			// 
			this->labelYfunc->BackColor = System::Drawing::SystemColors::HighlightText;
			this->labelYfunc->Location = System::Drawing::Point(3, 90);
			this->labelYfunc->Name = L"labelYfunc";
			this->labelYfunc->Size = System::Drawing::Size(362, 46);
			this->labelYfunc->TabIndex = 3;
			this->labelYfunc->Text = L"y = y + t";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(57, 29);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 17);
			this->label6->TabIndex = 4;
			this->label6->Text = L"deg(x)";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(227, 49);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(43, 22);
			this->button5->TabIndex = 9;
			this->button5->Text = L"add";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 29);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"coef";
			// 
			// textBoxYCoef
			// 
			this->textBoxYCoef->Location = System::Drawing::Point(6, 49);
			this->textBoxYCoef->Name = L"textBoxYCoef";
			this->textBoxYCoef->Size = System::Drawing::Size(32, 22);
			this->textBoxYCoef->TabIndex = 5;
			this->textBoxYCoef->Text = L"0";
			// 
			// groupBoxXfunc
			// 
			this->groupBoxXfunc->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBoxXfunc->Controls->Add(this->numericUpDownXdegT);
			this->groupBoxXfunc->Controls->Add(this->numericUpDownXdegY);
			this->groupBoxXfunc->Controls->Add(this->numericUpDownXDegX);
			this->groupBoxXfunc->Controls->Add(this->ClearXButton);
			this->groupBoxXfunc->Controls->Add(this->label4);
			this->groupBoxXfunc->Controls->Add(this->label3);
			this->groupBoxXfunc->Controls->Add(this->label2);
			this->groupBoxXfunc->Controls->Add(this->label1);
			this->groupBoxXfunc->Controls->Add(this->labelXFunc);
			this->groupBoxXfunc->Controls->Add(this->labelXpolynom);
			this->groupBoxXfunc->Controls->Add(this->buttonAddX);
			this->groupBoxXfunc->Controls->Add(this->textBoxXCoef);
			this->groupBoxXfunc->Location = System::Drawing::Point(7, 34);
			this->groupBoxXfunc->Name = L"groupBoxXfunc";
			this->groupBoxXfunc->Size = System::Drawing::Size(436, 120);
			this->groupBoxXfunc->TabIndex = 0;
			this->groupBoxXfunc->TabStop = false;
			this->groupBoxXfunc->Text = L"x = f(x, y, t)";
			// 
			// numericUpDownXdegT
			// 
			this->numericUpDownXdegT->Location = System::Drawing::Point(170, 45);
			this->numericUpDownXdegT->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->numericUpDownXdegT->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, System::Int32::MinValue});
			this->numericUpDownXdegT->Name = L"numericUpDownXdegT";
			this->numericUpDownXdegT->Size = System::Drawing::Size(44, 22);
			this->numericUpDownXdegT->TabIndex = 3;
			// 
			// numericUpDownXdegY
			// 
			this->numericUpDownXdegY->Location = System::Drawing::Point(115, 45);
			this->numericUpDownXdegY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->numericUpDownXdegY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, System::Int32::MinValue});
			this->numericUpDownXdegY->Name = L"numericUpDownXdegY";
			this->numericUpDownXdegY->Size = System::Drawing::Size(44, 22);
			this->numericUpDownXdegY->TabIndex = 2;
			// 
			// numericUpDownXDegX
			// 
			this->numericUpDownXDegX->Location = System::Drawing::Point(59, 46);
			this->numericUpDownXDegX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->numericUpDownXDegX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, System::Int32::MinValue});
			this->numericUpDownXDegX->Name = L"numericUpDownXDegX";
			this->numericUpDownXDegX->Size = System::Drawing::Size(44, 22);
			this->numericUpDownXDegX->TabIndex = 1;
			// 
			// ClearXButton
			// 
			this->ClearXButton->Location = System::Drawing::Point(370, 71);
			this->ClearXButton->Name = L"ClearXButton";
			this->ClearXButton->Size = System::Drawing::Size(60, 42);
			this->ClearXButton->TabIndex = 5;
			this->ClearXButton->Text = L"Clear";
			this->ClearXButton->UseVisualStyleBackColor = true;
			this->ClearXButton->Click += gcnew System::EventHandler(this, &Form1::ClearXButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(168, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"deg(t)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(112, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"deg(y)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(56, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"deg(x)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(2, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"coef";
			// 
			// labelXFunc
			// 
			this->labelXFunc->BackColor = System::Drawing::SystemColors::HighlightText;
			this->labelXFunc->Location = System::Drawing::Point(8, 74);
			this->labelXFunc->Name = L"labelXFunc";
			this->labelXFunc->Size = System::Drawing::Size(356, 39);
			this->labelXFunc->TabIndex = 3;
			this->labelXFunc->Text = L"x = x + 0.02*t + (-0.05)*t^2";
			// 
			// labelXpolynom
			// 
			this->labelXpolynom->AutoSize = true;
			this->labelXpolynom->Location = System::Drawing::Point(4, 84);
			this->labelXpolynom->Name = L"labelXpolynom";
			this->labelXpolynom->Size = System::Drawing::Size(0, 17);
			this->labelXpolynom->TabIndex = 2;
			// 
			// buttonAddX
			// 
			this->buttonAddX->Location = System::Drawing::Point(226, 45);
			this->buttonAddX->Name = L"buttonAddX";
			this->buttonAddX->Size = System::Drawing::Size(43, 22);
			this->buttonAddX->TabIndex = 4;
			this->buttonAddX->Text = L"add";
			this->buttonAddX->UseVisualStyleBackColor = true;
			this->buttonAddX->Click += gcnew System::EventHandler(this, &Form1::buttonAddX_Click);
			// 
			// textBoxXCoef
			// 
			this->textBoxXCoef->Location = System::Drawing::Point(5, 45);
			this->textBoxXCoef->Name = L"textBoxXCoef";
			this->textBoxXCoef->Size = System::Drawing::Size(32, 22);
			this->textBoxXCoef->TabIndex = 0;
			this->textBoxXCoef->Text = L"0";
			// 
			// groupBoxPoint
			// 
			this->groupBoxPoint->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->groupBoxPoint->Controls->Add(this->PointPanel);
			this->groupBoxPoint->Location = System::Drawing::Point(12, 45);
			this->groupBoxPoint->Name = L"groupBoxPoint";
			this->groupBoxPoint->Size = System::Drawing::Size(453, 453);
			this->groupBoxPoint->TabIndex = 1;
			this->groupBoxPoint->TabStop = false;
			this->groupBoxPoint->Text = L"Animation";
			// 
			// PointPanel
			// 
			this->PointPanel->BackColor = System::Drawing::Color::LightCyan;
			this->PointPanel->Location = System::Drawing::Point(3, 21);
			this->PointPanel->Name = L"PointPanel";
			this->PointPanel->Size = System::Drawing::Size(444, 425);
			this->PointPanel->TabIndex = 0;
			this->PointPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::PointPanel_Paint);
			this->PointPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::PointPanel_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1318, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(102, 24);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(62, 24);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Location = System::Drawing::Point(991, 44);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(311, 453);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"PointTable";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->X, this->Y});
			this->dataGridView1->Location = System::Drawing::Point(14, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(287, 411);
			this->dataGridView1->TabIndex = 0;
			// 
			// X
			// 
			this->X->HeaderText = L"x";
			this->X->Name = L"X";
			this->X->ReadOnly = true;
			// 
			// Y
			// 
			this->Y->HeaderText = L"y";
			this->Y->Name = L"Y";
			this->Y->ReadOnly = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1318, 516);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBoxPoint);
			this->Controls->Add(this->groupBoxSetting);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Point Mover";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBoxSetting->ResumeLayout(false);
			this->groupBoxButtons->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->groupBoxFormules->ResumeLayout(false);
			this->groupBoxYfunc->ResumeLayout(false);
			this->groupBoxYfunc->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownYdegT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownYdegY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownYdegX))->EndInit();
			this->groupBoxXfunc->ResumeLayout(false);
			this->groupBoxXfunc->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownXdegT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownXdegY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownXDegX))->EndInit();
			this->groupBoxPoint->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				Close();
			 }

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			GetModel()->NextStateCommand();
			 MyRefresh();
		 }
private: System::Void PointPanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			
				 Graphics ^g = e->Graphics;
				 Pen ^ pen = gcnew Pen (Color::Green, 10);
				 SolidBrush^ br = gcnew SolidBrush(Color::Green);
				 g = PointPanel->CreateGraphics();
				 GetModel()->GetData()->SetPoint(
					 ((int)GetModel()->GetData()->GetX()+PointPanel->Width)%PointPanel->Width,
					 ((int)GetModel()->GetData()->GetY()+PointPanel->Height)%PointPanel->Height);
				 g->DrawEllipse(pen, ((int)GetModel()->GetData()->GetX())%PointPanel->Width,
					 ((int)GetModel()->GetData()->GetY())%PointPanel->Height, POINT_RAD, POINT_RAD);
				 g->FillEllipse(br, ((int)GetModel()->GetData()->GetX())%PointPanel->Width,
					 ((int)GetModel()->GetData()->GetY())%PointPanel->Height, POINT_RAD, POINT_RAD);
		 }
private: System::Void PointPanel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 GetModel()->GetData()->SetPoint(e->X, e->Y);
			 MyRefresh();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer2->Enabled = true;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {GetModel()->NextStateCommand();
			 MyRefresh();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer2->Stop();
		 }

private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 GetModel()->GetData()->SetPoint(10, 10);
		 }
private: System::Void RefreshButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 GetModel()->GetData()->SetPoint(10,10);
			 GetModel()->GetData()->RestartTime();
			 MyRefresh();
		 }
private: System::Void ClearXButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer2->Stop();
			 GetModel()->GetData()->GetXPolynom()->Clear();
			 labelXFunc->Text = "0";
		 }
private: System::Void ClearYButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer2->Stop();
			 GetModel()->GetData()->GetYPolynom()->Clear();
			 labelYfunc->Text = "0";
		 }
private: System::Void buttonAddX_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer2->Stop();
			 int x = (int) numericUpDownXDegX->Value, y = (int) numericUpDownXdegY->Value,
				 t = (int) numericUpDownXdegT->Value;
			 Monom *n = new Monom(Convert::ToDouble((System::String^) textBoxXCoef->Text),
				 x, y, t);
			 GetModel()->GetData()->GetXPolynom()->PushMonom(*n);
			 label_RefreshPaint();
		 }

private: void label_RefreshPaint() {
			 labelXFunc->Text = "x = ";
			 Iterator it = GetModel()->GetData()->GetXPolynom()->iterator();
			 Monom t; 
			 int d[3];
			 labelXFunc->Text += "0";
			 while (it.HasNext())
			 {
				 t = it.Next();
				 labelXFunc->Text += " + ";
				 labelXFunc->Text += Convert::ToString(t.GetCoef());
				 labelXFunc->Text += " ";
				 d[0] = t.GetXdeg();
				 d[1] = t.GetYdeg();
				 d[2] = t.GetTdeg();
				 if (d[0] != 0) 
					 {
						 labelXFunc->Text += "*x^(";
						 labelXFunc->Text += Convert::ToString(t.GetXdeg());
						 labelXFunc->Text += ")";
					 }
				 if (d[1] != 0)
					  {
						 labelXFunc->Text += "*y^(";
						 labelXFunc->Text += Convert::ToString(t.GetYdeg());
						 labelXFunc->Text += ")";
					 }
				 if (d[2] != 0)
					  {
						 labelXFunc->Text += "*t^(";
						 labelXFunc->Text += Convert::ToString(t.GetTdeg());
						 labelXFunc->Text += ")";
					 }
			 }
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer2->Stop();
			 int x = (int) numericUpDownYdegX->Value, y = (int) numericUpDownYdegY->Value,
				 tt = (int) numericUpDownYdegT->Value;
			 Monom *n = new Monom(Convert::ToDouble((System::String^) textBoxYCoef->Text),
				 x, y, tt);
			 GetModel()->GetData()->GetYPolynom()->PushMonom(*n);
			 labelYfunc->Text = "y = ";
			 Iterator it = GetModel()->GetData()->GetYPolynom()->iterator();
			 Monom t; 
			 int d[3];
			 labelYfunc->Text += "0";
			 while (it.HasNext())
			 {
				 t = it.Next();
				 labelYfunc->Text += " + ";
				 labelYfunc->Text += Convert::ToString(t.GetCoef());
				 labelYfunc->Text += " ";
				 d[0] = t.GetXdeg();
				 d[1] = t.GetYdeg();
				 d[2] = t.GetTdeg();
				 if (d[0] != 0) 
					 {
						 labelYfunc->Text += "*x^(";
						 labelYfunc->Text += Convert::ToString(t.GetXdeg());
						 labelYfunc->Text += ")";
					 }
				 if (d[1] != 0)
					  {
						 labelYfunc->Text += "*y^(";
						 labelYfunc->Text += Convert::ToString(t.GetYdeg());
						 labelYfunc->Text += ")";
					 }
				 if (d[2] != 0)
					  {
						 labelYfunc->Text += "*t^(";
						 labelYfunc->Text += Convert::ToString(t.GetTdeg());
						 labelYfunc->Text += ")";
					 }
			 }
			 label_RefreshPaint();
		 }
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
			 GetModel()->NextStateCommand();
			 MyRefresh();
		 }
private: System::Void groupBoxYfunc_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 try
			 {
			 GetModel()->UnDoCommand();
			 MyRefresh();
			 }
			 catch (...)
			 {
				
				 MessageBox::Show("End of the history");
			 }
		 }
private: System::Void showHistoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 GetModel()->ShowHistory();
		 }
};
}

