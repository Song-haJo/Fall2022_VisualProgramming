/*-----------------------------------------------------------------------------------------------------------------
Create a new project.
Select "MFC App" and name the project name as "LPen." Then, click "Create."
In the <MFC Application> setting dialog, set as below.
* Application Type Options
	- [Application type] > Single Document
	- [Project style] > MFC standard
* Document Template Properties
	- [File extension] > anu
* Generated Classes
	- [Generated classes] > View
	- [Base class] > CFormView
Then, click "Finish."
In the "Class View," click "CLPenDoc" to open "LPenDoc.h" file.
Write the code as below.
-----------------------------------------------------------------------------------------------------------------*/
// Attributes			// L; location
public:				    // L
    CObArray m_oa;			// C; Code
/*-----------------------------------------------------------------------------------------------------------------
In the "Class View," select "CLPenDoc" and click "Serialize(CArchive & ar)" to open "LPenDoc.cpp" file.
Write the code as below.
-----------------------------------------------------------------------------------------------------------------*/
// CLPenDoc serialization		        // L
void CLPenDoc::Serialize(CArchive& ar)	// L
{				                        // L
    m_oa.Serialize(ar);			// C
}				                        // L
/*-----------------------------------------------------------------------------------------------------------------
Through the shortcut "Ctrl+Shift+X," open the "Class Wizard."
In the "Add Class..." combo box, click "MFC Class..."
In the "Add MFC Class" dialog, set as below and click "OK."
	- [Class name] > CLine
	- [Base class] > CObject
In the "CLine.h" file, write the code as below.
-----------------------------------------------------------------------------------------------------------------*/
#pragma once				    // L

// CLine command target			// L
class CLine : public CObject	// L
{					            // L
public:					        // L
    CLine(CPoint From, CPoint To, int Size, COLORREF Col)	// C
    {						                                // C
		m_From = From;				                        // C
		m_To = To;				                            // C
		m_Size = Size;			                        	// C
		m_Col = Col;			                        	// C
	}						                                // C
	void Draw(CDC* pDC)			                        	// C
	{					                                	// C
		CPen pen(PS_SOLID, m_Size, m_Col);	            	// C
		pDC->SelectObject(&pen);		                	// C
		pDC->MoveTo(m_From);		                    	// C
		pDC->LineTo(m_To);		                        	// C
	}						                                // C
	CLine();			    	// L
	virtual ~CLine();			// L
	CPoint m_From, m_To;	                    			// C
	COLORREF m_Col;		                        			// C
	int m_Size;				                               	// C
}				            	// L
/*-----------------------------------------------------------------------------------------------------------------
In the "Class View," select "CLine" and click "<Add> Serialize" in the combo box of "[Properties] > [Overrides]."
In the "CLine.cpp" file, write the code as below.
-----------------------------------------------------------------------------------------------------------------*/
// CLine.cpp : implementation file	// L
//				                    // L

#include "pch.h"			        // L
#include "LPen.h"		        	// L
#include "CLine.h"		        	// L
	
IMPLEMENT_SERIAL(CLine, CObject, 1)		    // C
// CLine				            // L

/*---------------------------------------------------------------------------------------------------------------*/
// CLine member functions			    // L
void CLine::Serialize(CArchive& ar)		// L
{					                    // L
	if (ar.IsStoring())	        		// L
	{	// storing code	               	// L
		ar << m_From << m_To << m_Size << m_Col;	// C
	}				                    // L
	else			                	// L
	{	// loading code	            	// L
		ar >> m_From >> m_To >> m_Size >> m_Col;	// C
	}				                    // L
}					                    // L
/*-----------------------------------------------------------------------------------------------------------------
In the "CLine.h" file, write the code as below.
-----------------------------------------------------------------------------------------------------------------*/
#pragma once				    // L

// CLine command target			// L
class CLine : public CObject	// L
{					            // L
	DECLARE_SERIAL(CLine)			    // C
public:					        // L
/*-----------------------------------------------------------------------------------------------------------------
In the "Class View," select "CLPenView" and click "<Add> OnMouseMove" in the combo box of "[Properties] > [Messages]."
In the "LPenView.cpp" file, rite the code as below.
-----------------------------------------------------------------------------------------------------------------*/
#include "LPenDoc.h"			// L
#include "LPenView.h"			// L
#include "CLine.h"				// C
/*---------------------------------------------------------------------------------------------------------------*/
// CLPenView message handlers		                	// L
void CLPenView::OnMouseMove(UINT nFlags, CPoint point)	// L
{						                                // L
	if (nFlags & MK_LBUTTON)		               		// C
	{						                            // C
		CLine* p = new CLine(opnt, point, size, col);	// C
		GetDocument()->m_oa.Add(p);		                // C
		Invalidate(false);			                	// C
	}						                            // C
	opnt = point;					                    // C
	CFormView::OnMouseMove(nFlags, point);          	// L
}						                                // L
/*-----------------------------------------------------------------------------------------------------------------
In the "LPenView.h" file, rite the code as below.
-----------------------------------------------------------------------------------------------------------------*/
// Attributes					        // L
public:						            // L
	CLPenDoc* GetDocument() const;		// L
	CPoint opnt;				// C
	int size;					// C
	COLORREF col;				// C
/*-----------------------------------------------------------------------------------------------------------------
In the "Class View," select "CLPenView" and  click "OnInitialUpdate()" to open "LPenView.cpp" file again.
-----------------------------------------------------------------------------------------------------------------*/
void CLPenView::OnInitialUpdate()			// L
{						                    // L
	CFormView::OnInitialUpdate();			// L
	GetParentFrame()->RecalcLayout();		// L
	ResizeParentToFit();		        	// L
	size = 16;					            // C
	col = RGB(0, 255, 0);			       	// C
}						                    // L
/*-----------------------------------------------------------------------------------------------------------------
In the "Class View," select "CLPenView" and click "<Add> OnPaint" in the combo box of "[Properties] > [Messages]."
Write the code as below.
-----------------------------------------------------------------------------------------------------------------*/
	void CLPenView::OnPaint()			// L
	{					                // L
		CPaintDC dc(this);		      	// L
		int n = GetDocument()->m_oa.GetSize();			// C
		for (int i = 0; i < n; i++)				        // C
		{						                        // C
			CLine* p = (CLine*)GetDocument()->m_oa[i];	// C
			p->Draw(&dc);				                // C
		}						                        // C
	}					                // L
/*-----------------------------------------------------------------------------------------------------------------
Remove "ICD_STATIC1 (Text Control)" and make the dialog window bigger.
In the "Class View," select "CLPenDoc" and click "OnNewDocument()" to open "LPenDoc.cpp" file again.
-----------------------------------------------------------------------------------------------------------------*/
	BOOL CLPenDoc::OnNewDocument()			// L
	{					                	// L
		if (!CDocument::OnNewDocument())	// L
			return FALSE;			        // L
		INT_PTR n = m_oa.GetSize();			// C
		for (INT_PTR i = 0; i < n; i++)		// C
			delete (m_oa[i]);		    	// C
		m_oa.RemoveAll();			    	// C
		return TRUE;		        		// L
	}					                	// L
/*-----------------------------------------------------------------------------------------------------------------
In the "Resource View," click "IDR_MAINFRAME" in the "Toolbar" folder.
-----------------------------------------------------------------------------------------------------------------*/
