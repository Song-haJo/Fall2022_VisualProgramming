void Cmfc01Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {		// IDOK = colorDialog 내 확인 버튼
		m_Col = dlg.GetColor();
	}
}


void Cmfc01Dlg::OnMouseMove(UINT nFlags, CPoint point)
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


void Cmfc01Dlg::OnSel1()
{
	// TODO: Add your command handler code here
	m_Size = 1;
}


void Cmfc01Dlg::OnSel8()
{
	// TODO: Add your command handler code here
	m_Size = 8;
}


void Cmfc01Dlg::OnSel16()
{
	// TODO: Add your command handler code here
	m_Size = 16;
}


void Cmfc01Dlg::OnSelColor()
{
	// TODO: Add your command handler code here
	// 1안과 2안 중 하나만 적으면 된다.
	// 1안
	OnBnClickedButton1();

	// 2안
	/*
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {		// IDOK = colorDialog 내 확인 버튼
		m_Col = dlg.GetColor();
	}
	*/
}


BOOL Cmfc01Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == 'R') m_Col = RGB(255, 0, 0);	// 대문자로 적어야 대소문자 모두 인식
		if (pMsg->wParam == 'G') m_Col = RGB(0, 255, 0);
		if (pMsg->wParam == 'B') m_Col = RGB(0, 0, 255);
	}
	return false;
	return CDialogEx::PreTranslateMessage(pMsg);
}


void Cmfc01Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	m_Size = m_Slider.GetPos();

	*pResult = 0;
}
