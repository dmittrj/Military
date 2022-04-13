#include "MilitaryAvoid.h"

[System::STAThreadAttribute]
void main(array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	MilitaryAvoid::MilitaryAvoidForm form;
	System::Windows::Forms::Application::Run(% form);
}
