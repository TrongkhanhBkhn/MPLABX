// GxtY601.h : main header file for the GXTY601 application
//

#if !defined(AFX_GXTY601_H__E5769726_C76D_454F_BDF9_FEA116711AEA__INCLUDED_)
#define AFX_GXTY601_H__E5769726_C76D_454F_BDF9_FEA116711AEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


/////////////////////////////////////////////////////////////////////////////
// CGxtY601App:
// See GxtY601.cpp for the implementation of this class
//

class CGxtY601App : public CWinApp
{
public:
	CGxtY601App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGxtY601App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGxtY601App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GXTY601_H__E5769726_C76D_454F_BDF9_FEA116711AEA__INCLUDED_)
