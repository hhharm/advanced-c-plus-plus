#pragma once
#include "BaseForm.h"
namespace LabWork4thSem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ History
	/// </summary>
	public ref class History : public BaseForm
	{
	public:
		History(void)
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
		~History()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridViewHistory;
	protected: 

	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
	virtual void MyRefresh()override
		{
			dataGridViewHistory->Refresh();
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridViewHistory = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridViewHistory))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewHistory
			// 
			this->dataGridViewHistory->AllowUserToAddRows = false;
			this->dataGridViewHistory->AllowUserToDeleteRows = false;
			this->dataGridViewHistory->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->dataGridViewHistory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewHistory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewHistory->Location = System::Drawing::Point(0, 0);
			this->dataGridViewHistory->Name = L"dataGridViewHistory";
			this->dataGridViewHistory->ReadOnly = true;
			this->dataGridViewHistory->RowTemplate->Height = 24;
			this->dataGridViewHistory->Size = System::Drawing::Size(248, 592);
			this->dataGridViewHistory->TabIndex = 0;
			this->dataGridViewHistory->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &History::dataGridViewHistory_CellContentClick);
			this->dataGridViewHistory->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &History::dataGridViewHistory_Paint);
			// 
			// History
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(248, 592);
			this->Controls->Add(this->dataGridViewHistory);
			this->Name = L"History";
			this->Text = L"History";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &History::History_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridViewHistory))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void History_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 Hide();
			 }
	private: System::Void dataGridViewHistory_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 dataGridViewHistory->Rows->Clear();
				 dataGridViewHistory->Rows->Add(1);
				 int stack_size = GetModel()->GetStackSize();
				 MyPoint t;
				 MyStack* st = GetModel()->GetStack();
				 for (int i = 0; i < stack_size; i++)
					{
						t = st->ReadEl(i);
					}
			 }
	};
}
