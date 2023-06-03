#include "Logowanie.h"

Logowanie::Logowanie(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Narty", wxDefaultPosition, wxSize(1000, 740))
{
	panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1000, 30));
	panel_top->SetBackgroundColour(wxColor(132, 132, 132));

	panel_mid = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1000, 100));
	panel_mid->SetBackgroundColour(wxColor(252, 252, 252));

	panel_main1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1000, 600));
	panel_main1->SetBackgroundColour(wxColor(247, 240, 247));

	panel_main2 = new wxPanel(panel_main1, wxID_ANY, wxDefaultPosition, wxSize(900, 400));
	panel_main2->SetBackgroundColour(wxColor(255, 247, 247));

	panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1000, 100));
	panel_bottom->SetBackgroundColour(wxColor(132, 132, 132));


	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(panel_top, 0, wxEXPAND);
	sizer->Add(panel_mid, 0, wxEXPAND | wxALL, 1);
	sizer->Add(panel_main1, 1, wxEXPAND | wxALL, 1);
	sizer->Add(panel_bottom, 0, wxEXPAND);

	sizer_main = new wxBoxSizer(wxVERTICAL);
	sizer_centering = new wxBoxSizer(wxHORIZONTAL);
	sizer_centering->Add(panel_main2, 0, wxALIGN_CENTER);
	sizer_main->Add(sizer_centering, 1, wxALIGN_CENTER);

	text_numer_telefonu = new wxStaticText(panel_top, wxID_ANY, "+48 000 000 000", wxPoint(100, 8));
	text_numer_telefonu->SetForegroundColour(wxColor(255, 255, 255));


	//mid-------------------------------------------------------------------------------------
	text_nazwa = new wxStaticText(panel_mid, wxID_ANY, "Logowanie", wxPoint(20, 24));
	text_nazwa->SetFont(text_nazwa->GetFont().Scale(1.6));

	//main-------------------------------------------------------------------------------------
	text_static_login = new wxStaticText(panel_main2, wxID_ANY, "Wpisz login:", wxPoint(390, 40));
	text_ctrl_login = new wxTextCtrl(panel_main2, wxID_ANY, "Login", wxPoint(330, 70), wxSize(200, -1));

	text_static_haslo = new wxStaticText(panel_main2, wxID_ANY, "Wpisz haslo:", wxPoint(390, 120));
	text_ctrl_haslo = new wxTextCtrl(panel_main2, wxID_ANY, "Haslo", wxPoint(330, 150), wxSize(200, -1), wxTE_PASSWORD);

	button_zaloguj = new wxButton(panel_main2, wxID_ANY, "Zaloguj", wxPoint(390, 200), wxSize(90, 35));


	panel_main1->SetSizerAndFit(sizer_main);
	this->SetSizerAndFit(sizer);

}