#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "file_management.h"

/* inicio Menu op��es de arte */
/* Avalia uma arte */
int evaluate_art(char art_name[20]) {
	int rate;
	char option;
	char feedback[200];

	printf("D� uma nota para a arte: ");
	scanf_s("%d", &rate);

	printf("Deseja adicionar um coment�rio? [s]im [n]�o ");

	if (option == 's') {
		char comment[100];

		/* Calcula o tamanho do array 'comment' */
		int comment_size = sizeof(comment) / sizeof(comment[0]);

		printf("Digite seu coment�rio (m�x. 100 caracteres): ");
		scanf_s("%s", &comment);

		if (sizeof(comment) > comment_size) {
			printf("Seu coment�rio � muito grande! O tamanho m�ximo � de 100 caracteres.");
			return 1;
		}
		else {
			sprintf(feedback, "%s,%s,%d\n", art_name, comment, rate);

			/* Registra a avalia��o da arte no sistema */
			append_to_file(csv_user_feedback, feedback);

			printf("Obrigado!\n");
			return 0;
		}
	}
	else if(option == 'n'){
		sprintf(feedback, "%s,%d\n", art_name, rate);
	
		/* Registra a avalia��o da arte no sistema */
		append_to_file(csv_user_feedback, feedback);

		printf("Obrigado!\n");
		return 0;
	}
	else {
		printf("Op��o inv�lida!");
		return 1;
	}
}

int select_theme_menu_option(){
	int choice;

	/* Imprime a lista de temas */
	read_file(menu_themes);

	printf("Escolha uma op��o: ");
	scanf_s("%d", &choice);
	
	if(select_theme(choice)) {
		return 0;
	}
	else {
		printf("\nOp��o invalida!");
	}
}
/* fim Menu op��es de arte */

/* inicio Menu op��es de temas */
int select_art(int theme) {
	int art;

	printf("Escolha uma op��o: ");
	scanf_s("%d", &art);

	switch (art) {
	case 1:
		switch_arts(theme, art);
	case 2:
		/* Volta para o menu de temas */
		select_theme_menu_option();
	case 3:
		/* Finaliza o programa */
		return 0;
	default:
		printf("\nOp��o invalida!");
	}
}

int switch_arts(int theme) {
	char key;
	int art = 0;

	while (1) {
		if (_kbhit()) {
			key = _getch();
			if (key == '.') {
				load_art(theme, art);
				read_file(menu_next_art);
				art++;
				if (art == 3) {
					art = 0;
				}
			}
		}
	}
	return 0;
}
/* fim Menu op��es de temas */

/* inicio Menu Pagamento */
int card_payment() {
	int card_number[12];
	char card_holder[100];
	int identification_number;

	printf("Digite o nome do titular do cart�o: ");
	scanf_s("%d", &card_holder);

	printf("Digite o n�mero do seu cart�o (max. 12 digitos): ");
	scanf_s("%d", &card_number);

	printf("Digite o n�mero de seguran�a do cart�o: ");
	scanf_s("%d", &identification_number);

	if (card_payment_validation(card_holder, card_number, identification_number)) {
		return 1;
	}

	return 0;
}

int pix_payment() {
	double value;

	printf("Digite o valor que deseja pagar: ");
	scanf_s("%f", value);

	if (pix_payment_validation(value)) {
		return 1;
	}

	return 0;
}

int select_payment_menu() {
	int choice;

	printf("Escolha uma op��o: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		card_payment();
	case 2:
		pix_payment();
	case 3:
		select_ticket_type();
	default:
		return 0;
	}
}
/* fim Menu Pagamento */

/* inicio Comprar Ingressos */
int full_price_ticket() {
	char name[50];
	printf("Digite seu nome: ");
	scanf_s("%s", &name);

	/* Registra um cliente no sistema */
	register_client(name);

	return 0;
}

int student_ticket() {
	char name[100];
	int studentId;

	printf("Digite seu nome: ");
	scanf_s("%s", &name);

	printf("Digite seu RA (m�ximo de 8 digitos): ");
	scanf_s("%d", &studentId);

	if (studentIDValidation(name, studentId)) {
		return 1;
	}
	return 0;
}

int senior_ticket() {
	char name[100];
	int age;

	printf("Digite sua idade (maior que 60 anos): ");
	scanf_s("%d", &age);

	if (age > 60) {
		return 1;
	}
	else {
		printf("Voc� n�o tem mais que 60 anos!");
		return 0;
	}
}

int disabled_ticket() {
	int disabledPersonId;

	printf("Digite sua identifica��o (m�ximo de 11 digitos): ");
	scanf_s("%d", &disabledPersonId);

	if (disabledPersonValidation(disabledPersonId)) {
		return 1;
	}
	return 0;
}

int select_ticket_type() {
	int choice;

	/* Imprime op��es de ingresso */
	read_file(menu_buy_tickets);

	printf("Escolha uma op��o: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		full_price_ticket();
		break;
	case 2:
		student_ticket();
		break;
	case 3:
		senior_ticket();
		break;
	case 4:
		disabled_ticket();
		break;
	case 5:
		/* Volta para o menu principal */
		select_main_menu_option();
		break;
	default:
		printf("\nOp��o invalida!");
		continue;
	}
}
/* fim Comprar Ingressos */

/* inicio Menu principal */
/* Fun��o para escolher uma op��o do menu principal */
int select_main_menu_option() {
	int choice;

	/* Imprime o menu principal */
	read_file(menu_main);

	printf("Escolha uma op��o: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1: 
		/* Abre menu de ingressos */
		select_ticket_type();
		break;
	case 2: 
		/* Imprime lista de temas */
		read_file(menu_themes);
		break;
	case 3: 
		/* Finaliza o programa */
		printf("\nObrigado por usar o sistema do museu!");
		return 0;
	default: 
		printf("\nOp��o invalida!");
	}
}
/* fim Menu principal */