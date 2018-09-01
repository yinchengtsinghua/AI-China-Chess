
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALPHABETAENGINE_H__6C3A4901_CDED_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_ALPHABETAENGINE_H__6C3A4901_CDED_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"

class CAlphaBetaEngine : public CSearchEngine  
{
public:
	CAlphaBetaEngine();
	virtual ~CAlphaBetaEngine();
	
	virtual int SearchAGoodMove(BYTE position[10][9]);

protected:
	int alphabeta(int depth, int alpha, int beta);

};

#endif // !defined(AFX_ALPHABETAENGINE_H__6C3A4901_CDED_11D5_AEC7_5254AB2E22C7__INCLUDED_)
