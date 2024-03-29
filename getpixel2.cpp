// getpixel.cpp : definiuje punkt wejścia dla aplikacji
//

#include "stdafx.h"
#include "getpixel2.h"
#include <windowsx.h>

#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bieżące wystąpienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytułu
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna głównego

												// Przekaż dalej deklaracje funkcji dołączonych w tym module kodu:
												//ATOM                MyRegisterClass(HINSTANCE hInstance);
												//BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: W tym miejscu umieść kod.
	HWND hWnd = GetDesktopWindow();
	HDC hdc = GetDC(GetDesktopWindow());
	int rgb = 0;
	//int xPos = GET_X_LPARAM(lParam);
	//int yPos = GET_Y_LPARAM(lParam);
	POINT p;
	POINT o;
	//int *rgb_zmiana = &rgb,
	int i = 0;
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0x13; // hardware scan code for key
	ip.ki.time = 1;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = 0x52; // virtual-key code for the "r" key
	MessageBox(hWnd, L"Po wciśnięciu OK i odczekaniu 2 sekund zostaną\nzarejestrowane koordynaty myszki.", L"Info", MB_OK | MB_ICONINFORMATION);
	Sleep(2000);
	if (GetCursorPos(&p))
	{
		rgb = GetPixel(hdc, p.x, p.y);

		while (rgb)
		{
			if (GetPixel(hdc, p.x, p.y) != rgb)
			{
				
				ip.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &ip, sizeof(INPUT));
				ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &ip, sizeof(INPUT));
				break;
			}
		}
	}

	DestroyWindow(hWnd);
	PostQuitMessage(0);
	return 0;

}

