// 
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IDALPHABETA_H__6091F700_DF64_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_IDALPHABETA_H__6091F700_DF64_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"

class CIDAlphabeta : public CSearchEngine  
{
public:
	CIDAlphabeta();
	virtual ~CIDAlphabeta();
	virtual int SearchAGoodMove(BYTE position[10][9]);

protected:
	int alphabeta(int depth, int alpha, int beta);
	int m_nTimeCount;
};

#endif // !defined(AFX_IDALPHABETA_H__6091F700_DF64_11D5_AEC7_5254AB2E22C7__INCLUDED_)
