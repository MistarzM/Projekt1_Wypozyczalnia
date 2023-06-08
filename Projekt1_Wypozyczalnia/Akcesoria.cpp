#include "Akcesoria.h"

Akcesoria::Akcesoria(wxWindow* parent, int ID) : wxDialog(parent, wxID_ANY, "Akcesoria", wxDefaultPosition, wxSize(1000, 740)), ID(ID)
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

	text_nazwa = new wxStaticText(panel_mid, wxID_ANY, "Akcesoria", wxPoint(20, 24));
	text_nazwa->SetFont(text_nazwa->GetFont().Scale(1.6));

	//main_narty--------------------------------------------------------------------------------------------------------
	text_model_akcesoria = new wxStaticText(panel_main2, wxID_ANY, "Model kijków", wxPoint(375, 40));
	text_model_akcesoria->SetFont(text_model_akcesoria->GetFont().Scale(1.3));

	choice_model_akcesoria = new wxChoice(panel_main2, wxID_ANY, wxPoint(375, 70), wxSize(150, 30));
	choice_model_akcesoria->Connect(wxEVT_CHOICE, wxCommandEventHandler(Akcesoria::OnChoiceValueChanged), nullptr, this);
	AddModelNart("Head Multi S", 30.00);
	AddModelNart("Atomic Park", 20.00);
	AddModelNart("Rossignol Tactic M", 36.00);
	AddModelNart("Salomon Icon Ergo S3", 40.00);
	AddModelNart("McKinley Safine C", 28.00);

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
	spin_ctrl_dni->Connect(wxEVT_SPINCTRL, wxSpinEventHandler(Akcesoria::OnSpinCtrlValueChanged), nullptr, this);

	text_cena = new wxStaticText(panel_mid, wxID_ANY, "Cena", wxPoint(800, 24));
	text_cena->SetFont(text_cena->GetFont().Scale(1.6));

	text_string_cena = new wxStaticText(panel_mid, wxID_ANY, string_cena, wxPoint(880, 24));
	text_string_cena->SetFont(text_string_cena->GetFont().Scale(1.6));

	//=============================================================================================================
	text_rozmiar_buta = new wxStaticText(panel_main2, wxID_ANY, "D³ugoœæ kijka", wxPoint(675, 160));
	text_rozmiar_buta->SetFont(text_rozmiar_buta->GetFont().Scale(1.3));
	wxArrayString rozmiar_buta;
	for (int i = 70; i < 145; i+=5)
	{
		std::string b = std::to_string(i);
		rozmiar_buta.Add(b);
	}
	choice_rozmiar_buta = new wxChoice(panel_main2, wxID_ANY, wxPoint(675, 190), wxSize(150, 30), rozmiar_buta);

	text_wzrost = new wxStaticText(panel_main2, wxID_ANY, "Przeznaczenie", wxPoint(375, 260));
	text_wzrost->SetFont(text_wzrost->GetFont().Scale(1.3));
	wxArrayString wzrost;
	wzrost.Add("Kijki biegowe");
	wzrost.Add("Kijki zjazdowe");
	wzrost.Add("Kijki skitouring-owe");
	wzrost.Add("Kijki do slalomu");

	choice_wzrost = new wxChoice(panel_main2, wxID_ANY, wxPoint(375, 290), wxSize(150, 30), wzrost);

	text_waga = new wxStaticText(panel_main2, wxID_ANY, "Rozmiar uchwytu", wxPoint(675, 260));
	text_waga->SetFont(text_waga->GetFont().Scale(1.3));
	wxArrayString waga;
	waga.Add("Ma³y");
	waga.Add("Œredni");
	waga.Add("Du¿y");
	choice_waga = new wxChoice(panel_main2, wxID_ANY, wxPoint(675, 290), wxSize(150, 30), waga);


	//main_narty_end----------------------------------------------------------------------------------------------------
	button_dalej = new wxButton(panel_bottom, wxID_ANY, "Dalej", wxPoint(800, 29), wxSize(100, 40));
	button_dalej->SetBackgroundColour(wxColor(132, 132, 132));
	button_dalej->SetForegroundColour(wxColor(255, 255, 255));
	button_dalej->Bind(wxEVT_BUTTON, &Akcesoria::OnButtonDalej, this);

	panel_main1->SetSizerAndFit(sizer_main);
	this->SetSizerAndFit(sizer);
}

void Akcesoria::AddModelNart(wxString firma, double cena)
{
	if (choice_model_akcesoria)
	{
		choice_model_akcesoria->Append(firma);
		prices[firma] = cena;
	}
}

double Akcesoria::cena_wypozyczenia(int value)
{
	double cena_wypozyczenia = 0.0;
	wxString wybrany = choice_model_akcesoria->GetStringSelection();
	for (int i = 0; i < value; i++)
	{
		cena_wypozyczenia += prices[wybrany];
	}
	return cena_wypozyczenia;
}

void Akcesoria::OnSpinCtrlValueChanged(wxSpinEvent& event)
{
	int value = event.GetPosition();
	double cena_pierwsza = cena_wypozyczenia(value);


	int precision = 2;
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(precision) << cena_pierwsza;

	string_cena = oss.str() + " PLN";

	text_string_cena->SetLabel(string_cena);
}

void Akcesoria::OnChoiceValueChanged(wxCommandEvent& event)
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

void Akcesoria::OnPodgladModelu(wxCommandEvent& event)
{
	if (bitmap_image)
	{
		bitmap_image->Destroy();
		bitmap_image = nullptr;
	}
	wxString numer_zdj = choice_model_akcesoria->GetStringSelection();
	panel_zdj = new wxPanel(panel_main2, wxID_ANY, wxPoint(10, 20), wxSize(350, 350));

	// wgranie zdj==================================================================
	wxInitAllImageHandlers();

	wxString imagePath;
	if (numer_zdj == "Head Multi S")
	{
		imagePath = wxT("zdj/akcesoria_zdj/akcesoria1.jpg");
	}
	else if (numer_zdj == "Atomic Park")
	{
		imagePath = wxT("zdj/akcesoria_zdj/akcesoria2.jpg");
	}
	else if (numer_zdj == "Rossignol Tactic M")
	{
		imagePath = wxT("zdj/akcesoria_zdj/akcesoria3.jpg");
	}
	else if (numer_zdj == "Salomon Icon Ergo S3")
	{
		imagePath = wxT("zdj/akcesoria_zdj/akcesoria4.jpg");
	}
	else
	{
		imagePath = wxT("zdj/akcesoria_zdj/akcesoria5.jpg");
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

void Akcesoria::OnButtonDalej(wxCommandEvent& event)
{
	wxString model = choice_model_akcesoria->GetStringSelection();
	int dni = spin_ctrl_dni->GetValue();
	wxString rozmiar_buta = choice_rozmiar_buta->GetStringSelection();
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
		payment_akcesoria = new Payment(this, cena_wys, ID);
		OnDalej(ID, cena_wys);
		payment_akcesoria->ShowModal();
		payment_akcesoria->Destroy();
	}
}

void Akcesoria::OnDalej(int id_produkt, double cena_produkt)
{
	wxString model = choice_model_akcesoria->GetStringSelection();
	wxDateTime data = date_picker_wypozyczenia->GetValue();
	int dni = spin_ctrl_dni->GetValue();
	wxString rozmiar_buta = choice_rozmiar_buta->GetStringSelection();
	wxString wzrost = choice_wzrost->GetStringSelection();
	wxString waga = choice_waga->GetStringSelection();


	std::ofstream outputFile(wxT("baza_danych/zamowienia_akcesoria.txt"));

	if (outputFile.is_open())
	{
		outputFile << "ID zamowienia: #" << id_produkt << std::endl;
		outputFile << "Cena: " << cena_produkt << std::endl;
		outputFile << "Model: " << model << std::endl;
		outputFile << "Data wypozyczenia: " << data.FormatISODate() << std::endl;
		outputFile << "Czas wypozyczenia: " << dni << " dni" << std::endl;
		outputFile << "D³ugoœæ kijka: " << rozmiar_buta << std::endl;
		outputFile << "Przeznaczenie: " << wzrost << std::endl;
		outputFile << "Rozmiar uchwytu: " << waga << std::endl;
		outputFile.close();
	}
	else
	{
		wxMessageBox("Error: Unable to open the file for writing.", "Error", wxOK | wxICON_ERROR);
	}
	EndModal(wxID_OK);
}


wxBEGIN_EVENT_TABLE(Akcesoria, wxDialog)
EVT_BUTTON(wxID_ANY, Akcesoria::OnButtonDalej)
wxEND_EVENT_TABLE()
