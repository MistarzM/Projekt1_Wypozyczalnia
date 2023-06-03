#pragma once
#include<wx/wx.h>
#include"Narty.h"
#include"ButyNarciarskie.h"
#include"Snowboard.h"
#include"Kaski.h"
#include"Akcesoria.h"
#include"Galeria.h"
#include"Kontakt.h"
#include"Logowanie.h"
#include"Rejestracja.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& site, const wxPoint& position, const wxSize& size);
	//top_deklaracja_funkcji-----------------------------------------------------------------------------
	void OnLogowanie(wxCommandEvent& event);
	void OnRejestracja(wxCommandEvent& event);

	//mid_deklaracja_funkcji-----------------------------------------------------------------------------
	void OnNarty(wxCommandEvent& event);
	void OnButyNarciarskie(wxCommandEvent& event);
	void OnSnowboard(wxCommandEvent& event);
	void OnKaski(wxCommandEvent& event);
	void OnAkcesoria(wxCommandEvent& event);
	void OnGaleria(wxCommandEvent& event);
	void OnKontakt(wxCommandEvent& event);
	void ChangeID(int& id);
private:
	int ID = 1000; //ID 

	wxBoxSizer* sizer;
	wxBoxSizer* sizer_main;
	wxBoxSizer* sizer_centering;

	wxButton* button_logowanie;
	wxButton* button_rejestracja;
	wxButton* button_narty;
	wxButton* button_buty_narciarskie;
	wxButton* button_snowboard;
	wxButton* button_kaski;
	wxButton* button_akcesoria;
	wxButton* button_galeria;
	wxButton* button_kontakt;

	wxPanel* panel_top;
	wxPanel* panel_mid;
	wxPanel* panel_main1;
	wxPanel* panel_main2;
	wxPanel* panel_bottom;

	wxStaticText* text_numer_telefonu;
	wxStaticText* text_nazwa;
	wxStaticText* text_wypozyczalnia;
};

