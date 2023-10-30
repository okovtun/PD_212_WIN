#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<string>
#include<vector>
#include"resource.h"

#define IDC_COMBO			1001
#define IDC_BUTTON_APPLY	1002
CONST CHAR* g_CURSOR[] = { "Busy.ani", "Normal Select.ani", "Working In Background.ani", "Move.ani" };

CONST CHAR g_sz_WINDOW_CLASS[] = "My Window Class";	//Имя класса окна

std::vector<std::string> LoadCurcorsFromDir(const std::string& directory);
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	/*
	-----------------------------
	hInstance - экземпляр исполняемого файла программы в оперативной памяти. 
	Если нужно обратиться к *.exe-файлу, то это можно сделать через hInstance.
	hInstance всегда можно получить при помощи функции GetModuleHandle(NULL).

	hPrevInst - предыдущий экземпляр программы. Этот параметр давно не используется.

	lpCmdLine - командная строка, из которой запустилась программа.
	Через эту командную строку в программу можно передать файл, или URL.
	lp - Long Pointer

	nCmdShow - режим отбражения окна, свернуто в окно, свернуто в панель задач, развернуто на весь экран.
	n - number (значение типа int)
	-----------------------------
	*/
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
	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);
	//CHAR sz_msg[MAX_PATH]{};
	//sprintf(sz_msg, "Resolution: %ix%i", screen_width, screen_height);
	//MessageBox(NULL, sz_msg, "Screen resolution", MB_OK);
	INT window_width = screen_width * 3 / 4;
	INT window_height = screen_height * 3 / 4;

	INT start_x = screen_width / 8;
	INT start_y = screen_height / 8;

	HWND hwnd = CreateWindowEx
	(
		NULL,	//ExStyle
		g_sz_WINDOW_CLASS,	//Class name
		g_sz_WINDOW_CLASS,	//Window name
		WS_OVERLAPPEDWINDOW,//У главного окна всегда будет такой стиль
		start_x, start_y,	//Position - Положение окна на экране
		window_width, window_height,	//Size - Размер окна
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
			WS_CHILD | WS_VISIBLE | CBN_DROPDOWN | WS_VSCROLL,
			10, 10,
			200, 200,
			hwnd,
			(HMENU)IDC_COMBO,
			GetModuleHandle(NULL),
			NULL
		);
		/*for (int i = 0; i < sizeof(g_CURSOR) / sizeof(g_CURSOR[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)g_CURSOR[i]);
		}*/
		CHAR sz_current_directory[MAX_PATH]{};
		GetCurrentDirectory(MAX_PATH, sz_current_directory);
		//MessageBox(hwnd, sz_current_directory, "Current dir", MB_OK);
		std::vector<std::string> cursors = LoadCurcorsFromDir("starcraft-original\\*");
		for (int i = 0; i < cursors.size(); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)cursors[i].c_str());
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
	case WM_SIZE:
	case WM_MOVE:
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		CHAR sz_message[MAX_PATH]{};
		sprintf(sz_message, "%s - Position: %ix%i, Size: %ix%i", 
			g_sz_WINDOW_CLASS, 
			rect.left, rect.top, 
			rect.right-rect.left, rect.bottom-rect.top
		);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_message);
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
std::vector<std::string> LoadCurcorsFromDir(const std::string& directory)
{
	std::vector<std::string> files;
	WIN32_FIND_DATA data;
	for (
		HANDLE hFind = FindFirstFile(directory.c_str(), &data);
		FindNextFile(hFind, &data);
		)
	{
		//const char* std::string::c_str() возвращает C-string, хранящийся в объекте std::string
		if (
			strcmp(strrchr(data.cFileName, '.'), ".cur") == 0 ||
			strcmp(strrchr(data.cFileName, '.'), ".ani") == 0
			)
			files.push_back(data.cFileName);
	}

	/*HANDLE hFind = FindFirstFile(directory.c_str(), &data);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			files.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data));
	}*/
	return files;
}