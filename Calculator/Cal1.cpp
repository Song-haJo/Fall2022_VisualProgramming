void C[project name]Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int a, b, c;
	a = GetDlgItemInt(IDC_EDIT1);	// Get an integer from IDC_EDIT1.
	b = GetDlgItemInt(IDC_EDIT2);	// Get an integer from IDC_EDIT2.
	c = a + b;
	SetDlgItemInt(IDC_EDIT3, c);	// Put the result in IDC_EDIT3.
}

// IDC_EDIT1 (Edit Control): The edit control added for the first.
// IDC_EDIT2 (Edit Control): The edit control added for the second.
// IDC_EDIT3 (Edit Control): The edit control added for the second.
