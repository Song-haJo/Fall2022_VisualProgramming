CPoint oldPt;
void CPen1Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (nFlags == MK_LBUTTON) {
		CPen pen(PS_SOLID, 8, RGB(0, 255, 0));	// 8 px Green
		CClientDC dc(this);
		dc.SelectObject(&pen);
		dc.MoveTo(oldPt);
		dc.LineTo(point);
	}
	oldPt = point;  // Update the location of mouse pointer.

	CDialogEx::OnMouseMove(nFlags, point);
}
