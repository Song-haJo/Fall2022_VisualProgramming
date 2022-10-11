/*-------------------------------------------------------------------------------------------------
On the menu bar, click [File]>[Close Solution]. Then, click [Create a new project].
Select [MFC App] and click [Next].
Keep the project name as "MFCApplication1" and the location as the same directory.
Then, click [Create]. Then, set as below.
	- [Application type]: Dialog based
Click [Finish].
Remove {IDC_STATIC1 (Text Control)} and add three {Edit Control}s and three {Button}s.
Set the first button as below.
	- [Caption]: Add1
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Select [MFC Dynamic-Link Library] and click [Next].
Keep the project name as "MFCLibrary1" and click [Create]. Then, set as below.
	- [DLL type]: Regular DLL using shared MFC DLL
Click [OK] and write as below in the {MFCLibrary1.def} file. (Solution Explorer>SourceFiles)
-------------------------------------------------------------------------------------------------*/
; MFCLibrary1.def : Declares the module parameters for the DLL.	//
								//
LIBRARY								//
								//
EXPORTS								//
    ; Explicit exports can go here				//
    Add2								// C
/*-------------------------------------------------------------------------------------------------
Then, write the code below in the {MFCLibrary1.cpp} file. (Solution Explorer>SourceFiles)
-------------------------------------------------------------------------------------------------*/
// CMFCLibrary1App initialization		//
						//
BOOL CMFCLibrary1App::InitInstance()		//
{						//
	CWinApp::InitInstance();		//
						//
	return TRUE;				//
}						//
						//
extern "C" int PASCAL EXPORT Add2(int a, int b) {	// C
	AFX_MANAGE_STATE(AfxGetStaticModuleState());	// C
	// normal function body here			// C
	return (a + b);					// C
}							// C
/*-------------------------------------------------------------------------------------------------
On the Solution Explorer, right-click the [Header Files] and click [Add]>[New Item...].
Select [Header File (.h)] and click [Add].
-------------------------------------------------------------------------------------------------*/
#pragma once					//
#include "pch.h"					// C
extern "C" int PASCAL EXPORT Add2(int a, int b);	// C
/*-------------------------------------------------------------------------------------------------
On the menu bar, click [File]>[Close Solution]. Then, come back to the solution, {MFCApplication1}.
On the {IDD_MFCAPPLICATION1_DIALOG}, set the second button as below.
	- [Caption]: Add2
And double-click it.
Then, write the code below in the {MFCApplication1Dlg.cpp} file.
-------------------------------------------------------------------------------------------------*/
#include "../MFCLibrary1/Header.h"			// C
void CMFCApplication1Dlg::OnBnClickedButton2()		//
{							//
	// TODO: Add your control notification handler code here
	int a, b, c;					// C
	a = GetDlgItemInt(IDC_EDIT1);			// C
	b = GetDlgItemInt(IDC_EDIT2);			// C
	c = Add2(a, b);					// C
	SetDlgItemInt(IDC_EDIT3, c);			// C
}							//
/*
