#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LRESULT)hIcon);
		SetFocus(GetDlgItem(hwnd, IDC_EDIT_LOGIN));
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_COPY:
		{
			//1) Создаем буфер чтения:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			//2) Получаем обработчики текстовых полей:
			HWND hLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);	//Функция GetDlgItem() по ID-ресурса дочернего окна возвращает HWND соответствующего дочернего окна.
			HWND hPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			//3) Читаем текст из текстового поля 'Login':
			SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			//4) Загружаем содржимое текстового буфера в поле 'Password':
			SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		break;
		case IDOK:		MessageBox(hwnd, "Была нажата кнопка OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:	EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:	EndDialog(hwnd, 0);
	}
	return FALSE;
}