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
			SolidBrush^ bg = gcnew SolidBrush(Color::FromArgb(205, 205, 205));

			//PathGradientBrush^ rg = gcnew PathGradientBrush();
			grfx->FillRectangle(pthGrBrush, workspace[0]->X, workspace[0]->Y,
				-workspace[0]->X + workspace[1]->X, -workspace[0]->Y + workspace[1]->Y);
			array<Point>^ Russia0 = {
				Point(workspace[1]->X, workspace[0]->Y + 4 * ratio_y),
				Point(workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 4 * ratio_y),
				Point(workspace[0]->X + 789 * ratio_x, workspace[0]->Y + 8 * ratio_y),
				Point(workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 11 * ratio_y),
				Point(workspace[0]->X + 791 * ratio_x, workspace[0]->Y + 13 * ratio_y),
				Point(workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 17 * ratio_y),
				Point(workspace[0]->X + 794 * ratio_x, workspace[0]->Y + 17 * ratio_y),
				Point(workspace[0]->X + 802 * ratio_x, workspace[0]->Y + 26 * ratio_y),
				Point(workspace[1]->X, workspace[0]->Y + 26 * ratio_y)
			};
			array<Point>^ Russia1 = {
				Point(workspace[1]->X, workspace[0]->Y + 26 * ratio_y),
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
				Point(workspace[0]->X + 781 * ratio_x, workspace[0]->Y + 71 * ratio_y),
				Point(workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 74 * ratio_y),
				Point(workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 71 * ratio_y),
				Point(workspace[0]->X + 795 * ratio_x, workspace[0]->Y + 68 * ratio_y),
				Point(workspace[0]->X + 802 * ratio_x, workspace[0]->Y + 69 * ratio_y),
				Point(workspace[0]->X + 812 * ratio_x, workspace[0]->Y + 67 * ratio_y),
				Point(workspace[0]->X + 815 * ratio_x, workspace[0]->Y + 71 * ratio_y),
				Point(workspace[0]->X + 807 * ratio_x, workspace[0]->Y + 77 * ratio_y),
				Point(workspace[0]->X + 812 * ratio_x, workspace[0]->Y + 89 * ratio_y),
				Point(workspace[0]->X + 816 * ratio_x, workspace[0]->Y + 111 * ratio_y),
				Point(workspace[0]->X + 819 * ratio_x, workspace[0]->Y + 123 * ratio_y),
				Point(workspace[0]->X + 825 * ratio_x, workspace[0]->Y + 128 * ratio_y),
				Point(workspace[0]->X + 816 * ratio_x, workspace[0]->Y + 129 * ratio_y),
				Point(workspace[0]->X + 810 * ratio_x, workspace[0]->Y + 138 * ratio_y),
				Point(workspace[0]->X + 811 * ratio_x, workspace[0]->Y + 145 * ratio_y),
				Point(workspace[0]->X + 814 * ratio_x, workspace[0]->Y + 151 * ratio_y),
				Point(workspace[0]->X + 807 * ratio_x, workspace[0]->Y + 147 * ratio_y),
				Point(workspace[0]->X + 811 * ratio_x, workspace[0]->Y + 157 * ratio_y),
				Point(workspace[0]->X + 807 * ratio_x, workspace[0]->Y + 159 * ratio_y),
				Point(workspace[0]->X + 806 * ratio_x, workspace[0]->Y + 164 * ratio_y),
				Point(workspace[0]->X + 814 * ratio_x, workspace[0]->Y + 173 * ratio_y),
				Point(workspace[0]->X + 813 * ratio_x, workspace[0]->Y + 180 * ratio_y),
				Point(workspace[0]->X + 823 * ratio_x, workspace[0]->Y + 185 * ratio_y),
				Point(workspace[0]->X + 825 * ratio_x, workspace[0]->Y + 181 * ratio_y),
				Point(workspace[0]->X + 829 * ratio_x, workspace[0]->Y + 180 * ratio_y),
				Point(workspace[0]->X + 831 * ratio_x, workspace[0]->Y + 185 * ratio_y),
				Point(workspace[0]->X + 838 * ratio_x, workspace[0]->Y + 188 * ratio_y),
				Point(workspace[0]->X + 845 * ratio_x, workspace[0]->Y + 190 * ratio_y),
				Point(workspace[0]->X + 840 * ratio_x, workspace[0]->Y + 194 * ratio_y),
				Point(workspace[0]->X + 845 * ratio_x, workspace[0]->Y + 201 * ratio_y),
				Point(workspace[0]->X + 849 * ratio_x, workspace[0]->Y + 204 * ratio_y),
				Point(workspace[0]->X + 854 * ratio_x, workspace[0]->Y + 204 * ratio_y),
				Point(workspace[0]->X + 857 * ratio_x, workspace[0]->Y + 208 * ratio_y),
				Point(workspace[0]->X + 852 * ratio_x, workspace[0]->Y + 210 * ratio_y),
				Point(workspace[0]->X + 852 * ratio_x, workspace[0]->Y + 219 * ratio_y),
				Point(workspace[0]->X + 858 * ratio_x, workspace[0]->Y + 224 * ratio_y),
				Point(workspace[0]->X + 862 * ratio_x, workspace[0]->Y + 226 * ratio_y),
				Point(workspace[0]->X + 858 * ratio_x, workspace[0]->Y + 232 * ratio_y),
				Point(workspace[0]->X + 860 * ratio_x, workspace[0]->Y + 239 * ratio_y),
				Point(workspace[0]->X + 868 * ratio_x, workspace[0]->Y + 245 * ratio_y),
				Point(workspace[0]->X + 872 * ratio_x, workspace[0]->Y + 259 * ratio_y),
				Point(workspace[1]->X, workspace[0]->Y + 259 * ratio_y)
			};
			array<Point>^ Russia2 = {
				Point(workspace[1]->X, workspace[0]->Y + 259 * ratio_y),
				Point(workspace[0]->X + 872 * ratio_x, workspace[0]->Y + 259 * ratio_y),
				Point(workspace[0]->X + 842 * ratio_x, workspace[0]->Y + 246 * ratio_y),
				Point(workspace[0]->X + 838 * ratio_x, workspace[0]->Y + 243 * ratio_y),
				Point(workspace[0]->X + 821 * ratio_x, workspace[0]->Y + 236 * ratio_y),
				Point(workspace[0]->X + 814 * ratio_x, workspace[0]->Y + 228 * ratio_y),
				Point(workspace[0]->X + 811 * ratio_x, workspace[0]->Y + 219 * ratio_y),
				Point(workspace[0]->X + 809 * ratio_x, workspace[0]->Y + 216 * ratio_y),
				Point(workspace[0]->X + 806 * ratio_x, workspace[0]->Y + 214 * ratio_y),
				Point(workspace[0]->X + 809 * ratio_x, workspace[0]->Y + 206 * ratio_y),
				Point(workspace[0]->X + 805 * ratio_x, workspace[0]->Y + 190 * ratio_y),
				Point(workspace[0]->X + 803 * ratio_x, workspace[0]->Y + 188 * ratio_y),
				Point(workspace[0]->X + 798 * ratio_x, workspace[0]->Y + 171 * ratio_y),
				Point(workspace[0]->X + 795 * ratio_x, workspace[0]->Y + 169 * ratio_y),
				Point(workspace[0]->X + 797 * ratio_x, workspace[0]->Y + 163 * ratio_y),
				Point(workspace[0]->X + 797 * ratio_x, workspace[0]->Y + 157 * ratio_y),
				Point(workspace[0]->X + 793 * ratio_x, workspace[0]->Y + 154 * ratio_y),
				Point(workspace[0]->X + 791 * ratio_x, workspace[0]->Y + 153 * ratio_y),
				Point(workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 146 * ratio_y),
				Point(workspace[0]->X + 786 * ratio_x, workspace[0]->Y + 140 * ratio_y),
				Point(workspace[0]->X + 778 * ratio_x, workspace[0]->Y + 143 * ratio_y),
				Point(workspace[0]->X + 786 * ratio_x, workspace[0]->Y + 156 * ratio_y),
				Point(workspace[0]->X + 786 * ratio_x, workspace[0]->Y + 165 * ratio_y),
				Point(workspace[0]->X + 787 * ratio_x, workspace[0]->Y + 174 * ratio_y),
				Point(workspace[0]->X + 782 * ratio_x, workspace[0]->Y + 173 * ratio_y),
				Point(workspace[0]->X + 775 * ratio_x, workspace[0]->Y + 168 * ratio_y),
				Point(workspace[0]->X + 775 * ratio_x, workspace[0]->Y + 172 * ratio_y),
				Point(workspace[0]->X + 770 * ratio_x, workspace[0]->Y + 173 * ratio_y),
				Point(workspace[0]->X + 769 * ratio_x, workspace[0]->Y + 181 * ratio_y),
				Point(workspace[0]->X + 770 * ratio_x, workspace[0]->Y + 191 * ratio_y),
				Point(workspace[0]->X + 773 * ratio_x, workspace[0]->Y + 199 * ratio_y),
				Point(workspace[0]->X + 774 * ratio_x, workspace[0]->Y + 209 * ratio_y),
				Point(workspace[0]->X + 777 * ratio_x, workspace[0]->Y + 215 * ratio_y),
				Point(workspace[0]->X + 784 * ratio_x, workspace[0]->Y + 212 * ratio_y),
				Point(workspace[0]->X + 782 * ratio_x, workspace[0]->Y + 218 * ratio_y),
				Point(workspace[0]->X + 778 * ratio_x, workspace[0]->Y + 219 * ratio_y),
				Point(workspace[0]->X + 779 * ratio_x, workspace[0]->Y + 226 * ratio_y),
				Point(workspace[0]->X + 776 * ratio_x, workspace[0]->Y + 232 * ratio_y),
				Point(workspace[0]->X + 772 * ratio_x, workspace[0]->Y + 231 * ratio_y),
				Point(workspace[0]->X + 773 * ratio_x, workspace[0]->Y + 226 * ratio_y),
				Point(workspace[0]->X + 757 * ratio_x, workspace[0]->Y + 234 * ratio_y),
				Point(workspace[0]->X + 759 * ratio_x, workspace[0]->Y + 241 * ratio_y),
				Point(workspace[0]->X + 749 * ratio_x, workspace[0]->Y + 250 * ratio_y),
				Point(workspace[0]->X + 750 * ratio_x, workspace[0]->Y + 256 * ratio_y),
				Point(workspace[0]->X + 743 * ratio_x, workspace[0]->Y + 256 * ratio_y),
				Point(workspace[0]->X + 731 * ratio_x, workspace[0]->Y + 274 * ratio_y),
				Point(workspace[0]->X + 733 * ratio_x, workspace[0]->Y + 280 * ratio_y),
				Point(workspace[0]->X + 731 * ratio_x, workspace[0]->Y + 283 * ratio_y),
				Point(workspace[0]->X + 731 * ratio_x, workspace[0]->Y + 289 * ratio_y),
				Point(workspace[0]->X + 735 * ratio_x, workspace[0]->Y + 292 * ratio_y),
				Point(workspace[1]->X, workspace[0]->Y + 292 * ratio_y)
			};
			grfx->FillPolygon(bg, Russia1);
			grfx->FillPolygon(bg, Russia0);
			grfx->FillPolygon(bg, Russia2);
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
