

#include "stdafx.h"
#include "chess.h"
#include "NegamaxEngine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNegamaxEngine::CNegamaxEngine()
{

}

CNegamaxEngine::~CNegamaxEngine()
{

}
int CNegamaxEngine::SearchAGoodMove(BYTE position[10][9])
{
	m_nMaxDepth = m_nSearchDepth;

	memcpy(CurPosition, position, 90);
	
	NegaMax(m_nMaxDepth);
	
	MakeMove(&m_cmBestMove);
	memcpy(position, CurPosition, 90);
	return 0;
}
extern int count;

int CNegamaxEngine::NegaMax(int depth)
{
	int current = -20000 ;
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
		score = -NegaMax(depth - 1);
		UnMakeMove(&m_pMG->m_MoveList[depth][i],type); 
		
		if (score > current)
		{
			current = score;
			if(depth == m_nMaxDepth)
			{
				m_cmBestMove = m_pMG->m_MoveList[depth][i];
			}
		}

	}

	return current;
}

