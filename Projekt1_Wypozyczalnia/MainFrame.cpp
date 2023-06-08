#include "MainFrame.h"


MainFrame::MainFrame(const wxString& site, const wxPoint& position, const wxSize& size) : wxFrame(nullptr, wxID_ANY, site, position, size)
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

	//top--------------------------------------------------------------------------------------
	text_numer_telefonu = new wxStaticText(panel_top, wxID_ANY, "+48 000 000 000", wxPoint(100, 8));
	text_numer_telefonu->SetForegroundColour(wxColor(255, 255, 255));

	button_logowanie = new wxButton(panel_top, wxID_ANY, "Logowanie", wxPoint(790, 0), wxSize(100, 30));
	button_logowanie->SetBackgroundColour(wxColor(132, 132, 132));
	button_logowanie->SetForegroundColour(wxColor(255, 255, 255));
	button_logowanie->Bind(wxEVT_BUTTON, &MainFrame::OnLogowanie, this);

	button_rejestracja = new wxButton(panel_top, wxID_ANY, "Rejestracja", wxPoint(890, 0), wxSize(100, 30));
	button_rejestracja->SetBackgroundColour(wxColor(132, 132, 132));
	button_rejestracja->SetForegroundColour(wxColor(255, 255, 255));
	button_rejestracja->Bind(wxEVT_BUTTON, &MainFrame::OnRejestracja, this);

	//mid--------------------------------------------------------------------------------------
	text_nazwa = new wxStaticText(panel_mid, wxID_ANY, "SkiProject", wxPoint(18, 10));
	text_nazwa->SetFont(text_nazwa->GetFont().Scale(1.6));

	button_narty = new wxButton(panel_mid, wxID_ANY, "Narty", wxPoint(45, 60), wxSize(100, 34));
	button_narty->Bind(wxEVT_BUTTON, &MainFrame::OnNarty, this);
	button_buty_narciarskie = new wxButton(panel_mid, wxID_ANY, "Buty narciarskie", wxPoint(180, 60), wxSize(100, 34));
	button_buty_narciarskie->Bind(wxEVT_BUTTON, &MainFrame::OnButyNarciarskie, this);
	button_snowboard = new wxButton(panel_mid, wxID_ANY, "Snowboard", wxPoint(315, 60), wxSize(100, 34));
	button_snowboard->Bind(wxEVT_BUTTON, &MainFrame::OnSnowboard, this);
	button_kaski = new wxButton(panel_mid, wxID_ANY, "Kaski", wxPoint(450, 60), wxSize(100, 34));
	button_kaski->Bind(wxEVT_BUTTON, &MainFrame::OnKaski, this);
	button_akcesoria = new wxButton(panel_mid, wxID_ANY, "Akcesoria", wxPoint(585, 60), wxSize(100, 34));
	button_akcesoria->Bind(wxEVT_BUTTON, &MainFrame::OnAkcesoria, this);
	button_galeria = new wxButton(panel_mid, wxID_ANY, "Galeria", wxPoint(720, 60), wxSize(100, 34));
	button_galeria->Bind(wxEVT_BUTTON, &MainFrame::OnGaleria, this);
	button_kontakt = new wxButton(panel_mid, wxID_ANY, "Kontakt", wxPoint(855, 60), wxSize(100, 34));
	button_kontakt->Bind(wxEVT_BUTTON, &MainFrame::OnKontakt, this);

	//main-------------------------------------------------------------------------------------
	text_wypozyczalnia = new wxStaticText(panel_main1, wxID_ANY, "Og³oszenia", wxPoint(10, 10));
	text_wypozyczalnia->SetFont(text_wypozyczalnia->GetFont().Scale(1.8));									//set_size
																											//opis

	ReadTextFromFile();																						//funkcja czytaj¹ca dane 
	//bottom-----------------------------------------------------------------------------------




	//SetSizerAndFit---------------------------------------------------------------------------
	panel_main1->SetSizerAndFit(sizer_main);
	this->SetSizerAndFit(sizer);
}

//Funkcje_top_definicje------------------------------------------------------------------------
void MainFrame::OnLogowanie(wxCommandEvent& event)
{
	Logowanie* ClickLogowanie = new Logowanie(this);
	ClickLogowanie->ShowModal();
	ClickLogowanie->Destroy();
}
void MainFrame::OnRejestracja(wxCommandEvent& event)
{
	Rejestracja* ClickRejestracja = new Rejestracja(this);
	ClickRejestracja->ShowModal();
	ClickRejestracja->Destroy();
}

//Funkcje_mid_definicje------------------------------------------------------------------------
void MainFrame::OnNarty(wxCommandEvent& event)
{
	Narty* ClickNarty = new Narty(this, ID);
	ChangeID(ID);
	ClickNarty->ShowModal();
	ClickNarty->Destroy();
}
void MainFrame::OnButyNarciarskie(wxCommandEvent& event)
{
	ButyNarciarskie* ClickButyNarciarskie = new ButyNarciarskie(this, ID);
	ChangeID(ID);
	ClickButyNarciarskie->ShowModal();
	ClickButyNarciarskie->Destroy();

}
void MainFrame::OnSnowboard(wxCommandEvent& event)
{
	Snowboard* ClickSnowboard = new Snowboard(this, ID);
	ChangeID(ID);
	ClickSnowboard->ShowModal();
	ClickSnowboard->Destroy();
}
void MainFrame::OnKaski(wxCommandEvent& event)
{
	Kaski* ClickKaski = new Kaski(this, ID);
	ChangeID(ID);
	ClickKaski->ShowModal();
	ClickKaski->Destroy();
}
void MainFrame::OnAkcesoria(wxCommandEvent& event)
{
	Akcesoria* ClickAkcesoria = new Akcesoria(this, ID);
	ChangeID(ID);
	ClickAkcesoria->ShowModal();
	ClickAkcesoria->Destroy();
}
void MainFrame::OnGaleria(wxCommandEvent& event)
{
	Galeria* ClickGaleria = new Galeria(this);
	ClickGaleria->ShowModal();
	ClickGaleria->Destroy();
}
void MainFrame::OnKontakt(wxCommandEvent& event)
{
	Kontakt* ClickKontakt = new Kontakt(this);
	ClickKontakt->ShowModal();
	ClickKontakt->Destroy();
}
//ID zmiana
void MainFrame::ChangeID(int& id)
{
	id++;
}
void MainFrame::ReadTextFromFile()
{
	std::ifstream file(wxT("baza_danych/main_wpisy.txt"));
	if (!file.is_open())
	{
		wxMessageBox("Failed to open the file.", "Error", wxOK | wxICON_ERROR);
		return;
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string fileContents = buffer.str();

	file.close();

	size_t newlinePos = fileContents.find('\n');

	std::string firstLine = fileContents.substr(0, newlinePos);
	std::string restOfText = fileContents.substr(newlinePos + 1);

	text_main_title = new wxStaticText(panel_main2, wxID_ANY, wxString(firstLine), wxPoint(30,30), wxDefaultSize, wxALIGN_LEFT);
	text_main_title->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	text_main_content = new wxStaticText(panel_main2, wxID_ANY, wxString(restOfText), wxPoint(30, 70), wxDefaultSize, wxALIGN_LEFT);
	text_main_content->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT));

}