// COPYRIGHT NOTES
// ---------------
// This source code is a part of chess which is an example of <Game Programing guide>.
// You may use, compile or redistribute it as part of your application 
// for free. 
// You cannot redistribute sources without the official agreement of the author. 
// If distribution of you application which contents code below was occured, place 
// e-mail <hidebug@hotmail.com> on it is to be appreciated.

//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVEGENERATOR_H__54A88FC2_CAFC_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_MOVEGENERATOR_H__54A88FC2_CAFC_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMoveGenerator  
{
public:
	CMoveGenerator();
	virtual ~CMoveGenerator();
	static BOOL IsValidMove(BYTE position[10][9], int nFromX, int nFromY, int nToX, int nToY);
	int CreatePossibleMove(BYTE position[10][9], int nPly,int nSide);

	CHESSMOVE m_MoveList[10][80];
protected:

	void Gen_KingMove(BYTE position[10][9], int i, int j, int nPly);
	void Gen_RBishopMove(BYTE position[10][9], int i, int j, int nPly);
	void Gen_BBishopMove(BYTE position[10][9], int i, int j, int nPly);
	void Gen_ElephantMove(BYTE position[10][9], int i, int j, int nPly);
	void Gen_HorseMove(BYTE position[10][9],  int i, int j, int nPly);
	void Gen_CarMove(BYTE position[10][9],  int i, int j, int nPly);
	void Gen_RPawnMove(BYTE position[10][9],  int i, int j, int nPly);
	void Gen_BPawnMove(BYTE position[10][9], int i, int j, int nPly);
	void Gen_CanonMove(BYTE position[10][9], int i, int j, int nPly);

	int AddMove(int nFromX,int nToX, int nFromY, int nToY,int nPly);
	int m_nMoveCount;
};

#endif // !defined(AFX_MOVEGENERATOR_H__54A88FC2_CAFC_11D5_AEC7_5254AB2E22C7__INCLUDED_)
