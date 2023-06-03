#pragma once
#include<wx/wx.h>
#include <wx/hyperlink.h>

class Kontakt : public wxDialog
{
public:
	Kontakt(wxWindow* parent);
	void OnButtonClicked1(wxCommandEvent& event);
	void OnButtonClicked2(wxCommandEvent& event);
	void OnButtonClicked3(wxCommandEvent& event);
	void OnButtonClicked4(wxCommandEvent& event);
private:
	wxPanel* panel_top;
	wxPanel* panel_mid;
	wxPanel* panel_main1;
	wxPanel* panel_main2;
	wxPanel* panel_bottom;
	wxBoxSizer* sizer;
	wxBoxSizer* sizer_main;
	wxBoxSizer* sizer_centering;
	wxStaticText* text_numer_telefonu;
	wxStaticText* text_nazwa;
	wxStaticText* text_static_grupa;
	wxStaticText* text_static_nazwisko1;
	wxStaticText* text_static_nazwisko2;
	wxStaticText* text_static_nazwisko3;
	wxStaticText* text_static_nazwisko4;

	//przyciski linki
	wxButton* button_nazwisko1;
	wxButton* button_nazwisko2;
	wxButton* button_nazwisko3;
	wxButton* button_nazwisko4;
};
