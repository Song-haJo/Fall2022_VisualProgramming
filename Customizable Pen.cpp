int n;
void CCustomizablePenDlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	CString pos;
	n = m_Slider.GetPos();
	pos.Format(L"%d", n);
	SetWindowText(pos);
}

CPoint oldPt;									//pen
COLORREF col;									//pen
void CCustomizablePenDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags == MK_LBUTTON)
	{
		CPen pen(PS_SOLID, n, col);					//pen
		//CBrush br = RGB(0, 0, 255);				//ellipse
		CClientDC dc(this);
		//dc.SelectObject(&br);
		dc.SelectObject(&pen);						//pen
		dc.MoveTo(oldPt);						//pen
		dc.LineTo(point);						//pen
		//CPoint p = point;					//ellipse
		//dc.Ellipse(p.x-n, p.y-n, p.x+n, p.y+n);		//ellipse
		CDialogEx::OnMouseMove(nFlags, point);
	}
	oldPt = point;
}

void CCustomizablePenDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		col = dlg.GetColor();
	}
}
