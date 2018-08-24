#include "SpinControlDlg.h"

CSpinControlDlg* CSpinControlDlg::ptr = NULL;

CSpinControlDlg::CSpinControlDlg(void)
{
	ptr = this;
}

void CSpinControlDlg::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL CSpinControlDlg::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) 
{
	hDialog = hwnd;
	hRed = GetDlgItem(hDialog, IDC_SPIN1);
	hEdit2 = GetDlgItem(hDialog, IDC_EDIT2);
	hGreen = GetDlgItem(hDialog, IDC_SPIN2);
	hEdit3 = GetDlgItem(hDialog, IDC_EDIT3);
	hBlue = GetDlgItem(hDialog, IDC_SPIN3);
	hEdit4 = GetDlgItem(hDialog, IDC_EDIT4);
	hResult = GetDlgItem(hDialog, IDC_PROGRESS2);

	// установим диапазон счетчика
	SendMessage(hRed, UDM_SETRANGE32, 0, 255);
	SendMessage(hGreen, UDM_SETRANGE32, 0, 255);
	SendMessage(hBlue, UDM_SETRANGE32, 0, 255);

	// зададим правило приращения
	UDACCEL pAcceleration[3] = {{1,1}, {3,10}, {5,50}};
	SendMessage(hRed, UDM_SETACCEL, 3, LPARAM(pAcceleration));
	SendMessage(hGreen, UDM_SETACCEL, 3, LPARAM(pAcceleration));
	SendMessage(hBlue, UDM_SETACCEL, 3, LPARAM(pAcceleration));

	// установим приятеля
	SendMessage(hRed, UDM_SETBUDDY, WPARAM(hEdit2), 0);
	SendMessage(hGreen, UDM_SETBUDDY, WPARAM(hEdit3), 0);
	SendMessage(hBlue, UDM_SETBUDDY, WPARAM(hEdit4), 0);

	SetWindowText(hEdit2, TEXT("0"));
	SetWindowText(hEdit3, TEXT("0"));
	SetWindowText(hEdit4, TEXT("0"));
	return TRUE;
}

void CSpinControlDlg::Cls_OnCommand(HWND hwnd, HWND hwndCtl, UINT code, int pos)
{
	static int red = 0, green = 0, blue = 0;
	int nCurrrentPosition = SendMessage(hwndCtl, UDM_GETPOS32, 0, 0);
	if (hwndCtl == hRed)
	{
		red = nCurrrentPosition;
	}
	else if (hwndCtl == hGreen)
	{
		green = nCurrrentPosition;
	}
	else{
		blue = nCurrrentPosition;
	}
	SendMessage(hResult, PBM_SETBKCOLOR, 0, RGB(red, green, blue));
}

BOOL CALLBACK CSpinControlDlg::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_VSCROLL, ptr->Cls_OnCommand);
	}
	return FALSE;
}