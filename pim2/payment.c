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

	printf("Digite o nome do titular do cartão: ");
	scanf_s("%100s", card_holder, 101);

	while (1) {
		printf("Digite o número do seu cartão (max. 12 digitos): ");
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
		printf("Digite o número de segurança do cartão: ");
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
	system("cls");
	float value;

	while (1) {
		printf("Digite o valor que deseja pagar: ");
		scanf_s("%f", &value);
		
		if (value < 20.0) {
			perror("Saldo insuficiênte");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}

	printf("Pagamento feito com sucesso\n");
	return 0;
}
