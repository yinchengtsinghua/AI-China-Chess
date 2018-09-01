; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewGame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "chess.h"

ClassCount=4
Class1=CChessApp
Class2=CChessDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CHESS_DIALOG
Class4=CNewGame
Resource4=IDD_NEWGAME

[CLS:CChessApp]
Type=0
HeaderFile=chess.h
ImplementationFile=chess.cpp
Filter=N

[CLS:CChessDlg]
Type=0
HeaderFile=chessDlg.h
ImplementationFile=chessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CChessDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=chessDlg.h
ImplementationFile=chessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHESS_DIALOG]
Type=1
Class=CChessDlg
ControlCount=2
Control1=IDC_NODECOUNT,static,1342308352
Control2=IDC_NEWGAME,button,1342242816

[DLG:IDD_NEWGAME]
Type=1
Class=CNewGame
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_LISTENGINE,listbox,1352728833
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_PLY,msctls_updown32,1342177334
Control6=IDC_STATIC,static,1342308352

[CLS:CNewGame]
Type=0
HeaderFile=NewGame.h
ImplementationFile=NewGame.cpp
BaseClass=CDialog
Filter=D
LastObject=CNewGame
VirtualFilter=dWC

