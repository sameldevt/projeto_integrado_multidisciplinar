#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"
#include "payment.h"
#include "misc.h"
#include "menu.h"

int selectPaymentOption() {
	while (1) {
		system("cls");
		int choice;

		printf("Escolha uma opção: ");

		switch (keyboardCheck()) {
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
		case '3': selectTicketType();
		default:
			return 0;
		}
	}
}

void selectThemeOption() {
	system("cls");

	/* Imprime a lista de temas */
	readFile(menu_themes);

	printf("Escolha uma op��o: ");

	if (keyboardCheck() > '4') {
		printf("\nOpção invalida!");
		selectThemeMenuOption();
	}
	else {
		switch_arts(keyboardCheck());
	}
}

int selectArtOption(int theme) {
	printf("Escolha uma opção: ");

	switch (keyboardCheck()) {
	case '1':
		switch_arts(theme);
	case '2':
		/* Volta para o menu de temas */
		selectThemeMenuOption();
	case '3':
		/* Finaliza o programa */
		exit(200);
	default:
		printf("\nOpção invalida!");
	}
}

/* Função para escolher uma op��o do menu principal */
int selectMainMenuOption() {
	while (1) {
		system("cls");

		/* Imprime o menu principal */
		readFile(menu_main);
		printf("Escolha uma opção: ");

		switch (keyboardCheck()) {
		case '1': select_ticket_type();
		case '2':
			/* Imprime lista de temas */
			system("cls");
			readFile(menu_themes);
			readFile(menu_back);

			if (keyboardCheck() == 'q') {
				continue;
			}
		case '3':
			/* Finaliza o programa */
			printf("\nObrigado por usar o sistema do museu!");
			exit(200);
		default:
			printf("\nOpção invalida!");
			threeSecTimer();
		}
	}
}

int selectTicketMenuOption() {
	while (1) {
		system("cls");
		readFile(menu_buy_tickets);

		printf("Escolha uma opção: ");

		switch (keyboardCheck()) {
		case '1':
			if (verifyFullPricePayment()) {
				select_payment_menu();
			}
			continue;
		case '2':
			if (student_ticket()) {
				select_payment_menu();
			}
			continue;
		case '3':
			if (senior_ticket()) {
				select_payment_menu();
			}
			continue;
		case '4':
			if (disabled_ticket()) {
				select_payment_menu();
			}
			continue;
		case '5':
			continue;
		default:
			threeSecTimer();
			printf("\nOpção inválida!");
		}
	}
}