#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "menu.h"
#include "files.h"

/* Arquivo com funções de auxílio ao sistema */

char keyboardCheck() {
	char key;

	while (_kbhit() != 'x') {
		key = _getch();
		return key;
	}
}

void threeSecTimer() {
	int time = 0;
	while (time < 3) {
		printf(" .");
		Sleep(1000);
		time++;
	}
}

void fiveSecTimer() {
	int time = 0;
	while (time < 6) {
		Sleep(1000);
		time++;
	}
}

void startProgram() {

	HWND consoleWindow = GetConsoleWindow();
	if (consoleWindow != NULL) {
		RECT consoleRect;
		GetWindowRect(consoleWindow, &consoleRect);

		int consoleWidth = consoleRect.right - consoleRect.left;
		int consoleHeight = consoleRect.bottom - consoleRect.top;

		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		int newX = (screenWidth - consoleWidth) / 2;
		int newY = (screenHeight - consoleHeight) / 2;

		MoveWindow(consoleWindow, newX, newY, consoleWidth, consoleHeight, TRUE);
	}

	readFile(MAIN_SCREEN);
	fiveSecTimer();
	selectMainMenuOption();
}
