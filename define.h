// COPYRIGHT NOTES

// 


//define.h // data structure and macros
#ifndef define_h_
#define define_h_

#define NOCHESS 0    //Ã»ÓÐÆå×Ó

#define B_KING       1  //ºÚË§
#define B_CAR        2  //ºÚ³µ
#define B_HORSE      3  //ºÚÂí
#define B_CANON      4  //ºÚÅÚ
#define B_BISHOP     5  //ºÚÊ¿
#define B_ELEPHANT   6  //ºÚÏó
#define B_PAWN       7  //ºÚ×ä
#define B_BEGIN      B_KING
#define B_END        B_PAWN

#define R_KING       8   //ºìË§
#define R_CAR        9   //ºì³µ
#define R_HORSE      10  //ºìÂí
#define R_CANON      11  //ºìÅÚ
#define R_BISHOP     12  //ºìÊ¿
#define R_ELEPHANT   13  //ºìÏó
#define R_PAWN       14  //ºì±ø
#define R_BEGIN      R_KING
#define R_END        R_PAWN

#define IsBlack(x)  (x>=B_BEGIN&&x<=B_END)
#define IsRed(x)  (x>=R_BEGIN&&x<=R_END)
#define IsSameSide(x,y)  ((IsBlack(x)&&IsBlack(y))||(IsRed(x)&&IsRed(y)))

typedef struct _chessmanposition
{
	BYTE		x;
	BYTE		y;
}CHESSMANPOS;

typedef struct _chessmove
{
	short	  	    ChessID;	//
	CHESSMANPOS	From;
	CHESSMANPOS	To;			//
	int			    Score;		// 
}CHESSMOVE;

#endif //define_h_