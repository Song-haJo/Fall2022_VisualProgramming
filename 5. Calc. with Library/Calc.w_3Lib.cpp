/*-------------------------------------------------------------------------------------------------
Click [Create a new project] and select [Static Library].
Click [Next] and keep the project name as "StaticLib1." Then, click [Create].
Write the code below in the {StaticLib1.cpp} file.
-------------------------------------------------------------------------------------------------*/
// TODO: This is an example of a library function		//
void fnStaticLib1()						//
{								//
}								//
								//
int Add1(int a, int b)						// C
{								// C
	return a + b;						// C
}								// C
/*-------------------------------------------------------------------------------------------------
On the Solution Explorer, right-click the [Header Files] and click [Add]>[New Item...].
Select [Header File (.h)] and click [Add].
Add the code below in the {Header.h} file.
-------------------------------------------------------------------------------------------------*/
#pragma once
int Add1(int a, int b);
/*-------------------------------------------------------------------------------------------------
On the menu bar, click [Build]>[Build Solution] to check if there is no error.
On the menu bar, click [File]>[Close Solution]. Then, click [Create a new project].
Select [MFC App] and click [Next].
Keep the project name as "MFCApplication1" and the location as the same directory.
Then, click [Create]. Then, set as below.
	- [Application type]: Dialog based
Click [Finish].
Remove {IDC_STATIC1 (Text Control)} and add three {Edit Control}s and three {Button}s.
Set the Button1 as below.
	- [Caption]: Add1
-------------------------------------------------------------------------------------------------*/
#include "../StaticLib1/Header.h"			// C
void CMFCApplication1Dlg::OnBnClickedButton1()		//
{							//
	// TODO: Add your control notification handler code here
	int a, b, c;					// C
	a = GetDlgItemInt(IDC_EDIT1);			// C
	b = GetDlgItemInt(IDC_EDIT2);			// C
	c = Add1(a, b);					// C
	SetDlgItemInt(IDC_EDIT3, c);			// C
}							//
/*-------------------------------------------------------------------------------------------------
On the Solution Explorer, right-click the [MFCApplication1] and click [Add]>[Existing Item...].
Select [StaticLib1]>[x64]>[Debug]>{StaticLib1.lib} and click [Add].
Now, the function Add1 works.
-------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------------------------------------------------------------------------
On the menu bar, click [File]>[New]>[Project...].
Click [Create a new project].
Select [MFC Dynamic-Link Library] and click [Next].
Keep the project name as "MFCLibrary1" and [Solution] as [Create new solution].
Click [Create] and set as below.
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
Add the code below in the {Header.h} file.
-------------------------------------------------------------------------------------------------*/
#pragma once					//
#include "pch.h"					// C
extern "C" int PASCAL EXPORT Add2(int a, int b);	// C
/*-------------------------------------------------------------------------------------------------
On the menu bar, click [Build]>[Build Solution] to check if there is no error.
On the menu bar, click [File]>[Close Solution]. Then, come back to the solution, {MFCApplication1}.
On the {IDD_MFCAPPLICATION1_DIALOG}, set the Button2 as below.
	- [Caption]: Add2
And, double-click Button2.
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
/*-------------------------------------------------------------------------------------------------
On the Solution Explorer, right-click the [MFCApplication1] and click [Add]>[Existing Item...].
Select [MFCLibrary1]>[x64]>[Debug]>{MFCLibrary1.lib} and click [Add].
Then, copy the [MFCLibrary1]>[x64]>[Debug]>{MFCLibrary1.dll}.
Paste in the [MFCApplication1]>[x64]>[Debug] folder.
Now, the function Add2 works.
-------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------------------------------------------------------------------------
On the menu bar, click [File]>[New]>[Project...].
Click [Create a new project].
Select [MFC Dynamic-Link Library] and click [Next].
Keep the project name as "MFCLibrary2" and [Solution] as [Create new solution].
Click [Create] and set as below.
	- [DLL type]: MFC extension DLL
On the Solution Explorer, right-click the [Header Files] and click [Add]>[New Item...].
Select [Header File (.h)] and click [Add].
Add the code below in the {Header.h} file.
-------------------------------------------------------------------------------------------------*/
#pragma once						//
#include "pch.h"					// C
class AFX_EXT_CLASS CMath {				// C
public:							// C
    int Add3(int a, int b);				// C
};							// C
/*-------------------------------------------------------------------------------------------------
Then, write the code below in the {MFCLibrary2.cpp} file. (Solution Explorer>SourceFiles)
-------------------------------------------------------------------------------------------------*/
#ifdef _DEBUG						//
#define new DEBUG_NEW					//
#endif							//
							//
	    						//
#include "Header.h"					// C
int AFX_EXT_CLASS CMath::Add3(int a, int b)		// C
{							// C
	return a + b;					// C
}							// C
/*-------------------------------------------------------------------------------------------------
On the menu bar, click [Build]>[Build Solution] to check if there is no error.
On the menu bar, click [File]>[Close Solution]. Then, come back to the solution, {MFCApplication1}.
On the {IDD_MFCAPPLICATION1_DIALOG}, set the Button2 as below.
	- [Caption]: Add3
And, double-click Button3.
Then, write the code below in the {MFCApplication1Dlg.cpp} file.
-------------------------------------------------------------------------------------------------*/
#include "../MFCLibrary2/Header.h"			// C
void CMFCApplication1Dlg::OnBnClickedButton2()		//
{							//
	// TODO: Add your control notification handler code here
	int a, b, c;					// C
	a = GetDlgItemInt(IDC_EDIT1);			// C
	b = GetDlgItemInt(IDC_EDIT2);			// C
	c = Add3(a, b);					// C
	SetDlgItemInt(IDC_EDIT3, c);			// C
}							//
/*-------------------------------------------------------------------------------------------------
On the Solution Explorer, right-click the [MFCApplication1] and click [Add]>[Existing Item...].
Select [MFCLibrary2]>[x64]>[Debug]>{MFCLibrary2.lib} and click [Add].
Then, copy the [MFCLibrary2]>[x64]>[Debug]>{MFCLibrary2.dll}.
Paste in the [MFCApplication1]>[x64]>[Debug] folder.
Now, the function Add3 works.
-------------------------------------------------------------------------------------------------*/
