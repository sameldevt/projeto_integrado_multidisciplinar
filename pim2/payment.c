#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"
#include "misc.h"
#include "menu.h"

/* Arquivo com funções para verificação de pagamento */

int verifyCardPayment() {
	char card_number[13];
	char card_holder[101];
	char identification_number[4]; 

	loadLoadingScreen();

	while (1) {
		loadScreen(MENU_CARD_PAYMENT);
		scanf_s("%13s", &card_number, 13);

		if (sizeof(card_number) < 12 && sizeof(card_number) > 12) {
			loadScreen(MENU_CARD_PAYMENT_1_FAIL);
			Sleep(1500);
			loadLoadingScreen();
			continue;
		}
		break;
	}

	while (1) {
		loadScreen(MENU_CARD_PAYMENT_1);
		scanf_s("%3s", &identification_number, 3);

		if (sizeof(identification_number) > 3 && sizeof(identification_number) < 3) {
			loadScreen(MENU_CARD_PAYMENT_2_FAIL);
			Sleep(1500);
			loadLoadingScreen();
			continue;
		}
		break;
	}

	loadScreen(MENU_CARD_PAYMENT_2);
	Sleep(1500);
	return 1;
}

int verifyPixPayment() {
	float value;

	loadLoadingScreen();

	while (1) {
		loadScreen(MENU_PIX_PAYMENT);
		scanf_s("%f", &value);
		
		if (value < 5.0) {
			loadScreen(MENU_PIX_PAYMENT_1_FAIL);
			Sleep(1500);
			loadLoadingScreen();
			continue;
		}
		break;
	}

	loadScreen(MENU_PIX_PAYMENT_1);
	Sleep(1500);
	return 1;
}
