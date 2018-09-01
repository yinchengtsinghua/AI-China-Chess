
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEGASCOUT_TT_HH_H__42158561_E8BC_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_NEGASCOUT_TT_HH_H__42158561_E8BC_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"
#include "TranspositionTable.h"
#include "HistoryHeuristic.h"

class CNegaScout_TT_HH : 
	public CTranspositionTable, 
	public CHistoryHeuristic, 
	public CSearchEngine  
{
public:
	CNegaScout_TT_HH();
	virtual ~CNegaScout_TT_HH();

	virtual int SearchAGoodMove(BYTE position[10][9]);

protected:
	int NegaScout(int depth, int alpha, int beta);
};

#endif // !defined(AFX_NEGASCOUT_TT_HH_H__42158561_E8BC_11D5_AEC7_5254AB2E22C7__INCLUDED_)
