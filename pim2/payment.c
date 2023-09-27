#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"
#include "misc.h"
#include "menu.h"

/* Arquivo com funções para verificação de pagamento */

void verifyCardPayment() {
	int card_number;
	char card_holder[101];
	int identification_number;

	system("cls");

	readFile(MENU_CARD_PAYMENT);
	printf("   >> Titular do cartao: ");
	scanf_s("%100s", card_holder, 101);

	while (1) {
		printf("   >> Numero do cartao: ");
		scanf_s("%d", &card_number);

		if (sizeof(card_number) < 12 || sizeof(card_number) > 12) {
			printf("O número do cartão informado não é válido!\n");
			printf("O número do seu cartão precisa ter 12 digitos!\n");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}

	while (1) {
		printf("   >> Código de segurança do cartão: ");
		scanf_s("%d", &identification_number);

		if (sizeof(identification_number) > 3 && sizeof(identification_number < 3)) {
			printf("Código de segurança inválido");
			printf("O código de segurança do seu cartão precisa ter 3 digitos!\n");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}
	
	printf("Pagamento feito com sucesso\n");
	threeSecTimer();
	selectThemeOption();
}

void verifyPixPayment() {
	float value;

	while (1) {
		system("cls");
		readFile(MENU_PIX_PAYMENT);

		printf("   >> Valor: ");
		scanf_s("%f", &value);
		
		if (value < 10.0) {
			printf("Valor informado não é suficiente para comprar um ingresso!\n");
			printf("O ingresso custa R$10,00\n");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}

	printf("Pagamento feito com sucesso");
	threeSecTimer();
	selectThemeOption();
}
