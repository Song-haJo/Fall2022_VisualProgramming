void CCalculator1Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int a, b, c;
	a = GetDlgItemInt(IDC_A);
	b = GetDlgItemInt(IDC_B);
	c = a + b;
	SetDlgItemInt(IDC_C, c);
}
