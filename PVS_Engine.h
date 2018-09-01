// COPYRIGHT NOTES
// ---------------
// This source code is a part of chess which is an example of <Game Programing guide>.
// You may use, compile or redistribute it as part of your application 
// for free. 
// You cannot redistribute sources without the official agreement of the author. 
// If distribution of you application which contents code below was occured, place 

//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PVS_ENGINE_H__8E7D8B20_DB95_11D5_AEC7_5254AB2E22C7__INCLUDED_)
#define AFX_PVS_ENGINE_H__8E7D8B20_DB95_11D5_AEC7_5254AB2E22C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"

class CPVS_Engine : public CSearchEngine
{
public:
	CPVS_Engine();
	virtual ~CPVS_Engine();
	virtual int  SearchAGoodMove(BYTE position[10][9]);

protected:
	int PrincipalVariation(int depth, int alpha, int beta);


};

#endif // !defined(AFX_PVS_ENGINE_H__8E7D8B20_DB95_11D5_AEC7_5254AB2E22C7__INCLUDED_)
