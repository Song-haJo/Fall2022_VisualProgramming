///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// First  Part /////////////////////////////////////

int n;
void CEarthwormDlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	CString pos;
	n = sz_Slider.GetPos();
	pos.Format(L"%d", n);
	SetWindowText(pos);			// Show the value on the window title
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Second Part /////////////////////////////////////

void CEarthwormDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags == MK_LBUTTON)
	{
		CBrush br = RGB(0, 0, 255);	// set the ellipse color as blue
		CClientDC dc(this);
		dc.SelectObject(&br);
		CPoint p = point;
		dc.Ellipse(p.x - n, p.y - n, p.x + n, p.y + n);
		CDialogEx::OnMouseMove(nFlags, point);
	}
}
