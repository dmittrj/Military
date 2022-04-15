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
			this->SizeChanged += gcnew System::EventHandler(this, &MilitaryAvoidForm::MilitaryAvoidForm_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Playboard))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
		public: System::Void draw() {
			const int x_border = 25;
			const int y_border = 25;
			//const int x_aspect = 890;
			//const int y_aspect = 510;
			const float aspect = 510.0f / 890.0f;
			int width = this->Width - x_border * 2 - 20;
			int height = this->Height - y_border * 2 - 39;
			float real_aspect = (float)height / (float)width;
			Point* center = new Point((this->Width - 20) / 2, (this->Height - 39) / 2);
			Point** workspace = new Point*;
			if (real_aspect > aspect) {
				int new_height = width * aspect;
				workspace[0] = new Point(x_border, center->Y - new_height / 2);
				workspace[1] = new Point(x_border + width, center->Y + new_height / 2);
			}
			else {
				int new_width = height / aspect;
				workspace[0] = new Point(center->X - new_width / 2, y_border);
				workspace[1] = new Point(center->X + new_width / 2, y_border + height);
			}

			PB_Playboard->Width = this->Width;
			PB_Playboard->Height = this->Height;
			Bitmap^ board = gcnew Bitmap(PB_Playboard->Width, PB_Playboard->Height);
			Graphics^ grfx = Graphics::FromImage(board);
			//Drawing background
			grfx->Clear(Color::FromArgb(205, 205, 205));
			grfx->FillRectangle(Brushes::Bisque, workspace[0]->X, workspace[0]->Y,
				-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);

			PB_Playboard->Image = board;
		}

		private: System::Void MilitaryAvoidForm_Load(System::Object^ sender, System::EventArgs^ e) {
			draw();
		}
		private: System::Void MilitaryAvoidForm_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
			draw();
		}
	};
}
