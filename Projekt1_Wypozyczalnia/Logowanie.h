#pragma once
#include<wx/wx.h>

class Logowanie : public wxDialog
{
public:
	Logowanie(wxWindow* parent);
private:
	wxPanel* panel_top;
	wxPanel* panel_mid;
	wxPanel* panel_main1;
	wxPanel* panel_main2;
	wxPanel* panel_bottom;

	wxBoxSizer* sizer;
	wxBoxSizer* sizer_main;
	wxBoxSizer* sizer_centering;
	wxButton* button_zaloguj;

	wxStaticText* text_numer_telefonu;
	wxStaticText* text_nazwa;
	wxStaticText* text_static_login;
	wxStaticText* text_static_haslo;

	wxTextCtrl* text_ctrl_login;
	wxTextCtrl* text_ctrl_haslo;
};

