#include "Payment.h"

Payment::Payment(wxWindow* parent, double total, int id) : wxDialog(parent, wxID_ANY, "Platnosc Narty", wxDefaultPosition, wxDefaultSize), total(total), id(id)
{
	panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(450, 25));
	panel_top->SetBackgroundColour(wxColor(132, 132, 132));

	panel_mid = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(450, 50));
	panel_mid->SetBackgroundColour(wxColor(252, 252, 252));

	panel_main1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(450, 500));
	panel_main1->SetBackgroundColour(wxColor(247, 240, 247));

	panel_main2 = new wxPanel(panel_main1, wxID_ANY, wxDefaultPosition, wxSize(350, 300));
	panel_main2->SetBackgroundColour(wxColor(255, 247, 247));

	panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(450, 40));
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

	text_nazwa = new wxStaticText(panel_mid, wxID_ANY, "Dane", wxPoint(20, 10));
	text_nazwa->SetFont(text_nazwa->GetFont().Scale(1.6));


	text_imie = new wxStaticText(panel_main2, wxID_ANY, "Imie", wxPoint(40, 20));
	text_ctrl_imie = new wxTextCtrl(panel_main2, wxID_ANY, "", wxPoint(140, 15), wxSize(170, -1));
	text_nazwisko = new wxStaticText(panel_main2, wxID_ANY, "Nazwisko", wxPoint(40, 60));
	text_ctrl_nazwisko = new wxTextCtrl(panel_main2, wxID_ANY, "", wxPoint(140, 55), wxSize(170, -1));
	text_numer_telefonu = new wxStaticText(panel_main2, wxID_ANY, "Numer telefonu", wxPoint(40, 100));
	text_ctrl_numer_telefonu = new wxTextCtrl(panel_main2, wxID_ANY, "+48 ", wxPoint(140, 95), wxSize(170, -1));


	text_cena = new wxStaticText(panel_mid, wxID_ANY, wxString::Format("Cena: %.2f PLN", total), wxPoint(280, 10));
	text_cena->SetFont(text_cena->GetFont().Scale(1.6));

	wxString wybory[] = { "Gotowka", "Karta", "BLIK", "PayPal" };
	metoda_platnosci = new wxRadioBox(panel_main2, wxID_ANY, "Metoda Platnosci", wxPoint(30, 140), wxSize(285, 140), WXSIZEOF(wybory), wybory, 1);

	button_potwierdz = new wxButton(panel_bottom, wxID_ANY, "Potwierdz", wxPoint(300, 5), wxSize(100, 30));
	button_potwierdz->SetBackgroundColour(wxColor(132, 132, 132));
	button_potwierdz->SetForegroundColour(wxColor(255, 255, 255));

	panel_main1->SetSizerAndFit(sizer_main);
	this->SetSizerAndFit(sizer);
}
void Payment::OnPotwierdz(wxCommandEvent& event)
{
	wxString imie = text_ctrl_imie->GetValue();
	wxString nazwisko = text_ctrl_nazwisko->GetValue();
	wxString numer_telefonu = text_ctrl_numer_telefonu->GetValue();
	double cena = this->total;
	wxString metoda = metoda_platnosci->GetStringSelection();

	std::ofstream outputFile("C:/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/baza_danych/payment.txt");

	if (outputFile.is_open())
	{
		outputFile << "ID klienta: #" << id << std::endl;
		outputFile << "Imie: " << imie << std::endl;
		outputFile << "Nazwisko: " << nazwisko << std::endl;
		outputFile << "Numer telefonu: " << numer_telefonu << std::endl;
		outputFile << "Cena: " << cena << " PLN" << std::endl;
		outputFile << "Metoda platnosci: " << metoda << std::endl;
		outputFile.close();
	}
	else
	{
		wxMessageBox("Error: Unable to open the file for writing.", "Error", wxOK | wxICON_ERROR);
	}
	EndModal(wxID_OK);
}


wxBEGIN_EVENT_TABLE(Payment, wxDialog)
EVT_BUTTON(wxID_ANY, Payment::OnPotwierdz)
wxEND_EVENT_TABLE()