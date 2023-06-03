#include "Kontakt.h"

Kontakt::Kontakt(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Narty", wxDefaultPosition, wxSize(1000, 740))
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

	text_nazwa = new wxStaticText(panel_mid, wxID_ANY, "Kontakt", wxPoint(20, 24));
	text_nazwa->SetFont(text_nazwa->GetFont().Scale(1.6));
	//main----------------------------------------------
	text_static_grupa = new wxStaticText(panel_main2, wxID_ANY, "Sk³ad grupy:", wxPoint(240, 40));
	text_static_grupa->SetFont(text_static_grupa->GetFont().Scale(1.6));

	text_static_nazwisko1 = new wxStaticText(panel_main2, wxID_ANY, "Micha³ Mistarz", wxPoint(280, 90));
	text_static_nazwisko1->SetFont(text_static_nazwisko1->GetFont().Scale(1.4));
	button_nazwisko1 = new wxButton(panel_main2, wxID_ANY, "GitHub", wxPoint(440, 85), wxSize(90, 35));
	button_nazwisko1->SetFont(button_nazwisko1->GetFont().Scale(1.4));
	button_nazwisko1->Bind(wxEVT_BUTTON, &Kontakt::OnButtonClicked1, this);

	text_static_nazwisko2 = new wxStaticText(panel_main2, wxID_ANY, "Arkadiusz Wanat", wxPoint(280, 140));
	text_static_nazwisko2->SetFont(text_static_nazwisko2->GetFont().Scale(1.4));
	button_nazwisko2 = new wxButton(panel_main2, wxID_ANY, "GitHub", wxPoint(440, 135), wxSize(90, 35));
	button_nazwisko2->SetFont(button_nazwisko2->GetFont().Scale(1.4));
	button_nazwisko2->Bind(wxEVT_BUTTON, &Kontakt::OnButtonClicked2, this);

	text_static_nazwisko3 = new wxStaticText(panel_main2, wxID_ANY, "Szymon Mazurek", wxPoint(280, 190));
	text_static_nazwisko3->SetFont(text_static_nazwisko3->GetFont().Scale(1.4));
	button_nazwisko3 = new wxButton(panel_main2, wxID_ANY, "GitHub", wxPoint(440, 185), wxSize(90, 35));
	button_nazwisko3->SetFont(button_nazwisko3->GetFont().Scale(1.4));
	button_nazwisko3->Bind(wxEVT_BUTTON, &Kontakt::OnButtonClicked3, this);

	text_static_nazwisko4 = new wxStaticText(panel_main2, wxID_ANY, "Patryk Wróblewski", wxPoint(280, 240));
	text_static_nazwisko4->SetFont(text_static_nazwisko4->GetFont().Scale(1.4));
	button_nazwisko4 = new wxButton(panel_main2, wxID_ANY, "GitHub", wxPoint(440, 235), wxSize(90, 35));
	button_nazwisko4->SetFont(button_nazwisko4->GetFont().Scale(1.4));
	button_nazwisko4->Bind(wxEVT_BUTTON, &Kontakt::OnButtonClicked4, this);

	

	panel_main1->SetSizerAndFit(sizer_main);
	this->SetSizerAndFit(sizer);
}

void Kontakt::OnButtonClicked1(wxCommandEvent& event)
{
	wxString url = "https://github.com/MistarzM";
	wxLaunchDefaultBrowser(url);
}
void Kontakt::OnButtonClicked2(wxCommandEvent& event)
{
	wxString url = "https://github.com/acadiuss";
	wxLaunchDefaultBrowser(url);
}
void Kontakt::OnButtonClicked3(wxCommandEvent& event)
{
	wxString url = "https://github.com/szymonmazurek";
	wxLaunchDefaultBrowser(url);
}
void Kontakt::OnButtonClicked4(wxCommandEvent& event)
{
	wxString url = "https://github.com/Patryk2001k";
	wxLaunchDefaultBrowser(url);
}