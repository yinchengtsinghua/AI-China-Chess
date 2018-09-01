
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FALPHABETAENGINE_H__6C3A4903_CDED_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_FALPHABETAENGINE_H__6C3A4903_CDED_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"

class CFAlphaBetaEngine : public CSearchEngine  
{
public:
	CFAlphaBetaEngine();
	virtual ~CFAlphaBetaEngine();

	virtual int  SearchAGoodMove(BYTE position[10][9]);

protected:
	int FAlphaBeta(int depth, int alpha, int beta);

};

#endif // !defined(AFX_FALPHABETAENGINE_H__6C3A4903_CDED_11D5_AEC7_5254AB2E22C7__INCLUDED_)
