//ComboBox
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<Windows.h>
#include"resource.h"

CONST CHAR* g_sz_VALUES[] = { "This", "is", "my", "first", "Combo", "Box" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProcAdd(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//hwnd - Handler to Window (Обработчик окна);
	//uMsg - unsignedMessage	Сообщение;
	//wParam, lParam - параметры сообщения;
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
		for (int i = 0; i < sizeof(g_sz_VALUES) / sizeof(g_sz_VALUES[0]); i++)
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)g_sz_VALUES[i]);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_ADD:
		{
			DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG_ADD), hwnd, DlgProcAdd, 0);
		}
		break;
		case IDOK:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
			CHAR sz_message[SIZE]{};
			sprintf(sz_message, "Вы выбрали элемент № %i, со значением \"%s\"", i, sz_buffer);
			//%i - integer
			//%s - string
			MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);
		}
		break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}
BOOL CALLBACK DlgProcAdd(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetFocus(GetDlgItem(hwnd, IDC_EDIT_ADD));
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE]{};
			HWND hEdit = GetDlgItem(hwnd, IDC_EDIT_ADD);
			SendMessage(hEdit, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);

			HWND parent = GetParent(hwnd);
			HWND hCombo = GetDlgItem(parent, IDC_COMBO1);
			if (SendMessage(hCombo, CB_FINDSTRING, -1, (LPARAM)sz_buffer) == CB_ERR)
			{
				if (strlen(sz_buffer) == 0)break;
				SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)sz_buffer);
				EndDialog(hwnd, 0);
			}
			else
			{
				MessageBox(hwnd, "Такое значение уже есть", "Info", MB_OK | MB_ICONINFORMATION);
			}

		}
		break;
		case IDCANCEL:EndDialog(hwnd, 0); break;
		}
	}
	break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}