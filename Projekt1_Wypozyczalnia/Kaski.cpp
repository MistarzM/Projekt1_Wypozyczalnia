#include "Kaski.h"

Kaski::Kaski(wxWindow* parent, int ID) : wxDialog(parent, wxID_ANY, "Kaski", wxDefaultPosition, wxSize(1000, 740)), ID(ID)
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

	text_nazwa = new wxStaticText(panel_mid, wxID_ANY, "Kaski", wxPoint(20, 24));
	text_nazwa->SetFont(text_nazwa->GetFont().Scale(1.6));

	//main_narty--------------------------------------------------------------------------------------------------------
	text_model_kask = new wxStaticText(panel_main2, wxID_ANY, "Model kasku", wxPoint(375, 40));
	text_model_kask->SetFont(text_model_kask->GetFont().Scale(1.3));

	choice_model_kask = new wxChoice(panel_main2, wxID_ANY, wxPoint(375, 70), wxSize(150, 30));
	choice_model_kask->Connect(wxEVT_CHOICE, wxCommandEventHandler(Kaski::OnChoiceValueChanged), nullptr, this);
	AddModelNart("Alpina Junta", 15.00);
	AddModelNart("Meteor HOLO", 20.00);
	AddModelNart("Atomic Savor Visor", 35.00);
	AddModelNart("Smith Z1M", 19.00);
	AddModelNart("K2 Thrive", 38.00);

	text_data_wypozyczenia = new wxStaticText(panel_main2, wxID_ANY, "Data wypozyczenia", wxPoint(675, 40));
	text_data_wypozyczenia->SetFont(text_data_wypozyczenia->GetFont().Scale(1.3));
	date_picker_wypozyczenia = new wxDatePickerCtrl(panel_main2, wxID_ANY, wxDefaultDateTime, wxPoint(675, 70), wxSize(150, 26), wxDP_DROPDOWN);
	wxDateTime Date = wxDateTime::Today();
	Date.Add(wxDateSpan::Months(1));
	date_picker_wypozyczenia->SetRange(wxDateTime::Today(), Date);

	text_ilosc_dni = new wxStaticText(panel_main2, wxID_ANY, "Ilosc dni", wxPoint(375, 160));
	text_ilosc_dni->SetFont(text_ilosc_dni->GetFont().Scale(1.3));
	//=============================================================================================================
	spin_ctrl_dni = new wxSpinCtrl(panel_main2, wxID_ANY, wxT("0"), wxPoint(375, 190), wxSize(150, 23));
	spin_ctrl_dni->Connect(wxEVT_SPINCTRL, wxSpinEventHandler(Kaski::OnSpinCtrlValueChanged), nullptr, this);

	text_cena = new wxStaticText(panel_mid, wxID_ANY, "Cena", wxPoint(800, 24));
	text_cena->SetFont(text_cena->GetFont().Scale(1.6));

	text_string_cena = new wxStaticText(panel_mid, wxID_ANY, string_cena, wxPoint(880, 24));
	text_string_cena->SetFont(text_string_cena->GetFont().Scale(1.6));

	//=============================================================================================================
	text_rozmiar_kasku = new wxStaticText(panel_main2, wxID_ANY, "Rozmiar kasku", wxPoint(675, 160));
	text_rozmiar_kasku->SetFont(text_rozmiar_kasku->GetFont().Scale(1.3));
	wxArrayString rozmiar_kasku;
	rozmiar_kasku.Add("XS");
	rozmiar_kasku.Add("S");
	rozmiar_kasku.Add("M");
	rozmiar_kasku.Add("L");
	rozmiar_kasku.Add("XL");
	choice_rozmiar_kasku = new wxChoice(panel_main2, wxID_ANY, wxPoint(675, 190), wxSize(150, 30), rozmiar_kasku);

	text_wzrost = new wxStaticText(panel_main2, wxID_ANY, "Wyjmowalna wyœció³ka", wxPoint(375, 260));
	text_wzrost->SetFont(text_wzrost->GetFont().Scale(1.3));
	wxArrayString wzrost;
	wzrost.Add("Tak");
	wzrost.Add("Nie");
	choice_wzrost = new wxChoice(panel_main2, wxID_ANY, wxPoint(375, 290), wxSize(150, 30), wzrost);

	text_waga = new wxStaticText(panel_main2, wxID_ANY, "Antyalergiczna wyœció³ka", wxPoint(675, 260));
	text_waga->SetFont(text_waga->GetFont().Scale(1.3));
	wxArrayString waga;
	waga.Add("Tak");
	waga.Add("Nie");

	choice_waga = new wxChoice(panel_main2, wxID_ANY, wxPoint(675, 290), wxSize(150, 30), waga);


	//main_narty_end----------------------------------------------------------------------------------------------------
	button_dalej = new wxButton(panel_bottom, wxID_ANY, "Dalej", wxPoint(800, 29), wxSize(100, 40));
	button_dalej->SetBackgroundColour(wxColor(132, 132, 132));
	button_dalej->SetForegroundColour(wxColor(255, 255, 255));
	button_dalej->Bind(wxEVT_BUTTON, &Kaski::OnButtonDalej, this);

	panel_main1->SetSizerAndFit(sizer_main);
	this->SetSizerAndFit(sizer);
}
void Kaski::AddModelNart(wxString firma, double cena)
{
	if (choice_model_kask)
	{
		choice_model_kask->Append(firma);
		prices[firma] = cena;
	}
}

double Kaski::cena_wypozyczenia(int value)
{
	double cena_wypozyczenia = 0.0;
	wxString wybrany = choice_model_kask->GetStringSelection();
	for (int i = 0; i < value; i++)
	{
		cena_wypozyczenia += prices[wybrany];
	}
	return cena_wypozyczenia;
}

void Kaski::OnSpinCtrlValueChanged(wxSpinEvent& event)
{
	int value = event.GetPosition();
	double cena_pierwsza = cena_wypozyczenia(value);


	int precision = 2;
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << cena_pierwsza;

	string_cena = oss.str() + " PLN";

	text_string_cena->SetLabel(string_cena);
}

void Kaski::OnChoiceValueChanged(wxCommandEvent& event)
{
	int value = spin_ctrl_dni->GetValue();
	double cena_pierwsza = cena_wypozyczenia(value);
	OnPodgladModelu(event);

	int precision = 2;
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << cena_pierwsza;

	string_cena = oss.str() + " PLN";

	text_string_cena->SetLabel(string_cena);
}

void Kaski::OnPodgladModelu(wxCommandEvent& event)
{
	if (bitmap_image)
	{
		bitmap_image->Destroy();
		bitmap_image = nullptr;
	}
	wxString numer_zdj = choice_model_kask->GetStringSelection();
	panel_zdj = new wxPanel(panel_main2, wxID_ANY, wxPoint(10, 20), wxSize(350, 350));

	// wgranie zdj==================================================================
	wxInitAllImageHandlers();

	wxString imagePath;
	if (numer_zdj == "Alpina Junta")
	{
		imagePath = wxT("zdj/kaski_zdj/kask1.jpg");
	}
	else if (numer_zdj == "Meteor HOLO")
	{
		imagePath = wxT("zdj/kaski_zdj/kask2.jpg");
	}
	else if (numer_zdj == "Atomic Savor Visor")
	{
		imagePath = wxT("zdj/kaski_zdj/kask3.jpg");
	}
	else if (numer_zdj == "Smith Z1M")
	{
		imagePath = wxT("zdj/kaski_zdj/kask4.jpg");
	}
	else
	{
		imagePath = wxT("zdj/kaski_zdj/kask5.jpg");
	}

	if (!imagePath.IsEmpty())
	{
		wxImage image(imagePath);
		if (image.IsOk())
		{
			wxSize panel_size = panel_zdj->GetSize();
			wxImage scaled_image = image.Scale(panel_size.GetWidth(), panel_size.GetHeight(), wxIMAGE_QUALITY_HIGH);
			wxBitmap bitmap(scaled_image);
			bitmap_image = new wxStaticBitmap(panel_zdj, wxID_ANY, bitmap, wxDefaultPosition);
		}
	}
}

void Kaski::OnButtonDalej(wxCommandEvent& event)
{
	wxString model = choice_model_kask->GetStringSelection();
	int dni = spin_ctrl_dni->GetValue();
	wxString rozmiar_buta = choice_rozmiar_kasku->GetStringSelection();
	wxString wzrost = choice_wzrost->GetStringSelection();
	wxString waga = choice_waga->GetStringSelection();
	if (model == "" || dni == 0 || rozmiar_buta == "" || wzrost == "" || waga == "")
	{
		wxMessageBox("Nie wybrano", "Error", wxOK | wxICON_ERROR);
	}
	else
	{
		//pobranie ceny
		int cena_int = spin_ctrl_dni->GetValue();
		double cena_wys = cena_wypozyczenia(cena_int);
		//wys³anie ceny do formularza
		payment_kask = new Payment(this, cena_wys, ID);
		OnDalej(ID, cena_wys);
		payment_kask->ShowModal();
		payment_kask->Destroy();
	}
}

void Kaski::OnDalej(int id_produkt, double cena_produkt)
{
	wxString model = choice_model_kask->GetStringSelection();
	wxDateTime data = date_picker_wypozyczenia->GetValue();
	int dni = spin_ctrl_dni->GetValue();
	wxString rozmiar_buta = choice_rozmiar_kasku->GetStringSelection();
	wxString wzrost = choice_wzrost->GetStringSelection();
	wxString waga = choice_waga->GetStringSelection();


	std::ofstream outputFile(wxT("baza_danych/zamowienia_kaski.txt"));

	if (outputFile.is_open())
	{
		outputFile << "ID zamowienia: #" << id_produkt << std::endl;
		outputFile << "Cena: " << cena_produkt << std::endl;
		outputFile << "Model: " << model << std::endl;
		outputFile << "Data wypozyczenia: " << data.FormatISODate() << std::endl;
		outputFile << "Czas wypozyczenia: " << dni << " dni" << std::endl;
		outputFile << "Rozmiar buta: " << rozmiar_buta << std::endl;
		outputFile << "Wyjmowalna wyœció³ka: " << wzrost << std::endl;
		outputFile << "Antyalergiczna wyœci³ka: " << waga << std::endl;
		outputFile.close();
	}
	else
	{
		wxMessageBox("Error: Unable to open the file for writing.", "Error", wxOK | wxICON_ERROR);
	}
	EndModal(wxID_OK);
}


wxBEGIN_EVENT_TABLE(Kaski, wxDialog)
EVT_BUTTON(wxID_ANY, Kaski::OnButtonDalej)
wxEND_EVENT_TABLE()
