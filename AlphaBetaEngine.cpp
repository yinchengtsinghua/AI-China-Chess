// COPYRIGHT NOTES
// ---------------
// This source code is a part of chess which is an example of <Game Programing guide>.
// You may use, compile or redistribute it as part of your application 
// for free. 


#include "stdafx.h"
#include "chess.h"
#include "AlphaBetaEngine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CAlphaBetaEngine::CAlphaBetaEngine()
{

}

CAlphaBetaEngine::~CAlphaBetaEngine()
{

}

int CAlphaBetaEngine::SearchAGoodMove(BYTE position[10][9])
{
	memcpy(CurPosition, position, 90);
	m_nMaxDepth = m_nSearchDepth;
	alphabeta(m_nMaxDepth, -20000, 20000);
	MakeMove(&m_cmBestMove);
	memcpy(position, CurPosition, 90);
	return 0;
}

int CAlphaBetaEngine::alphabeta(int depth, int alpha, int beta)
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

	for (i=0;i<Count;i++) 
	{

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

/*
int CAlphaBetaEngine::alphabeta_A(int depth, int alpha, int beta)
{
	int score;
	int Count,i;
	BYTE type;

	i = IsGameOver(CurPosition, depth);
	if (i != 0)
		return i;

	if (depth <= 0)	//叶子节点取估值
		return m_pEval->Eveluate(CurPosition, 0);
	
	Count = m_pMG->CreatePossibleMove(CurPosition, depth, 0);

	for (i=0;i<Count;i++) 
	{

		type = MakeMove(&m_pMG->m_MoveList[depth][i]);
		score = -alphabeta_B(depth - 1, -beta, -alpha);
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



int CAlphaBetaEngine::alphabeta_B(int depth, int alpha, int beta)
{
	int score;
	int Count,i;
	BYTE type;

	i = IsGameOver(CurPosition, depth);
	if (i != 0)
		return i;

	if (depth <= 0)	//叶子节点取估值
		return m_pEval->Eveluate(CurPosition, 1);
	
	Count = m_pMG->CreatePossibleMove(CurPosition, depth, 1);

	for (i=0;i<Count;i++) 
	{

		type = MakeMove(&m_pMG->m_MoveList[depth][i]);
		score = -alphabeta_A(depth - 1, -beta, -alpha);
		UnMakeMove(&m_pMG->m_MoveList[depth][i],type); 

		if (score > alpha)
			alpha = score;
        if (alpha >= beta) 
              break;
	}
	return alpha;
}


*/