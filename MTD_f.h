// COPYRIGHT NOTES
// ---------------
// This source code is a part of chess which is an example of <Game Programing guide>.
// You may use, compile or redistribute it as part of your application 
// for free. 
// You cannot redistribute sources without the official agreement of the author. 
// If distribution of you application which contents code below was occured, place 
// e-mail <hidebug@hotmail.com> on it is to be appreciated.
// This code can be used WITHOUT ANY WARRANTIES on your own risk.

//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTD_F_H__5870AB22_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_MTD_F_H__5870AB22_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"
#include "TranspositionTable.h"
#include "HistoryHeuristic.h" 

class CMTD_f : 
public CSearchEngine,
public CHistoryHeuristic, 
public CTranspositionTable
{
public:
	CMTD_f();
	virtual ~CMTD_f();
	virtual int SearchAGoodMove(BYTE position[10][9]);

protected:
	int mtdf(int firstguess,int depth);
	int FAlphaBeta(int depth, int alpha, int beta);
	CHESSMOVE m_cmBackupBM;

};

#endif // !defined(AFX_MTD_F_H__5870AB22_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_)
