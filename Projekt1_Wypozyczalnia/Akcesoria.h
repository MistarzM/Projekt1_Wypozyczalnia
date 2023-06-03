#pragma once
#include<wx/wx.h>
#include<wx/spinctrl.h>
#include<string>
#include<wx/choice.h>
#include<wx/datectrl.h>
#include<wx/button.h>
#include <map>
#include<iomanip>
#include <sstream>
#include "Payment.h"
#include <fstream>




class Akcesoria : public wxDialog
{
public:
	Akcesoria(wxWindow* parent, int ID);
	void AddModelNart(wxString firma, double cena);
	double cena_wypozyczenia(int cena);
	void OnPodgladModelu(wxCommandEvent& event);
	void OnChoiceValueChanged(wxCommandEvent& event);
	void OnSpinCtrlValueChanged(wxSpinEvent& event);
	void OnButtonDalej(wxCommandEvent& event);
	void OnDalej(int id_produkt, double cena_produkt);
	wxDECLARE_EVENT_TABLE();
private:
	int ID;
	wxPanel* panel_top;
	wxPanel* panel_mid;
	wxPanel* panel_main1;
	wxPanel* panel_main2;
	wxPanel* panel_bottom;
	wxPanel* panel_zdj;

	wxBoxSizer* sizer;
	wxBoxSizer* sizer_main;
	wxBoxSizer* sizer_centering;

	wxStaticText* text_numer_telefonu;
	wxStaticText* text_nazwa;
	wxStaticText* text_model_akcesoria;
	wxStaticText* text_cena;
	wxStaticText* text_string_cena;
	wxStaticText* text_data_wypozyczenia;
	wxStaticText* text_ilosc_dni;
	wxStaticText* text_rozmiar_buta;
	wxStaticText* text_wzrost;
	wxStaticText* text_waga;

	wxDatePickerCtrl* date_picker_wypozyczenia;

	wxChoice* choice_model_akcesoria;
	wxChoice* choice_rozmiar_buta;
	wxChoice* choice_wzrost;
	wxChoice* choice_waga;

	wxSpinCtrl* spin_ctrl_dni;
	std::map<wxString, double> prices;
	std::string string_cena;
	wxStaticBitmap* bitmap_image;
	wxButton* button_dalej;
	Payment* payment_akcesoria;

};

