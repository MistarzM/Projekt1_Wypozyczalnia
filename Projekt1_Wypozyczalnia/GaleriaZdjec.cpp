#include "GaleriaZdjec.h"

GaleriaZdjec::GaleriaZdjec(wxWindow* parent) : wxWindow(parent, wxID_ANY, wxDefaultPosition , wxSize(1000, 740), wxFULL_REPAINT_ON_RESIZE)
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	this->Bind(wxEVT_PAINT, &GaleriaZdjec::OnPaint, this);

	this->Bind(wxEVT_LEFT_DOWN, &GaleriaZdjec::OnLeftDown, this);
}

void GaleriaZdjec::OnPaint(wxPaintEvent& evt)
{
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);

	if (gc && bitmaps.size() > 0)
	{
		const wxSize drawSize = GetClientSize();

		DrawBitmaps(gc, drawSize);

		double arrowLineLength = NavigationRectSize().GetWidth() * 2 / 3;
		double arrowLineWidth = FromDIP(5);

		DrawNavigationRect(gc, NavigationRectLeft());
		DrawArrow(gc, NavigationRectLeft(), arrowLineLength, arrowLineWidth, 0);

		DrawNavigationRect(gc, NavigationRectRight());
		DrawArrow(gc, NavigationRectRight(), arrowLineLength, arrowLineWidth, M_PI);


		delete gc;
	}
}
void GaleriaZdjec::DrawBitmaps(wxGraphicsContext* gc, const wxSize& drawSize)
{
	const auto currentTransform = gc->GetTransform();

	const wxSize dipDrawSize = ToDIP(drawSize);

	gc->Translate(-FromDIP(dipDrawSize.GetWidth()) * selectedIndex, 0);

	for (const auto& bitmap : bitmaps)
	{
		const wxSize bmpSize = bitmap.GetSize();

		double imageW = bmpSize.GetWidth();
		double imageH = bmpSize.GetHeight();

		if (scaling == GaleriaZdjecSkalowanie::Fit)
		{
			double scaleX = dipDrawSize.GetWidth() / imageW;
			double scaleY = dipDrawSize.GetHeight() / imageH;

			double scale = std::min(scaleX, scaleY);

			imageW *= scale;
			imageH *= scale;
		}
		else if (scaling == GaleriaZdjecSkalowanie::FillWidth)
		{
			double scaleX = dipDrawSize.GetWidth() / imageW;

			imageW *= scaleX;
			imageH *= scaleX;
		}
		else if (scaling == GaleriaZdjecSkalowanie::FillHeight)
		{
			double scaleY = dipDrawSize.GetHeight() / imageH;

			imageW *= scaleY;
			imageH *= scaleY;
		}

		double cellCenterX = dipDrawSize.GetWidth() / 2;
		double imageCenterX = imageW / 2;

		double cellCenterY = dipDrawSize.GetHeight() / 2;
		double imageCenterY = imageH / 2;

		double bitmapX = cellCenterX - imageCenterX;
		double bitmapY = cellCenterY - imageCenterY;

		gc->Clip(0, 0, FromDIP(dipDrawSize.GetWidth()), FromDIP(dipDrawSize.GetHeight()));
		gc->DrawBitmap(bitmap, FromDIP(bitmapX), FromDIP(bitmapY), FromDIP(imageW), FromDIP(imageH));

		gc->ResetClip();

		gc->Translate(FromDIP(dipDrawSize.GetWidth()), 0);
	}
	gc->SetTransform(currentTransform);
}
void GaleriaZdjec::DrawNavigationRect(wxGraphicsContext* gc, const wxRect& rect)
{
	gc->SetPen(*wxTRANSPARENT_PEN);
	gc->SetBrush(wxBrush(wxColor(255, 255, 255, 70)));

	gc->DrawRectangle(rect.GetX(), rect.GetY(), rect.GetWidth(), rect.GetHeight());
}

void GaleriaZdjec::DrawArrow(wxGraphicsContext* gc, const wxRect& rectToCenterIn, double lineLength, double lineWidth, double rotationAngle)
{
	const auto currentTransform = gc->GetTransform();
	const auto rectCenter = rectToCenterIn.GetPosition() + rectToCenterIn.GetSize() / 2;

	gc->SetPen(wxPen(wxColor(255, 255, 255, 255), lineWidth));

	gc->Translate(rectCenter.x, rectCenter.y);
	gc->Rotate(-M_PI / 4);
	gc->Rotate(rotationAngle);
	gc->Translate(-lineLength / 4, -lineLength / 4);

	gc->StrokeLine(0, 0, lineLength, 0);
	gc->StrokeLine(0, 0, 0, lineLength);

	gc->SetTransform(currentTransform);
}


void GaleriaZdjec::OnLeftDown(wxMouseEvent& evt)
{
	if (NavigationRectLeft().Contains(evt.GetPosition()))
	{
		selectedIndex = std::max(0, selectedIndex - 1);
		Refresh();
	}
	else if (NavigationRectRight().Contains(evt.GetPosition()))
	{
		selectedIndex = std::min(static_cast<int>(bitmaps.size()) - 1, selectedIndex + 1);
		Refresh();
	}
	else
	{
		evt.Skip();
	}
}

wxSize GaleriaZdjec::NavigationRectSize()
{
	return { FromDIP(30), GetClientSize().GetHeight() };
}

wxRect GaleriaZdjec::NavigationRectLeft()
{
	return { 0, 0, NavigationRectSize().GetWidth(), NavigationRectSize().GetHeight() };
}

wxRect GaleriaZdjec::NavigationRectRight()
{
	return { GetClientSize().GetWidth() - NavigationRectSize().GetWidth(), 0, NavigationRectSize().GetWidth(), NavigationRectSize().GetHeight() };
}