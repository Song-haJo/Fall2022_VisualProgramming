/*Select [MFC Dynamic-Link Library] and click [Next].
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
    Add								// C
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
extern "C" int PASCAL EXPORT Add(int a, int b) {	// C
	AFX_MANAGE_STATE(AfxGetStaticModuleState());	// C
	// normal function body here			// C
	return (a + b);					// C
}							// C
/*-------------------------------------------------------------------------------------------------
On the Solution Explorer, right-click the [Header Files] and click [Add]>[New Item...].
Select [Header File (.h)] and click [Add].
-------------------------------------------------------------------------------------------------*/
#pragma once					//
						//
extern "C" int PASCAL EXPORT Add(int a, int b);	// C
