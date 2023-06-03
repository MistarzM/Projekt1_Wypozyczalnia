#pragma once
#include<wx/wx.h>
#include <fstream>


class Payment : public wxDialog
{
public:
	Payment(wxWindow* parent, double total, int id);
private:
	double total;
	int id;
	wxPanel* panel_top;
	wxPanel* panel_mid;
	wxPanel* panel_main1;
	wxPanel* panel_main2;
	wxPanel* panel_bottom;
	wxBoxSizer* sizer;
	wxBoxSizer* sizer_main;
	wxBoxSizer* sizer_centering;
	wxStaticText* text_cena;
	wxRadioBox* metoda_platnosci;
	wxStaticText* text_nazwa;
	wxStaticText* text_imie;
	wxTextCtrl* text_ctrl_imie;
	wxStaticText* text_nazwisko;
	wxTextCtrl* text_ctrl_nazwisko;
	wxStaticText* text_numer_telefonu;
	wxTextCtrl* text_ctrl_numer_telefonu;
	wxButton* button_potwierdz;
	void OnPotwierdz(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
