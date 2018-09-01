// COPYRIGHT NOT

#include "stdafx.h"
#include "chess.h"
#include "AspirationSearch.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAspirationSearch::CAspirationSearch()
{
}

CAspirationSearch::~CAspirationSearch()
{
}

int CAspirationSearch::SearchAGoodMove(BYTE position[10][9])
{
	int x,y;
	memcpy(CurPosition, position, 90);
	m_nMaxDepth = m_nSearchDepth-1;
	x= FAlphaBeta(m_nMaxDepth, -20000, 20000);
	m_nMaxDepth = m_nSearchDepth;
	y = FAlphaBeta(m_nMaxDepth, x-50, x+50);
	if (y < x-50)
		FAlphaBeta(m_nMaxDepth, -20000, y);
	if (y > x+50)
		FAlphaBeta(m_nMaxDepth, y, 20000);
	MakeMove(&m_cmBestMove);
	memcpy(position, CurPosition, 90);
	return 0;
}