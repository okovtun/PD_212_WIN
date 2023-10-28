#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"resource.h"

#define IDC_COMBO			1001
#define IDC_BUTTON_APPLY	1002
CONST CHAR* g_CURSOR[] = { "Busy.ani", "Normal Select.ani", "Working In Background.ani", "Move.ani" };

CONST CHAR g_sz_WINDOW_CLASS[] = "My Window Class";	//Имя класса окна

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	//cb - Count Bytes (Количемство Байт)
	wc.cbWndExtra = 0;	//Дополнительные Байты окна
	wc.cbClsExtra = 0;	//Дополнительные Байты класса окна
	wc.style = 0;		//Стиль окна

	//wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CPU));
	//wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_RAM));	//Sm - Small
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = (HICON)LoadImage(hInstance, "palm.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hIconSm = (HICON)LoadImage(hInstance, "star.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	//wc.hCursor = (HCURSOR)LoadImage(hInstance, "star.ani", IMAGE_CURSOR, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hbrBackground = HBRUSH(COLOR_WINDOW + 1);

	wc.hInstance = hInstance;	//hInstance - это экземпляр исполняемого файла программы в памяти
	//Функция WinMain() принимает hInstance как параметр, и поэтому к нему есть прямой доступ,
	//В любой другой функции 'hInstance' всегда можно получить при помощи функции GetModuleHandle(NULL)
	wc.lpfnWndProc = WndProc;	//Указатель на процедуру окна
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_WINDOW_CLASS;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) Создание окна:
	HWND hwnd = CreateWindowEx
	(
		NULL,	//ExStyle
		g_sz_WINDOW_CLASS,	//Class name
		g_sz_WINDOW_CLASS,	//Window name
		WS_OVERLAPPEDWINDOW,//У главного окна всегда будет такой стиль
		CW_USEDEFAULT, CW_USEDEFAULT,	//Position - Положение окна на экране
		CW_USEDEFAULT, CW_USEDEFAULT,	//Size - Размер окна
		NULL,	//Parent Window
		//---------------------------
		NULL,	//hMenu - для главного окна этот падаметр содержит ID_ресурса меню.
				//Для дочернего окна, которое является элементом другого окна, в hMenu передается ID_ресурса этого элемента
		//---------------------------
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//3) Запуск цикла сообщений:
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HCURSOR hCursor;
	switch (uMsg)
	{
	case WM_CREATE:
	{
		HWND hCombo = CreateWindowEx
		(
			NULL,
			"ComboBox",
			"",
			WS_CHILD | WS_VISIBLE | CBN_DROPDOWN,
			10, 10,
			200, 200,
			hwnd,
			(HMENU)IDC_COMBO,
			GetModuleHandle(NULL),
			NULL
		);
		for (int i = 0; i < sizeof(g_CURSOR) / sizeof(g_CURSOR[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)g_CURSOR[i]);
		}

		HWND hButton = CreateWindowEx
		(
			NULL,
			"Button",
			"Apply",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			220, 10,
			100, 24,
			hwnd,
			(HMENU)IDC_BUTTON_APPLY,
			GetModuleHandle(NULL),
			NULL
		);

	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_APPLY:
		{
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO);
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			CHAR sz_filename[_MAX_FNAME]{};
			CHAR sz_filepath[_MAX_PATH] = "starcraft-original\\";
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_filename);
			strcat(sz_filepath, sz_filename);
			//MessageBox(hwnd, sz_filepath, "Info", MB_OK);
			//HCURSOR 
			hCursor = (HCURSOR)LoadImage(
				GetModuleHandle(NULL),
				sz_filepath,
				IMAGE_CURSOR,
				LR_DEFAULTSIZE, LR_DEFAULTSIZE,
				LR_LOADFROMFILE);
			//SetCursorPos(500, 200);
			SetClassLong(hwnd, GCL_HCURSOR, (LONG)hCursor);
			SetClassLong(GetDlgItem(hwnd, IDC_BUTTON_APPLY), GCL_HCURSOR, (LONG)hCursor);
			SetClassLong(GetDlgItem(hwnd, IDC_COMBO), GCL_HCURSOR, (LONG)hCursor);
			//SetCursor(hCursor);
			return FALSE;
		}
		break;
		}
	}
	break;
	case WM_DESTROY:PostQuitMessage(0); break;
	case WM_CLOSE:	DestroyWindow(hwnd); break;
	default:		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return NULL;
}