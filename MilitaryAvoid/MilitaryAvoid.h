#pragma once

namespace MilitaryAvoid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MilitaryAvoidForm : public System::Windows::Forms::Form
	{
	public:
		MilitaryAvoidForm(void)
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
		~MilitaryAvoidForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ PB_Playboard;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PB_Playboard = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Playboard))->BeginInit();
			this->SuspendLayout();
			// 
			// PB_Playboard
			// 
			this->PB_Playboard->Location = System::Drawing::Point(0, 0);
			this->PB_Playboard->Name = L"PB_Playboard";
			this->PB_Playboard->Size = System::Drawing::Size(159, 105);
			this->PB_Playboard->TabIndex = 0;
			this->PB_Playboard->TabStop = false;
			// 
			// MilitaryAvoidForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(948, 524);
			this->Controls->Add(this->PB_Playboard);
			this->Name = L"MilitaryAvoidForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MilitaryAvoid";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MilitaryAvoidForm::MilitaryAvoidForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Playboard))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
		public: System::Void draw() {
			PB_Playboard->Width = this->Width;
			PB_Playboard->Height = this->Height;
			Bitmap^ board = gcnew Bitmap(PB_Playboard->Width, PB_Playboard->Height);
			Graphics^ grfx = Graphics::FromImage(board);
			//Drawing background
			grfx->Clear(Color::FromArgb(205, 205, 205));

			PB_Playboard->Image = board;
		}

		private: System::Void MilitaryAvoidForm_Load(System::Object^ sender, System::EventArgs^ e) {
			draw();
			//PB_Playboard->Width = this->Width;
			//PB_Playboard->Height = this->Height;
			//Bitmap ^board = gcnew Bitmap(PB_Playboard->Width, PB_Playboard->Height);
			//Graphics^ grfx = Graphics::FromImage(board);
			////Drawing background
			//grfx->Clear(Color::FromArgb(205, 205, 205));

			//PB_Playboard->Image = board;
		}
	};
}
