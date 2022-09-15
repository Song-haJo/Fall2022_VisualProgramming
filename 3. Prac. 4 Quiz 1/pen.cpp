void Cmfc01Dlg::OnBnClickedButton1()				// When you click Button1, you can use the Color Dialog.
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {		// IDOK = OK Button in the Color Dialog 
		m_Col = dlg.GetColor();
	}
}


void Cmfc01Dlg::OnMouseMove(UINT nFlags, CPoint point)		// When you drag with the left mouse button, you can draw with your pen.
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags & MK_LBUTTON) {
		CClientDC dc(this);
		CPen pen(PS_SOLID, m_Size, m_Col);
		dc.SelectObject(&pen);
		dc.MoveTo(oPnt);
		dc.LineTo(point);
	}
	oPnt = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void Cmfc01Dlg::OnSel1()					// When you click the submenu 1, you can set your pen size as 1 px.
{
	// TODO: Add your command handler code here
	m_Size = 1;
}


void Cmfc01Dlg::OnSel8()					// When you click the submenu 8, you can set your pen size as 8 px.
{
	// TODO: Add your command handler code here
	m_Size = 8;
}


void Cmfc01Dlg::OnSel16()					// When you click the submenu 16, you can set your pen size as 16 px.
{
	// TODO: Add your command handler code here
	m_Size = 16;
}


void Cmfc01Dlg::OnSelColor()					// When you click the submenu Color, you can use the Color Dialog.
{
	// TODO: Add your command handler code here
	// Choose one between Option 1 and 2
	// Option 1: works same as Option 2
	OnBnClickedButton1();

	// Option 2: works same as Option 1
	/*
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {		// IDOK = OK Button in the Color Dialog 
		m_Col = dlg.GetColor();
	}
	*/
}


BOOL Cmfc01Dlg::PreTranslateMessage(MSG* pMsg)			// When you press the "R," "G," or "B" key, you can change the pen color to Red, Green, or Blue.
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == 'R') m_Col = RGB(255, 0, 0);	// For the condition, you need to use capital letters
		if (pMsg->wParam == 'G') m_Col = RGB(0, 255, 0);	// to let your computer recognize both upper and lower cases.
		if (pMsg->wParam == 'B') m_Col = RGB(0, 0, 255);
	}
	return false;
	return CDialogEx::PreTranslateMessage(pMsg);
}


void Cmfc01Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)	// This will get you the number of the slider's position.
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	m_Size = m_Slider.GetPos();

	*pResult = 0;
}
