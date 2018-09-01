

#if !defined(AFX_NEWGAME_H__B0962A80_D557_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_NEWGAME_H__B0962A80_D557_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewGame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewGame dialog

class CNewGame : public CDialog
{
// Construction
public:

	CNewGame(CWnd* pParent = NULL);   // standard constructor
	int GetSelectedEngine(){return m_nSelectedEngine;};
	int GetSelectedPly(){return m_nSelectedPly;};

// Dialog Data
	//{{AFX_DATA(CNewGame)
	enum { IDD = IDD_NEWGAME };
	CSpinButtonCtrl	m_SetPly;
	CListBox	m_SearchEngineList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewGame)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_nSelectedEngine;
	int m_nSelectedPly;
	// Generated message map functions
	//{{AFX_MSG(CNewGame)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWGAME_H__B0962A80_D557_11D5_AEC7_5254AB2E22C7__INCLUDED_)
