#pragma once
#include "pixels.h"

namespace MilitaryAvoid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

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
			this->PB_Playboard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MilitaryAvoidForm::PB_Playboard_Paint);
			this->PB_Playboard->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MilitaryAvoidForm::PB_Playboard_MouseMove);
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
			//Point** workspace = new Point*;
			
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
			ratio_x = (float)(workspace[1]->X - workspace[0]->X) / 890;
			ratio_y = (float)(workspace[1]->Y - workspace[0]->Y) / 510;


			PB_Playboard->Width = this->Width;
			PB_Playboard->Height = this->Height;
			//Bitmap^ board = gcnew Bitmap(PB_Playboard->Width, PB_Playboard->Height);
			//Graphics^ grfx = Graphics::FromImage(board);
			////Drawing background
			//grfx->Clear(Color::FromArgb(205, 205, 205));
			//Rectangle* rect = new Rectangle(
			//	workspace[0]->X, workspace[0]->Y,
			//	-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);
			//PointF* p1 = new PointF(workspace[0]->X, workspace[0]->Y);
			//PointF* p2 = new PointF(-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);
			//LinearGradientBrush^ russia_grad = gcnew LinearGradientBrush(*p1, *p2,
			//	Color::Aqua, Color::BlueViolet);

			//GraphicsPath^ path = gcnew GraphicsPath();
			////path->AddEllipse(0, 0, 140, 70);
			//path->AddRectangle(*rect);
			//PathGradientBrush^ pthGrBrush = gcnew PathGradientBrush(path);
			//pthGrBrush->CenterColor = Color::FromArgb(255, 20, 255, 30);
			//pthGrBrush->CenterPoint = this->Cursor->Position;
			//array<Color>^ colors = { 
			//	Color::FromArgb(255, 0, 255, 255),
			//	Color::FromArgb(255, 0, 200, 255) 
			//};
			//pthGrBrush->SurroundColors = colors;


			////PathGradientBrush^ rg = gcnew PathGradientBrush();
			//grfx->FillRectangle(pthGrBrush, workspace[0]->X, workspace[0]->Y,
			//	-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);
			//array<Point>^ Russia = { 
			//	Point (workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 4 * ratio_y),
			//	Point (workspace[0]->X + 789 * ratio_x, workspace[0]->Y + 8 * ratio_y),
			//	Point (workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 11 * ratio_y),
			//	Point(workspace[0]->X + 791 * ratio_x, workspace[0]->Y + 13 * ratio_y),
			//	Point(workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 17 * ratio_y),
			//	Point(workspace[0]->X + 794 * ratio_x, workspace[0]->Y + 17 * ratio_y),
			//	Point(workspace[0]->X + 802 * ratio_x, workspace[0]->Y + 26 * ratio_y),
			//	Point(workspace[0]->X + 796 * ratio_x, workspace[0]->Y + 29 * ratio_y),
			//	Point(workspace[0]->X + 793 * ratio_x, workspace[0]->Y + 35 * ratio_y),
			//	Point(workspace[0]->X + 786 * ratio_x, workspace[0]->Y + 34 * ratio_y),
			//	Point(workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 44 * ratio_y),
			//	Point(workspace[0]->X + 777 * ratio_x, workspace[0]->Y + 45 * ratio_y),
			//	Point(workspace[0]->X + 773 * ratio_x, workspace[0]->Y + 44 * ratio_y),
			//	Point(workspace[0]->X + 775 * ratio_x, workspace[0]->Y + 53 * ratio_y),
			//	Point(workspace[0]->X + 782 * ratio_x, workspace[0]->Y + 54 * ratio_y),
			//	Point(workspace[0]->X + 786 * ratio_x, workspace[0]->Y + 58 * ratio_y),
			//	Point(workspace[0]->X + 788 * ratio_x, workspace[0]->Y + 67 * ratio_y),
			//	Point(workspace[0]->X + 781 * ratio_x, workspace[0]->Y + 71 * ratio_y)
			//};
			//grfx->FillPolygon(Brushes::Green, Russia);
			//this->Text = ratio_x.ToString();
			//PB_Playboard->Image = board;
			paint();
			delete center;
			//delete workspace[1];
			//delete workspace[2]; 
			//delete[] workspace;
		}

		public: System::Void paint() {
			Bitmap^ board = gcnew Bitmap(PB_Playboard->Width, PB_Playboard->Height);
			Graphics^ grfx = Graphics::FromImage(board);
			//Drawing background
			grfx->Clear(Color::FromArgb(205, 205, 205));
			Rectangle* rect = new Rectangle(
				workspace[0]->X, workspace[0]->Y,
				-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);
			PointF* p1 = new PointF(workspace[0]->X, workspace[0]->Y);
			PointF* p2 = new PointF(-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);
			LinearGradientBrush^ russia_grad = gcnew LinearGradientBrush(*p1, *p2,
				Color::Aqua, Color::BlueViolet);

			GraphicsPath^ path = gcnew GraphicsPath();
			//path->AddEllipse(0, 0, 140, 70);
			path->AddRectangle(*rect);
			PathGradientBrush^ pthGrBrush = gcnew PathGradientBrush(path);
			pthGrBrush->CenterColor = Color::FromArgb(255, 20, 255, 30);
			pthGrBrush->CenterPoint = this->Cursor->Position;
			array<Color>^ colors = {
				Color::FromArgb(255, 0, 255, 255),
				Color::FromArgb(255, 0, 200, 255)
			};
			pthGrBrush->SurroundColors = colors;


			//PathGradientBrush^ rg = gcnew PathGradientBrush();
			grfx->FillRectangle(pthGrBrush, workspace[0]->X, workspace[0]->Y,
				-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);
			array<Point>^ Russia = {
				Point(workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 4 * ratio_y),
				Point(workspace[0]->X + 789 * ratio_x, workspace[0]->Y + 8 * ratio_y),
				Point(workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 11 * ratio_y),
				Point(workspace[0]->X + 791 * ratio_x, workspace[0]->Y + 13 * ratio_y),
				Point(workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 17 * ratio_y),
				Point(workspace[0]->X + 794 * ratio_x, workspace[0]->Y + 17 * ratio_y),
				Point(workspace[0]->X + 802 * ratio_x, workspace[0]->Y + 26 * ratio_y),
				Point(workspace[0]->X + 796 * ratio_x, workspace[0]->Y + 29 * ratio_y),
				Point(workspace[0]->X + 793 * ratio_x, workspace[0]->Y + 35 * ratio_y),
				Point(workspace[0]->X + 786 * ratio_x, workspace[0]->Y + 34 * ratio_y),
				Point(workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 44 * ratio_y),
				Point(workspace[0]->X + 777 * ratio_x, workspace[0]->Y + 45 * ratio_y),
				Point(workspace[0]->X + 773 * ratio_x, workspace[0]->Y + 44 * ratio_y),
				Point(workspace[0]->X + 775 * ratio_x, workspace[0]->Y + 53 * ratio_y),
				Point(workspace[0]->X + 782 * ratio_x, workspace[0]->Y + 54 * ratio_y),
				Point(workspace[0]->X + 786 * ratio_x, workspace[0]->Y + 58 * ratio_y),
				Point(workspace[0]->X + 788 * ratio_x, workspace[0]->Y + 67 * ratio_y),
				Point(workspace[0]->X + 781 * ratio_x, workspace[0]->Y + 71 * ratio_y)
			};
			grfx->FillPolygon(Brushes::Green, Russia);
			this->Text = ratio_x.ToString();
			PB_Playboard->Image = board;
		}

		private: System::Void MilitaryAvoidForm_Load(System::Object^ sender, System::EventArgs^ e) {
			draw();
		}
		private: System::Void MilitaryAvoidForm_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
			draw();
		}
		private: System::Void PB_Playboard_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			//paint();
		}
		private: System::Void PB_Playboard_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			paint();
		}
	};
}
