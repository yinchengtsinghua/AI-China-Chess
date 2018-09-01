

#include "stdafx.h"
#include "chess.h"
#include "HistoryHeuristic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHistoryHeuristic::CHistoryHeuristic()
{
}

CHistoryHeuristic::~CHistoryHeuristic()
{
}

void CHistoryHeuristic::ResetHistoryTable()
{
	memset(m_HistoryTable, 10, 8100*4);
}

int CHistoryHeuristic::GetHistoryScore(CHESSMOVE *move)
{
	int nFrom, nTo;
	
	nFrom = move->From.y*9+move->From.x;
	nTo = move->To.y*9+move->To.x;
	
	return m_HistoryTable[nFrom][nTo];
}
void CHistoryHeuristic::EnterHistoryScore(CHESSMOVE *move,int depth)
{
	int nFrom, nTo;
	nFrom = move->From.y*9+move->From.x;
	nTo = move->To.y*9+move->To.x;

	m_HistoryTable[nFrom][nTo] += 2<<depth;
}
//
void CHistoryHeuristic::Merge(CHESSMOVE *source, CHESSMOVE *target, int l,int m, int r)
	{//从小到大排序
		int i = l;
		int j = m + 1;
		int k = l;
		
		while((i <= m) && (j <= r))
			if (source[i].Score <= source[j].Score)
				target[k++] = source[i++];
			else
				target[k++] = source[j++];
			
			if(i > m)
				for (int q = j; q <= r; q++)
					target[k++] = source[q];
				else
					for(int q = i; q <= m; q++)
						target[k++] = source[q];
	}

void CHistoryHeuristic::Merge_A(CHESSMOVE *source, CHESSMOVE *target, int l,int m, int r)
	{//从大到小排序
		int i = l;
		int j = m + 1;
		int k = l;
		
		while((i <= m) && (j <= r))
			if (source[i].Score >= source[j].Score)
				target[k++] = source[i++];
			else
				target[k++] = source[j++];
			
		if(i > m)
			for (int q = j; q <= r; q++)
				target[k++] = source[q];
		else
			for(int q = i; q <= m; q++)
				target[k++] = source[q];
	}
	
	
void CHistoryHeuristic::MergePass(CHESSMOVE *source, CHESSMOVE *target, const  int s, const  int n, const BOOL direction)
	{
		int i = 0;
		
		while(i <= n - 2 * s)
		{
			//合并大小为s的相邻二段子数组
			if (direction)
				Merge(source, target, i, i + s - 1, i + 2 * s - 1);
			else
				Merge_A(source, target, i, i + s - 1, i + 2 * s - 1);
			i=i+2*s;
		}
		
		if (i + s < n) //剩余的元素个数小於2s
		{
			if (direction)
				Merge(source, target, i, i + s - 1, n - 1);
			else
				Merge_A(source, target, i, i + s - 1, n - 1);
		}
		else
			for (int j = i; j <= n - 1; j++)
				target[j] = source[j];
	}


void CHistoryHeuristic::MergeSort(CHESSMOVE *source, int n, BOOL direction)
{
	int s = 1;
	while(s < n)
	{
		MergePass(source, m_TargetBuff, s, n, direction);
		s += s;
		MergePass(m_TargetBuff, source, s, n, direction);
		s += s;
	}
}

