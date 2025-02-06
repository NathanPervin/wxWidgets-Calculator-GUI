#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ Calculator");
	mainFrame->SetClientSize(350, 450);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
