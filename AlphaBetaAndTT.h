

#if !defined(AFX_ALPHABETAANDTT_H__8E8EE2C0_CEBC_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_ALPHABETAANDTT_H__8E8EE2C0_CEBC_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"
#include "TranspositionTable.h"

class CAlphaBetaAndTT : public CSearchEngine, public CTranspositionTable 
{
public:
	CAlphaBetaAndTT();
	virtual ~CAlphaBetaAndTT();

	virtual int SearchAGoodMove(BYTE position[10][9]);
protected:
	int alphabeta(int depth, int alpha, int beta);
};

#endif // !defined(AFX_ALPHABETAANDTT_H__8E8EE2C0_CEBC_11D5_AEC7_5254AB2E22C7__INCLUDED_)
