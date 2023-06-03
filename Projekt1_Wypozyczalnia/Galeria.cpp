#include "Galeria.h"
Galeria::Galeria(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Galeria", wxDefaultPosition, wxSize(1000, 740))
{
	wxInitAllImageHandlers();
	auto gallery = new GaleriaZdjec(this);

	wxImage image1(wxT("zdj/galeria_zdj/galeria1.jpg"));
	wxImage image2(wxT("zdj/galeria_zdj/galeria2.jpg"));
	wxImage image3(wxT("zdj/galeria_zdj/galeria3.jpg"));
	wxImage image4(wxT("zdj/galeria_zdj/galeria4.jpg"));
	wxImage image5(wxT("zdj/galeria_zdj/galeria5.jpg"));



	gallery->bitmaps = { image1, image2, image3, image4, image5 };
	gallery->scaling = GaleriaZdjecSkalowanie::FillWidth;
}