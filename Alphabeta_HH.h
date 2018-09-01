

#if !defined(AFX_Alphabeta_HH_H__5870AB21_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_Alphabeta_HH_H__5870AB21_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"
#include "HistoryHeuristic.h"

class CAlphabeta_HH : public CSearchEngine , public CHistoryHeuristic
{
public:
	CAlphabeta_HH();
	virtual ~CAlphabeta_HH();

	virtual int SearchAGoodMove(BYTE position[10][9]);

protected:
	int alphabeta(int depth, int alpha, int beta);

};

#endif // !defined(AFX_Alphabeta_HH_H__5870AB21_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_)
