#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"
#include "payment.h"
#include "misc.h"
#include "menu.h"
#include "entry.h"
#include "arts.h"

void selectThemeOption() {
	int key;
	
	loadLoadingScreen();

	while (_kbhit() == NULL) {
		loadScreen(MENU_THEMES_CHOICE);
		key = _getch();

		switch (key) {
		case 49:
			loadScreen(MODERN_WEEK_SCREEN);
			Sleep(1500);
			if (loadArts(ARTS_MODERN_WEEK)) {
				continue;
			}
		case 50:
			loadScreen(SANTOS_DUMONT_SCREEN);
			Sleep(1500);
			if (loadArts(ARTS_SANTOS_DUMONT)) {
				continue;
			}
		case 51:
			loadScreen(OLIMPIC_GAMES_SCREEN);
			Sleep(1500);
			if (loadArts(ARTS_OLIMPIC_GAMES)) {
				continue;
			}
		case 52:
			loadScreen(TECNOLOGY_SECURITY_SCREEN);
			Sleep(1500);
			if (loadArts(ARTS_TECNOLOGY_SECURITY)) {
				continue;
			}
		case 81:
		case 113:
			/* Volta para o menu principal*/
			return 1;
		default:
			loadScreen(INVALID_OPTION_SCREEN);
			Sleep(1500);
			loadLoadingScreen();
			continue;
		}
	}
}

int selectPaymentOption() {
	loadLoadingScreen();
	int key;

	while (_kbhit() == NULL) {
		loadScreen(MENU_PAYMENT);
		key = _getch();

		switch (key) {
		case 49: 
			if (verifyCardPayment()) {
				break;
			}
		case 50: 
			if (verifyPixPayment()) {
				break;
			}
		case 81:
		case 113:
			/* Volta para o menu principal*/
			return 1;
		default:
			// loadFailScreen();
			continue;
		}
		break;
	}

	selectThemeOption();
}


int selectHalfPriceEntry() {
	int key;

	while (_kbhit() == NULL) {
		loadScreen(MENU_HALFPRICE_ENTRY);
		key = _getch();
		switch (key) {
		case 49:
			return 0;
		case 50:
			return 1;
		default:
			continue;
		}
		Sleep(500);
	}
}

int selectFreeEntry() {
	int key;

	while (_kbhit() == NULL) {
		loadScreen(MENU_FREE_ENTRY);
		key = _getch();
		switch (key) {
		case 49:
			return 0;
		case 50:
			return 1;
		default:
			continue;
		}
		Sleep(500);
	}
}

int selectTicketMenuOption() {
	loadLoadingScreen();
	int key;

	while (_kbhit() == NULL) {
		loadScreen(MENU_BUY_TICKETS);
		key = _getch();

		switch (key) {
		case 49: 
			if (verifyPersonEntry()) {
				break;
			}
		case 50: 
			if (selectHalfPriceEntry()) {
				if (verifyDisabledPersonEntry()) {
					break;
				}
			}
			else {
				if (verifyStudentEntry()) {
					break;
				}
			}
		case 51: 
			if (selectFreeEntry()) {
				if (verifySeniorEntry()) {
					break;
				}
			}
			else {
				if (verifyJuniorEntry()) {
					break;
				}
			}
		case 52: 
			if (verifyDisabledPersonEntry()) {
				break;
			}
		case 81:
		case 113:
			/* Volta para o menu principal*/
			return 1;
		default:		
			continue;
		}
		break;
	}

	selectPaymentOption();
}

void selectMainMenuOption() {
	int key;

	while (_kbhit() == NULL) {
		loadScreen(MENU_MAIN);
		key = _getch();

		switch (key) {
		case 49: 
			if (selectTicketMenuOption()) {
				continue;
			}
		case 50:
			do {
				loadScreen(MENU_THEMES);
			} while (keyboardCheck() != 113);
			continue;
		case 81:
		case 113:
			/* Finaliza o programa */
			loadScreen(FINAL_SCREEN);
			Sleep(1500);
			exit(0); 
		default:
			// loadFailScreen();
			continue;
		}
	}
}