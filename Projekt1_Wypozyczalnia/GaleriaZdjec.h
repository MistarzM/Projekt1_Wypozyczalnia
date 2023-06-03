#pragma once
#include<wx/wx.h>
#include<wx/graphics.h>
#include<wx/dcbuffer.h>
#include<vector>

enum class GaleriaZdjecSkalowanie : int
{
	Center = 0,
	Fit,
	FillWidth,
	FillHeight

};

class GaleriaZdjec : public wxWindow
{
public:
	GaleriaZdjec(wxWindow* parent);
	void OnPaint(wxPaintEvent& evt);
	void DrawBitmaps(wxGraphicsContext* gc, const wxSize& drawSize);
	void DrawNavigationRect(wxGraphicsContext* gc, const wxRect& rect);
	void DrawArrow(wxGraphicsContext* gc, const wxRect& rectToCenterIn, double lineLength, double lineWidth, double rotationAngle);
	void OnLeftDown(wxMouseEvent& evt);

	std::vector<wxBitmap>bitmaps;
	GaleriaZdjecSkalowanie scaling = GaleriaZdjecSkalowanie::Center;

private:
	int selectedIndex = 0;

	wxSize NavigationRectSize();
	wxRect NavigationRectLeft();
	wxRect NavigationRectRight();
};