#include "MainForm.h"
#include "AboutForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array <String^> ^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TaskManager::MainForm form;
	Application::Run(%form);
	return 0;
}