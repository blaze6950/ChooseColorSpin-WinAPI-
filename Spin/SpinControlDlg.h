#pragma once
#include "header.h"

class CSpinControlDlg
{
public:
	CSpinControlDlg(void);
public:
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static CSpinControlDlg* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, HWND hwndCtl, UINT code, int pos);
	void Cls_OnClose(HWND hwnd);
	HWND hDialog, hRed, hEdit2, hGreen, hEdit3, hBlue, hEdit4, hResult;
};
