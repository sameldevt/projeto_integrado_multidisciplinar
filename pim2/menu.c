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
	int theme;

	while (1) {
		system("cls");
		readFile(MENU_THEMES);

		int key = keyboardCheck();

		switch (key) {
		case 49:
			loadArts(ARTS_MODERN_WEEK);
			break;
		case 50:
			loadArts(ARTS_SANTOS_DUMONT);
			break;
		case 51:
			loadArts(ARTS_OLIMPIC_GAMES);
			break;
		case 52:
			loadArts(ARTS_TECNOLOGY_SECURITY);
			break;
		default:
			printf("Opção inválidad!");
			threeSecTimer();
			continue;
		}
	}
}

void selectArtOption(char theme) {
	int key;

	while (1) {
		system("cls");
		key = keyboardCheck();

		switch (key) {
		case 49:
			loadArts(theme);
		case 50:
			/* Volta para o menu de temas */
			selectThemeOption();
		case 51:
			/* Finaliza o programa */
			//readFile(GOODBYE_SCREEN);
			exit(0);
		default:
			printf("\nOpção invalida!");
			continue;
		}
	}
}

void selectPaymentOption() {
	int key;

	while (1) {
		system("cls");
		readFile(MENU_PAYMENT);

		key = keyboardCheck();

		switch (key) {
		case 49: verifyCardPayment(); 
		case 50: verifyPixPayment(); 
		case 51: selectTicketMenuOption();
		default:
			printf("\nOpção inválida!");
			threeSecTimer();
			continue;
		}
	}
}

void selectTicketMenuOption() {
	int key;
	while (1) {
		system("cls");
		readFile(MENU_BUY_TICKETS);

		key = keyboardCheck();
		switch (key) {
		case 49: verifyPersonEntry();
		case 50: verifyStudentEntry();
		case 51: verifySeniorEntry();
		case 52: verifyDisabledPersonEntry();
		default:		
			printf("\nOpção inválida!");
			threeSecTimer();
			continue;
		}
	}
}

void selectMainMenuOption() {
	int option;

	while (1) {
		system("cls");

		readFile(MENU_MAIN);
		option = keyboardCheck();

		switch (option) {
		case 49: selectTicketMenuOption();
		case 50:
			do {
				system("cls");
				readFile(MENU_THEMES);
			} while (keyboardCheck() != 113);
			continue;
		case 51:
			//readFile(GOODBYE_SCREEN);
			threeSecTimer();
			exit(0); 
		default:
			printf("\nOpção invalida!");
			threeSecTimer();
			continue;
		}
	}
}