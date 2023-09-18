#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"
#include "misc.h"

/* Arquivo com funções para verificação de pagamento */

int verifyCardPayment() {
	system("cls");
	int card_number;
	char card_holder[101];
	int identification_number;

	readFile(MENU_CARD_PAYMENT);
	printf("   >> Titular do cartão: ");
	scanf_s("%100s", card_holder, 101);

	while (1) {
		printf("   >> Número do cartão: ");
		scanf_s("%d", &card_number);

		if (sizeof(card_number) < 12 && sizeof(card_number) > 12) {
			perror("O número do cartão informado não é válido");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}

	while (1) {
		printf("   >> Código de segurança do cartão: ");
		scanf_s("%d", &identification_number);

		if (identification_number > 3 && identification_number < 3) {
			perror("Código de segurança inválido");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}
	
	printf("Pagamento feito com sucesso\n");
	return 0;
}

int verifyPixPayment() {
	float value;

	while (1) {
		system("cls");
		readFile(MENU_PIX_PAYMENT);

		printf("   >> Valor: ");
		scanf_s("%f", &value);
		
		if (value < 20.0) {
			perror("Saldo insuficiênte");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}

	printf("Pagamento feito com sucesso");
	threeSecTimer();
	return 0;
}
