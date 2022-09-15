class Cmfc01Dlg : public CDialogEx
{
public:
	int m_Size;
	COLORREF m_Col;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint oPnt;
	afx_msg void OnSel1();
	afx_msg void OnSel8();
	afx_msg void OnSel16();
	afx_msg void OnSelColor();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CSliderCtrl m_Slider;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
};
