#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* Frame = new MainFrame("Site", wxDefaultPosition, wxDefaultSize);
	Frame->Center();
	Frame->SetClientSize(1000, 740);
	Frame->Show();
	return true;
}