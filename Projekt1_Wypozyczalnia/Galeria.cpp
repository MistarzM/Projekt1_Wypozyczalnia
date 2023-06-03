#include "Galeria.h"
Galeria::Galeria(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Galeria", wxDefaultPosition, wxSize(1000, 740))
{
	wxInitAllImageHandlers();
	auto gallery = new GaleriaZdjec(this);

#if defined(__WXOSX__)
	wxImage image1("/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria1.jpg");
	wxImage image2("/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria2.jpg");
	wxImage image3("/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria3.jpg");
	wxImage image4("/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria4.jpg");
	wxImage image5("/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria5.jpg");
#elif defined(__WXMSW__)
	wxImage image1("C:/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria1.jpg");
	wxImage image2("C:/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria2.jpg");
	wxImage image3("C:/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria3.jpg");
	wxImage image4("C:/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria4.jpg");
	wxImage image5("C:/Users/micha/source/repos/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria5.jpg");

#else
	wxImage image1("/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria1.jpg");
	wxImage image2("/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria2.jpg");
	wxImage image3("/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria3.jpg");
	wxImage image4("/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria4.jpg");
	wxImage image5("/ProjektWypozyczalnia/ProjektWypozyczalnia/zdj/galeria_zdj/galeria5.jpg");
#endif

	gallery->bitmaps = { image1, image2, image3, image4, image5 };
	gallery->scaling = GaleriaZdjecSkalowanie::FillWidth;
}