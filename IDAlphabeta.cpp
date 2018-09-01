// COPYRIGHT NOTES


#include "stdafx.h"
#include "chess.h"
#include "IDAlphabeta.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIDAlphabeta::CIDAlphabeta()
{

}

CIDAlphabeta::~CIDAlphabeta()
{

}

int  CIDAlphabeta::SearchAGoodMove(BYTE position[10][9])
{
	CHESSMOVE backupmove;
	memcpy(CurPosition, position, 90);
	m_nTimeCount = GetTickCount();
	for (m_nMaxDepth = 1; m_nMaxDepth <= m_nSearchDepth; m_nMaxDepth++)
	{
		if (alphabeta(m_nMaxDepth, -20000, 20000) != 66666)
			backupmove = m_cmBestMove;
	}

	MakeMove(&backupmove);
	memcpy(position, CurPosition, 90);
	return 0;
}
int CIDAlphabeta::alphabeta(int depth, int alpha, int beta)
{
	int score;
	int Count,i;
	BYTE type;

	i = IsGameOver(CurPosition, depth);
	if (i != 0)
		return i;

	if (depth <= 0)	//叶子节点取估值
		return m_pEval->Eveluate(CurPosition, (m_nMaxDepth-depth)%2);
	
	Count = m_pMG->CreatePossibleMove(CurPosition, depth, (m_nMaxDepth-depth)%2);
	
	if (depth == m_nMaxDepth && m_nMaxDepth > 1)
	{
		for (i=1; i < Count;i++) 
		{
			if (m_pMG->m_MoveList[depth][i].From.x == m_cmBestMove.From.x
				&& m_pMG->m_MoveList[depth][i].From.y == m_cmBestMove.From.y
				&& m_pMG->m_MoveList[depth][i].To.x == m_cmBestMove.To.x	
				&& m_pMG->m_MoveList[depth][i].To.y == m_cmBestMove.To.y)	
			{
				m_pMG->m_MoveList[depth][i] = m_pMG->m_MoveList[depth][0];
				m_pMG->m_MoveList[depth][0] = m_cmBestMove;
			}				
		}	
	}

	for (i=0;i<Count;i++) 
	{
		if (depth == m_nMaxDepth)
		{
			if (GetTickCount() - m_nTimeCount >= 1000000)
				return 66666;
		}
		type = MakeMove(&m_pMG->m_MoveList[depth][i]);
		score = -alphabeta(depth - 1, -beta, -alpha);
		UnMakeMove(&m_pMG->m_MoveList[depth][i],type); 

		if (score > alpha)
		{
			alpha = score;
			if(depth == m_nMaxDepth)
				m_cmBestMove = m_pMG->m_MoveList[depth][i];
		}
        if (alpha >= beta) 
              break;

				
	}
	return alpha;
}

