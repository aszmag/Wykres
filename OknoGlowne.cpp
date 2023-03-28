#include "OknoGlowne.h"

using namespace Wykres;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew OknoGlowne());
	return 0;
}
