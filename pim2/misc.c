#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#include "menu.h"
#include "files.h"

/* Arquivo com funções de auxílio ao sistema */

void setHorizontalSize() {
	// setlocale(LC_ALL, "Portuguese");
	// resolve o problema de acentuação porem buga todo o programa

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (console != INVALID_HANDLE_VALUE) {
		// Define o tamanho do buffer de tela
		COORD bufferSize;
		bufferSize.X = 170; // 100 colunas
		bufferSize.Y = 40;  // 50 linhas

		SetConsoleScreenBufferSize(console, bufferSize);

		// Define o tamanho da janela do console
		SMALL_RECT windowSize;
		windowSize.Left = 0;
		windowSize.Top = 0;
		windowSize.Right = 169;  // 100 colunas - 1
		windowSize.Bottom = 39; // 50 linhas - 1

		SetConsoleWindowInfo(console, TRUE, &windowSize);
	}

	// Obtém um identificador para o console atual
	HWND consoleWindow = GetConsoleWindow();

	if (consoleWindow != NULL) {
		// Obtém informações sobre a tela
		RECT consoleRect;
		GetWindowRect(consoleWindow, &consoleRect);

		// Obtém as dimensões da tela
		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		// Calcula as coordenadas para centralizar o console
		int consoleWidth = consoleRect.right - consoleRect.left;
		int consoleHeight = consoleRect.bottom - consoleRect.top;
		int consoleX = (screenWidth - consoleWidth) / 2;
		int consoleY = (screenHeight - consoleHeight) / 2;

		// Move o console para as coordenadas calculadas
		MoveWindow(consoleWindow, consoleX, consoleY, consoleWidth, consoleHeight, TRUE);
	}

}

void setVerticalSize() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (console != INVALID_HANDLE_VALUE) {
		// Define o tamanho do buffer de tela
		COORD bufferSize;
		bufferSize.X = 70; // 100 colunas
		bufferSize.Y = 40;  // 50 linhas

		SetConsoleScreenBufferSize(console, bufferSize);

		// Define o tamanho da janela do console
		SMALL_RECT windowSize;
		windowSize.Left = 0;
		windowSize.Top = 0;
		windowSize.Right = 69;  // 100 colunas - 1
		windowSize.Bottom = 39; // 50 linhas - 1

		SetConsoleWindowInfo(console, TRUE, &windowSize);
	}

	// Obtém um identificador para o console atual
	HWND consoleWindow = GetConsoleWindow();

	if (consoleWindow != NULL) {
		// Obtém informações sobre a tela
		RECT consoleRect;
		GetWindowRect(consoleWindow, &consoleRect);

		// Obtém as dimensões da tela
		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		// Calcula as coordenadas para centralizar o console
		int consoleWidth = consoleRect.right - consoleRect.left;
		int consoleHeight = consoleRect.bottom - consoleRect.top;
		int consoleX = (screenWidth - consoleWidth) / 2;
		int consoleY = (screenHeight - consoleHeight) / 2;

		// Move o console para as coordenadas calculadas
		MoveWindow(consoleWindow, consoleX, consoleY, consoleWidth, consoleHeight, TRUE);
	}
}

void loadLoadingScreen() {
	system("cls");
	FILE* fp1 = fopen(LOADING_SCREEN, "r");

	char loading_screen[100];

	while (fgets(loading_screen, sizeof(loading_screen), fp1) != NULL) {
		printf(loading_screen);
	}

	fclose(fp1);
	Sleep(500);
	system("cls");
}

int keyboardCheck() {
	int key;

	while (_kbhit() != 'x') {
		key = _getch();
		return key;
	}
}

void startProgram() {
	setHorizontalSize();
	loadScreen(INITIAL_SCREEN);
	Sleep(3000);
	
	selectMainMenuOption();
}

void endProgram() {
	loadScreen(FINAL_SCREEN);
	Sleep(2000);
	exit(0);
}
