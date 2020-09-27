#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "WindowsProject2.h"
#include<windows.h>
#include <cstring>
#include <fstream>
#include <commdlg.h>
#include <stdlib.h>
#include <mmsystem.h>
#include "Source1.cpp"
#pragma comment (lib, "comctl32.lib")
#pragma comment (lib, "Winmm.lib")
#include <ctime>
#include <commctrl.h>
#include "resource1.h"
#define IDD_DIALOG1  131


#define IDT_TOOLBAR 400
#define MAX_PATH	102
		char filename[MAX_PATH] = "";
		
		
		
		TBBUTTON tbb[] = 
		{
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{11, 5, TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{1, 31,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{0, 30,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},		
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},
			{0,0,TBSTATE_ENABLED,TBSTYLE_SEP,0L,1},


			{2, 21, TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{3, 22,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{4, 23,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{5, 24, TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{6, 25,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{7, 26,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{8, 27, TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{9, 28,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0},
			{10, 29,TBSTATE_ENABLED, TBSTYLE_BUTTON,0,0,0,0}

		};
		
		int flg = 0;
		LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
		char szProgName[] = "Судоку";
		int CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			static char text[50] = "";
			switch (msg)
			{
			case  WM_COMMAND:
				switch (LOWORD(wParam))
				{
				case IDOK:
					flg = 1;
					EndDialog(hwnd, 0);
					return 1;
					break;
				case IDCANCEL:
					flg = -1;
					EndDialog(hwnd, 0);
					return 0;
					break;
				}
				break;

			case WM_CLOSE:
				EndDialog(hwnd, 0);
				break;
			}
			return 0;
		}
		int CALLBACK DlgSpravkaProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			switch (msg)
			{
			case  WM_COMMAND:
				switch (LOWORD(wParam))
				{
				case IDOK:
					EndDialog(hwnd, 0);
					return 1;
					break;
				}
				break;

			case WM_CLOSE:
				EndDialog(hwnd, 0);
				break;
			}
			return 0;
		}
		int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
		{
			HWND hWnd;
			MSG lpMsg;
			WNDCLASS w;

			w.lpszClassName = (LPCWSTR)szProgName;
			w.hInstance = hInstance;
			w.lpfnWndProc = WndProc;
			w.hCursor = LoadCursor(NULL, IDC_ARROW);
			w.hIcon =  LoadIcon(hInstance, MAKEINTRESOURCE(108));
			w.lpszMenuName = 0;
			w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
			w.style = CS_HREDRAW | CS_VREDRAW;
			w.cbClsExtra = 0;
			w.cbWndExtra = 0;

			if (!RegisterClass(&w))
				return 0;

			hWnd = CreateWindow((LPCWSTR)szProgName, L" Судоку", WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZE,
				100, 100, W, H,
				(HWND)NULL, //идентификатор родительского окна
				(HMENU)NULL, //идентификатор меню
				(HINSTANCE)hInstance, //идентификатор экземпляра программы
				(HINSTANCE)NULL); //отсутствие дополнительных параметров
				//Выводим окно из памяти на экран
			
			ShowWindow(hWnd, nCmdShow);
			//Обновим содержимое окна
			UpdateWindow(hWnd);
			while (GetMessage(&lpMsg, NULL, 0, 0))
			{
				
				TranslateMessage(&lpMsg);
				DispatchMessage(&lpMsg);
				
			}
			return(lpMsg.wParam);
		}
		
		LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
		{
			HDC hdc;
			HINSTANCE hInst = NULL;
			PAINTSTRUCT ps;
			LOGFONT lf;
			HFONT hFont;
			HBRUSH hBrush;
			HPEN hPen;
			RECT r = { 0,0,W,H };
			static RECT rx = { 60,68,100,108 }, rx1;
			static OPENFILENAME of;
			static HMENU hmenu = CreateMenu(), popmenu = CreatePopupMenu(), popmenu1 = CreatePopupMenu(), popmenu2 = CreatePopupMenu(); 
			static int mm = 1, i, j;
			static bool kk = 0, sound = 0, sound1 = 0, flag = 0, dialog =  0, flags = 0;
			static HWND  hBtn, hStatusWindow, hwndToolBar, hDial;
			static sudoku sud;
			static int xscr = 0, yscr = 0, minute = 0, second = 0, xscr1 = 0, yscr1 = 0;
			static char time[20] = "", tm[20] = "", stat[20] = "";
			static HBITMAP hBitmap;
			static HICON hIcon;
			static int pParts[3], prov = 0;
			SYSTEMTIME st;
			switch (messg)
			{
			case WM_CREATE:
				AppendMenu(hmenu, MF_STRING | MF_POPUP, (UINT)popmenu, L"Новая игра");
				AppendMenu(hmenu, MF_STRING | MF_POPUP, (UINT)popmenu1, L"Параметры");
				AppendMenu(hmenu, MF_STRING, 42, L"Cправка");
				AppendMenu(popmenu, MF_STRING, 1, L"Легкий");
				AppendMenu(popmenu, MF_STRING, 2, L"Средний");
				AppendMenu(popmenu, MF_STRING, 3, L"Сложный");
				AppendMenu(popmenu, MF_STRING, 4, L"На время");
				AppendMenu(popmenu, MF_STRING, 5, L"Сдаться");
				AppendMenu(popmenu1, MF_STRING | MF_UNCHECKED, 41, L"Звук");
			
				SetMenu(hWnd, hmenu);
				hwndToolBar = CreateToolbarEx(hWnd,
					WS_CHILD | WS_VISIBLE | WS_BORDER | TBSTYLE_TOOLTIPS, IDT_TOOLBAR, 1, GetModuleHandle(NULL), IDR_TOOLBAR1,
					(LPCTBBUTTON)tbb, 37, 0, 0, 0, 0, sizeof(TBBUTTON));
				hStatusWindow = CreateWindow(STATUSCLASSNAME, L"",
					WS_CHILD | WS_VISIBLE | WS_BORDER | CCS_BOTTOM,
					0, 0, 0, 0, hWnd, (HMENU)0, hInst, NULL);
				pParts[0] = 200;//250;
				SendMessage(hStatusWindow, SB_SETTEXTA, 0, (LPARAM)" Уровень сложности:");
				pParts[1] = 400;//500;
				pParts[2] = 500;
				SendMessage(hStatusWindow, SB_SETPARTS, 3, (LPARAM)pParts);
				SetTimer(hWnd, 101, 1000, NULL);
				if (!sud.flag)
					DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
				else
					flg = -1;
				break;
			case WM_COMMAND:
				switch (LOWORD(wParam))
				{
				case 1:
					sud.show(1);
					CheckMenuItem(popmenu, 1, MF_CHECKED);
					if (mm != 1)
						CheckMenuItem(popmenu, mm, MF_UNCHECKED);
					mm = 1;
					SendMessage(hStatusWindow, SB_SETTEXTA, 0, (LPARAM)" Уровень сложности: Легкий");
					minute = 0;
					second = 0;
					if (sound)
						if (sound1)
							PlaySound(L"grushin.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					sound1 = 0;
					InvalidateRect(hWnd, 0, 1);
					break;
				case 2:
					sud.show(2);
					CheckMenuItem(popmenu, 2, MF_CHECKED);
					if (mm != 2)
						CheckMenuItem(popmenu, mm, MF_UNCHECKED);
					mm = 2;
					SendMessage(hStatusWindow, SB_SETTEXTA, 0, (LPARAM)" Уровень сложности: Средний");
					minute = 0;
					second = 0;
					if (sound)
						if (sound1)
							PlaySound(L"grushin.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					sound1 = 0;
					InvalidateRect(hWnd, 0, 1);
					break;
				case 3:
					sud.show(3);
					CheckMenuItem(popmenu, 3, MF_CHECKED);
					if (mm != 3)
						CheckMenuItem(popmenu, mm, MF_UNCHECKED);
					mm = 3;
					SendMessage(hStatusWindow, SB_SETTEXTA, 0, (LPARAM)" Уровень сложности: Сложный");
					GetLocalTime(&st);
					minute = 0;
					second = 0;
					if (sound)
						if (sound1)
							PlaySound(L"grushin.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					sound1 = 0;
					
					
					InvalidateRect(hWnd, 0, 1);
					break;
				case 4:
					sud.show(1);
					minute = 0;
					second = 15;
					flags = 0;
					CheckMenuItem(popmenu, 4, MF_CHECKED);
					if (mm != 4)
						CheckMenuItem(popmenu, mm, MF_UNCHECKED);
					mm = 4;
					if (sound)
						if (!sound1)
							PlaySound(L"lindsey.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					sound1 = 1;
					
					SendMessage(hStatusWindow, SB_SETTEXTA, 0, (LPARAM)" Уровень сложности: На время");
					break;
				case 5:
					sud.show(4);
					InvalidateRect(hWnd, 0, 1);
					break;
				case 21:
					prov = sud.add_us(yscr, xscr, 1);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 22:
					prov = sud.add_us(yscr, xscr, 2);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 23:
					prov = sud.add_us(yscr, xscr, 3);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 24:
					prov = sud.add_us(yscr, xscr, 4);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 25:
					prov = sud.add_us(yscr, xscr, 5);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 26:
					prov = sud.add_us(yscr, xscr, 6);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 27:
					prov = sud.add_us(yscr, xscr, 7);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 28:
					prov = sud.add_us(yscr, xscr, 8);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 29:
					prov = sud.add_us(yscr, xscr, 9);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 30:
					sud.add_us(yscr, xscr, 0);
					break;
				case 31:
					sud.tooltip(yscr, xscr);
					break;
				case 41:
					if (!sound)
					{
						if (!sound)
							PlaySound(L"grushin.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						else 
							PlaySound(L"lindsey.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						CheckMenuItem(popmenu1, 41, MF_CHECKED);
						sound = 1;
					}
					else
					{
						PlaySound(0, 0, SND_PURGE);
						CheckMenuItem(popmenu1, 41, MF_UNCHECKED);
						sound = 0;
					}
					break;
				case 42:
					DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2),hWnd, &DlgSpravkaProc, 0);
					break;
				}
				InvalidateRect(hWnd, 0, 1);
				break;
			case WM_LBUTTONDOWN:
				xscr = LOWORD(lParam);
				yscr = HIWORD(lParam);
				xscr -= 60;
				yscr -= 68;
				xscr /= 40;
				yscr /= 40;
				if (xscr >= 0 && xscr < 9 && yscr >= 0 && yscr < 9)
				{
					rx.left = xscr * 40 + 60;
					rx.top = yscr * 40 + 68;
					rx.right = rx.left + 40;
					rx.bottom = rx.top + 40;
				};
				InvalidateRect(hWnd, 0, 1);
				break;
			case WM_TIMER:

				if (mm != 4)
				{
					if (flg == 1)
					{
						minute = second = 0;
						InvalidateRect(hWnd, 0, 1);
						PlaySound(L"grushin.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						CheckMenuItem(popmenu1, 41, MF_CHECKED);
						sound = 1;
						flg = 0;
					}
					if (flg == -1)
					{
						sud.show(1);
						SendMessage(hStatusWindow, SB_SETTEXTA, 0, (LPARAM)" Уровень сложности: Легкий");
						CheckMenuItem(popmenu, 1, MF_CHECKED);
						mm = 1;
						InvalidateRect(hWnd, 0, 1);
						PlaySound(L"grushin.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						CheckMenuItem(popmenu1, 41, MF_CHECKED);
						sound = 1;
						flg = 0;
						minute = 0;
						second = -1;
					}
					second++;
					if (second == 60)
					{
						second = 0;
						minute++;
					}
				}
				else
				{
					if (!flags && (sud.procent()!=100))
					{
						if (second || (minute && !second))
						{
							if (second) second--;
							if (second == 0) if (minute)
							{
								minute--;
								second = 59;
							}
							if (!second && !minute) flags = 1;
							if (prov)
							{
								prov = 0;
								second += 15;
								if (second >= 60)
								{
									second -= 60;
									minute++;
								}
							}
							
						}
						if (!second && !minute)
						{

							if (sud.kolvo() > 0)
							{
								second = 15;
							}

							sud.hide();
							InvalidateRect(hWnd, 0, 1);
						}
						
					}
					
				}
				sprintf(tm, "%02d", minute);
				strcpy(time, tm);
				strcat(time, ":");
				sprintf(tm, "%02d", second);
				strcat(time, tm);
				SendMessage(hStatusWindow, SB_SETTEXTA, 2, (LPARAM)time);
				break;
			case WM_KEYDOWN:
				switch (wParam)
				{
				case VK_LEFT:
					xscr--;
					if (xscr < 0) xscr = 0;
					rx.left = xscr * 40 + 60;
					rx.top = yscr * 40 + 68;
					rx.right = rx.left + 40;
					rx.bottom = rx.top + 40;
					break;
				case VK_RIGHT:
					xscr++;
					if (xscr > 8) xscr = 8;
					rx.left = xscr * 40 + 60;
					rx.top = yscr * 40 + 68;
					rx.right = rx.left + 40;
					rx.bottom = rx.top + 40;
					break;
				case VK_UP:
					yscr--;
					if (yscr < 0) yscr = 0;
					rx.left = xscr * 40 + 60;
					rx.top = yscr * 40 + 68;
					rx.right = rx.left + 40;
					rx.bottom = rx.top + 40;
					break;
				case VK_DOWN:
					yscr++;
					if (yscr > 8) yscr = 8;
					rx.left = xscr * 40 + 60;
					rx.top = yscr * 40 + 68;
					rx.right = rx.left + 40;
					rx.bottom = rx.top + 40;
					break;
				case VK_NUMPAD1:
					prov = sud.add_us(yscr, xscr, 1);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD2:
					prov = sud.add_us(yscr, xscr, 2);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD3:
					prov = sud.add_us(yscr, xscr, 3);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD4:
					prov = sud.add_us(yscr, xscr, 4);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD5:
					prov = sud.add_us(yscr, xscr, 5);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD6:
					prov = sud.add_us(yscr, xscr, 6);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD7:
					prov = sud.add_us(yscr, xscr, 7);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD8:
					prov = sud.add_us(yscr, xscr, 8);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_NUMPAD9:
					prov = sud.add_us(yscr, xscr, 9);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case VK_BACK:
					sud.add_us(yscr, xscr, 0);
					break;
				case 0x31:
					prov = sud.add_us(yscr, xscr, 1);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x32:
					prov = sud.add_us(yscr, xscr, 2);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x33:
					prov = sud.add_us(yscr, xscr, 3);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x34:
					prov = sud.add_us(yscr, xscr, 4);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x35:
					prov = sud.add_us(yscr, xscr, 5);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x36:
					prov = sud.add_us(yscr, xscr, 6);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x37:
					prov = sud.add_us(yscr, xscr, 7);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x38:
					prov = sud.add_us(yscr, xscr, 8);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				case 0x39:
					prov = sud.add_us(yscr, xscr, 9);
					if (xscr == xscr1 && yscr == yscr1)
						prov = 0;
					else
					{
						xscr1 = xscr;
						yscr1 = yscr;
					}
					break;
				}
				InvalidateRect(hWnd, 0, 1);
				break;
			case WM_PAINT:
				hdc = BeginPaint(hWnd, &ps);
				rx1 = rx;
				rx1.left += 5;
				rx1.top += 5;
				rx1.bottom -= 4;
				rx1.right -= 4;
				FillRect(hdc, &rx, HBRUSH(CreateSolidBrush(RGB(0, 255, 0))));
				FillRect(hdc, &rx1, HBRUSH(CreateSolidBrush(RGB(255, 255, 255))));
				strcpy((char*)lf.lfFaceName, "Times New Roman");
				lf.lfHeight = 30;
				lf.lfItalic = 0;
				lf.lfStrikeOut = 0;
				lf.lfUnderline = 0;
				lf.lfWidth = 10;
				lf.lfWeight = 70;
				lf.lfCharSet = DEFAULT_CHARSET;
				lf.lfPitchAndFamily = DEFAULT_PITCH;
				lf.lfEscapement = 0;
				hFont = CreateFontIndirect(&lf);
				SelectObject(hdc, hFont);
				sud.draw(hdc, yscr, xscr);
				sprintf(stat, "Заполнено на %.2f", sud.procent());
				strcat(stat, "%");
				SendMessage(hStatusWindow, SB_SETTEXTA, 1, (LPARAM)stat);
				if (sud.procent() == 100)
				{
					SetTextColor(hdc, RGB(255, 0, 0));
					lf.lfHeight = 100;
					lf.lfWidth = 18;
					hFont = CreateFontIndirect(&lf);
					SelectObject(hdc, hFont);
					TextOut(hdc, 64, 140, L" ВЫ ВЫИГРАЛИ!!! ", 16);
				}
				if (flags)
				{
					SetTextColor(hdc, RGB(255, 0, 0));
					lf.lfHeight = 100;
					lf.lfWidth = 18;
					hFont = CreateFontIndirect(&lf);
					SelectObject(hdc, hFont);
					TextOut(hdc, 66, 140, L"ВЫ ПРОИГРАЛИ:(", 14);
				}
				EndPaint(hWnd, &ps);
				break;
			case WM_SIZE:
				GetWindowRect(hWnd, &r);
				W = r.right;
				break;
			case WM_DESTROY:

				PostQuitMessage(0);

				break;
			default:
				return(DefWindowProc(hWnd, messg, wParam, lParam));
			}

			return 0;
		};