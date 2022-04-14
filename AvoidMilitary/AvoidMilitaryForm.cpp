#include "AvoidMilitaryForm.h"

[System::STAThreadAttribute]
void main(array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	AvoidMilitary::AvoidMilitaryForm form;
	System::Windows::Forms::Application::Run(% form);
}