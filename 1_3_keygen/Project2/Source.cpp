#include "Func.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

int main()
{
	FixConsoleWindow();
	//Get the window console handle(isn't the right code but works for these sample
	HWND ConsoleWindow;
	ConsoleWindow = GetForegroundWindow();

	//Getting the desktop hadle and rectangule
	HWND   hwndScreen;
	RECT   rectScreen;
	hwndScreen = GetDesktopWindow();
	GetWindowRect(hwndScreen, &rectScreen);

	//Set windows size(see the width problem)
	SetWindowPos(ConsoleWindow, NULL, 0, 0, 1000, 500, SWP_SHOWWINDOW);

	// Get the current width and height of the console
	RECT rConsole;
	GetWindowRect(ConsoleWindow, &rConsole);
	int Width = rConsole.left = rConsole.right;
	int Height = rConsole.bottom - rConsole.top;

	//caculate the window console to center of the screen	
	int ConsolePosX;
	int ConsolePosY;
	ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - Width / 2);
	ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - Height / 2);
	SetWindowPos(ConsoleWindow, NULL, ConsolePosX, ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);
	int key;
	while (1)
	{
		system("cls");
		string a;
		cout << "Nhap vao Username: " << endl;
		cin >> a;
		if (RightUsername(a))
		{
			cout << "Password: " << RightPassword(SumASCII(a)) << endl;
		}
		else cout << "Username khong hop le!" << endl;
		cout << "Press any key to continue..." << endl;
		cout << "Press X to exit!" << endl;
		key = toupper(_getch());
		if (key == 'X')
		{
			system("cls");
			exit(0);
		}
	}
		return 0;
}