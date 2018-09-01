// COPYRIG
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HISTORYHEURISTIC_H__5870AB20_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_HISTORYHEURISTIC_H__5870AB20_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHistoryHeuristic  
{
public:
	CHistoryHeuristic();
	virtual ~CHistoryHeuristic();
	
	void ResetHistoryTable();
	int GetHistoryScore(CHESSMOVE *move);
	void EnterHistoryScore(CHESSMOVE *move,int depth);
	void MergeSort(CHESSMOVE *source, int n, BOOL direction);
protected:
	void Merge(CHESSMOVE *source, CHESSMOVE *target, int l,int m, int r);
	void MergePass(CHESSMOVE *source, CHESSMOVE *target, const  int s, const  int n, const BOOL direction);
	void Merge_A(CHESSMOVE *source, CHESSMOVE *target, int l,int m, int r);
	int m_HistoryTable[90][90];
	CHESSMOVE m_TargetBuff[100]; 

};

#endif // !defined(AFX_HISTORYHEURISTIC_H__5870AB20_E3F1_11D5_AEC7_5254AB2E22C7__INCLUDED_)
