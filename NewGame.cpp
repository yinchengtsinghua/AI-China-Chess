// COPYRIGHT NOTES
// ---------------
// This source code is a part of chess which is an example of <Game Programing guide>.
// You may use, compile or redistribute it as part of your application 
// for free. 

// NewGame.cpp : implementation file
//

#include "stdafx.h"
#include "chess.h"
#include "NewGame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewGame dialog


CNewGame::CNewGame(CWnd* pParent /*=NULL*/)
	: CDialog(CNewGame::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewGame)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNewGame::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewGame)
	DDX_Control(pDX, IDC_PLY, m_SetPly);
	DDX_Control(pDX, IDC_LISTENGINE, m_SearchEngineList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewGame, CDialog)
	//{{AFX_MSG_MAP(CNewGame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewGame message handlers

void CNewGame::OnOK() 
{
	// TODO: Add extra validation here
	m_nSelectedEngine = m_SearchEngineList.GetCurSel();
	m_nSelectedPly = m_SetPly.GetPos();
	 
	CDialog::OnOK();
}

BOOL CNewGame::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_SearchEngineList.AddString("Negamax Search Engine");
	m_SearchEngineList.AddString("AlphaBeta Search Engine");
	m_SearchEngineList.AddString("Fail-Soft Alpha-Beta Search Engine");
	m_SearchEngineList.AddString("Aspiration Search Engine");
	m_SearchEngineList.AddString("PVS Search Engine");
	m_SearchEngineList.AddString("Iterative Deepening Alphabeta Search");
	m_SearchEngineList.AddString("AlphaBeta + TT Search Engine");
	m_SearchEngineList.AddString("Alphabeta + History Heuristic Search");
	m_SearchEngineList.AddString("Mdt(f) Search Engine");
	m_SearchEngineList.AddString("NegaScout + TT + HH");
	
	m_SearchEngineList.SetCurSel(0);
	m_SetPly.SetRange(1, 15);
	m_SetPly.SetPos(3);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

