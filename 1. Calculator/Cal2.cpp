void CCal2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	vC = vA + vB;
	UpdateData(false);
}

// vA = IDC_EDIT1 (Edit Control): The edit control added for the first.
// vB = IDC_EDIT2 (Edit Control): The edit control added for the second.
// vC = IDC_EDIT3 (Edit Control): The edit control added for the second.
