#include "Func.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

//int main(int argc, char* argv[])
//{
//		srand(time(NULL));
//		string a = randFirstPart();
//		cout << "Key: " << a << " " << ToHexString(xuly(md5(a))) << endl;
//	return 0;
//}

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
	srand(time(NULL));
	cout << "Press any key to get key!" << endl;
	cout << "Press X to exit!" << endl;
	key = toupper(_getch());
	if (key == 'X')
	{
		system("cls");
		exit(0);
	}
	else
	while (1)
	{
		system("cls");
		string a = randFirstPart();
		cout << "Congratulation! You got a key!" << endl;
		cout << "Key: " << a << " " << ToHexString(xuly(md5(a))) << endl;
		cout << "Press any key to generate" << endl;
		cout << "Press X to exit!" << endl;
		key = toupper(_getch());
		if(key == 'X')
		{
			system("cls");
			break;
		}
	}
	return 0;
}