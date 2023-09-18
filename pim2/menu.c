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
	char key;
	system("cls");
	readFile(MENU_THEMES);

	printf("Escolha uma opção: ");

	while(1){
		key = keyboardCheck();
		if (key > '4') {
			printf("\nOpção invalida!");
			continue;
		}
		break;
	}
	browseBetweenArts(key);
}

int selectArtOption(char theme) {
	char key;

	while (1) {
		system("cls");
		printf("Escolha uma opção: ");
		key = keyboardCheck();

		switch (key) {
		case '1':
			browseBetweenArts(theme);
		case '2':
			/* Volta para o menu de temas */
			selectThemeOption();
		case '3':
			/* Finaliza o programa */
			exit(0);
		default:
			printf("\nOpção invalida!");
			continue;
		}
	}
}

int selectPaymentOption() {
	char option;

	while (1) {
		system("cls");
		readFile(MENU_PAYMENT);

		printf("Escolha uma opção: ");
		option = keyboardCheck();

		switch (option) {
		case '1':
			if (verifyCardPayment()) {
				selectThemeOption();
			}
			continue;
		case '2':
			if (verifyPixPayment()) {
				selectThemeOption();
			}
			continue;
		case '3': selectTicketMenuOption();
		default:
			printf("\nOpção inválida!");
			threeSecTimer();
			continue;
		}
	}
}

int selectTicketMenuOption() {
	while (1) {
		system("cls");
		readFile(MENU_BUY_TICKETS);

		printf("Escolha uma opção: ");

		switch (keyboardCheck()) {
		case '1': verifyPersonEntry();
		case '2': verifyStudentEntry();
		case '3': verifySeniorEntry();
		case '4': verifyDisabledPersonEntry();
		default:		
			printf("\nOpção inválida!");
			threeSecTimer();
			continue;
		}
	}
}

int selectMainMenuOption() {
	char option;

	while (1) {
		system("cls");

		readFile(MENU_MAIN);
		printf("Escolha uma opção: ");
		option = keyboardCheck();

		switch (option) {
		case '1': selectTicketMenuOption();
		case '2':
			system("cls");
			readFile(MENU_THEMES);
			readFile(MENU_BACK);

			if (keyboardCheck() == 'q') {
				continue;
			}
		case '3':
			printf("\nObrigado por usar o sistema do museu!");
			threeSecTimer();
			exit(0);
		default:
			printf("\nOpção invalida!");
			threeSecTimer();
		}
	}
}