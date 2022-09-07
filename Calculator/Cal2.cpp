void CTest2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	IDC_EDIT3 = IDC_EDIT1 + IDC_EDIT2;
	UpdateData(false);
}

// IDC_EDIT1 (Edit Control): The edit control added for the first.
// IDC_EDIT2 (Edit Control): The edit control added for the second.
// IDC_EDIT3 (Edit Control): The edit control added for the second.
