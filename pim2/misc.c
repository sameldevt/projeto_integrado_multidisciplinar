#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#include "menu.h"
#include "files.h"

/* Arquivo com funções de auxílio ao sistema */

void loadLoadingScreen() {
	FILE* fp1 = fopen(LOADING_SCREEN, "r");

	char loading_screen[100];

	while (fgets(loading_screen, sizeof(loading_screen), fp1) != NULL) {
		printf(loading_screen);
	}

	fclose(fp1);
	Sleep(3000);
	system("cls");
}

int keyboardCheck() {
	int key;

	while (_kbhit() != 'x') {
		key = _getch();
		return key;
	}
}

void threeSecTimer() {
	int time = 0;
	while (time < 3) {
		printf(" .");
		Sleep(500);
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

	// setlocale(LC_ALL, "Portuguese");
	// resolve o problema de acentuação porem buga todo o programa

	HWND consoleWindow = GetConsoleWindow();

	if (consoleWindow != NULL) {
		// Maximize the console window
		ShowWindow(consoleWindow, SW_MAXIMIZE);
	}

	readFile(INITIAL_SCREEN);
	Sleep(3000);
	
	selectMainMenuOption();
}

void endProgram() {

}
