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

CPoint oldPt;
COLORREF col;
void CCustomizablePenDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags == MK_LBUTTON)
	{
		CPen pen(PS_SOLID, n, col);
		CClientDC dc(this);
		dc.SelectObject(&pen);
		dc.MoveTo(oldPt);
		dc.LineTo(point);
		CDialogEx::OnMouseMove(nFlags, point);
	}
	oldPt = point;
}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Third  Part /////////////////////////////////////

void CCustomizablePenDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		col = dlg.GetColor();
	}
}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Fourth Part /////////////////////////////////////

BEGIN_MESSAGE_MAP(CCustomizablePenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CCustomizablePenDlg::OnNMCustomdrawSlider1)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CCustomizablePenDlg::OnBnClickedButton1)
	ON_COMMAND(ID_SIZE_4, OnMenuSize4)		// Line to add	(Function name: OnMenuSize4)
	ON_COMMAND(ID_SIZE_8, OnMenuSize8)		// Line to add	(Function name: OnMenuSize8)
	ON_COMMAND(ID_SIZE_16, OnMenuSize16)		// Line to add	(Function name: OnMenuSize16)
BEGIN_MESSAGE_MAP()

	
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Fifth  Part /////////////////////////////////////

void CCustomizablePenDlg::OnMenuSize4()
{
	// TODO: Add your implementation code here.
	n = 4;
	MessageBox(L"Size changed to 4 px.")
}

void CCustomizablePenDlg::OnMenuSize16()
{
	// TODO: Add your implementation code here.
	n = 8;
	MessageBox(L"Size changed to 8 px.")
}

void CCustomizablePenDlg::OnMenuSize16()
{
	// TODO: Add your implementation code here.
	n = 16;
	MessageBox(L"Size changed to 16 px.")
}
