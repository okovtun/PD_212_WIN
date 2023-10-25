#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<Windows.h>
#include "resource.h"

typedef struct
{
	CHAR achName[MAX_PATH];
	CHAR achPosition[12];
	int nGamesPlayed;
	int nGoalsScored;
} Human;

Human Number1[] =
{
	{ TEXT("Muller, Jonathan"), TEXT("Midfield"), 18, 4 },
	{ TEXT("Bugatty, Fernando"), TEXT("Forward"), 36, 12 },
	{ TEXT("Thomas, Duglas"), TEXT("Back"), 26, 0 },
	{ TEXT("Andrew, Valley"), TEXT("Back"), 24, 2 },
	
};

BOOL CALLBACK ListBoxExampleProc(HWND hDlg, UINT message,
	WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDC_LISTBOX), NULL, (DLGPROC)ListBoxExampleProc, 0);
	return 0;
}

BOOL CALLBACK ListBoxExampleProc(HWND hDlg, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		HWND hwndList = GetDlgItem(hDlg, IDC_LISTBOX);
		for (int i = 0; i < ARRAYSIZE(Number1); i++)
		{
			int pos = (int)SendMessage(hwndList, LB_ADDSTRING, 0,
				(LPARAM)Number1[i].achName);
			
			SendMessage(hwndList, LB_SETITEMDATA, pos, (LPARAM)i);
		}
		
		SetFocus(hwndList);
		//return TRUE;
	}

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			//return TRUE;
			break;
		case IDC_LISTBOX:
		{
			switch (HIWORD(wParam))
			{
			case LBN_SELCHANGE:
			{
				HWND hwndList = GetDlgItem(hDlg, IDC_LISTBOX);
				int lbItem = (int)SendMessage(hwndList, LB_GETCURSEL, 0, 0);
				int i = (int)SendMessage(hwndList, LB_GETITEMDATA, lbItem, 0);
				/*TCHAR buff[MAX_PATH];
				StringCbPrintf(buff, ARRAYSIZE(buff),
					TEXT("Position: %s\nGames played: %d\nGoals: %d"),
					Number1[i].achPosition, Number1[i].nGamesPlayed,
					Number1[i].nGoalsScored);*/
				//SetDlgItemText(hDlg, IDC_STATISTICS, buff);
				CHAR sz_buffer[MAX_PATH]{};
				SendMessage(hwndList, LB_GETTEXT, lbItem, (LPARAM)sz_buffer);
				CHAR sz_msg[MAX_PATH]{};
				sprintf(sz_msg, "Вы выбрали элемент №%i со значением \"%s\"", lbItem, sz_buffer);
				return TRUE;
			}
			}
		}
		//return TRUE;
		}
		break;
	case WM_CLOSE: EndDialog(hDlg, 0);
	}
	return FALSE;
}