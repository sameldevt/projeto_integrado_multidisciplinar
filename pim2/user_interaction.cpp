#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "file_management.h"

char path[100] = "\\pim2\\resources\\";

/* inicio Menu principal */

/* Função para escolher uma opção do menu principal */
int select_mainmenu_option() {
	int choice;

	/* Imprime o menu principal */
	read_file(path);

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1: 
		/* Abre menu de ingressos */
		select_ticket_type();
	case 2: 
		/* Imprime lista de temas */
		read_file(path);
	case 3: 
		/* Finaliza o programa */
		printf("\nObrigado por usar o sistema do museu!");
		return 0;
	default: 
		printf("\nOpção invalida!");
	}
}

/* fim Menu principal */

/* inicio Menu Ingressos */

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

	printf("Digite seu RA (máximo de 8 digitos): ");
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
		printf("Você não tem mais que 60 anos!");
		return 0;
	}
}

int disabled_ticket() {
	int disabledPersonId;

	printf("Digite sua identificação (máximo de 11 digitos): ");
	scanf_s("%d", &disabledPersonId);

	if (disabledPersonValidation(disabledPersonId)) {
		return 1;
	}
	return 0;
}

int select_ticket_type() {
	int choice;

	/* Imprime opções de ingresso */
	read_file(path);

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		full_price_ticket();
	case 2:
		student_ticket();
	case 3:
		senior_ticket();
	case 4:
		disabled_ticket();
	case 5:
		/* Volta para o menu principal */
		select_main_menu_option();
	default:
		printf("\nOpção invalida!");
	}
}

/* Registra um cliente no sistema */
int register_client(char name[50]) {

}

/* fim Menu Ingressos */

/* inicio Menu Pagamento */

int card_payment() {
	int card_number[12];
	char card_holder[100];
	int identification_number;

	printf("Digite o nome do titular do cartão: ");
	scanf_s("%d", &card_holder);

	printf("Digite o número do seu cartão (max. 12 digitos): ");
	scanf_s("%d", &card_number);

	printf("Digite o número de segurança do cartão: ");
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

	printf("Escolha uma opção: ");
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

/* inicio Menu Temas */

int select_theme_menu_option(){
	int choice;

	/* Imprime a lista de temas */
	read_file(path);

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);
	
	if(select_theme(choice)) {
		return 0;
	}
	else {
		printf("\nOpção invalida!");
	}
}

/* fim Menu Temas */

/* inicio Menu opções de temas */

int select_art(int theme) {
	int art;

	printf("Escolha uma opção: ");
	scanf_s("%d", &art);

	switch (art) {
	case 1:
		load_art(theme, art);
	case 2:
		/* Volta para o menu de temas */
		select_theme_menu_option();
	case 3:
		/* Finaliza o programa */
		return 0;
	default:
		printf("\nOpção invalida!");
	}
}

int load_art(int theme, int art) {
	switch (theme) {
	case 1: 
	case 2:
	case 3:
	case 4:
	default:

	}
}

int switch_arts(int theme) {
	char key;
	int art = 0;

	while (1) {
		if (_kbhit()) { // Verifica se uma tecla foi pressionada
			key = _getch(); // Obtém a tecla pressionada
			if (key == '.') {
				load_art(theme, art++);
				if (art == 3) {
					art--;
				}
			}
			else if (key == ',') {
				load_art(theme, art--);
				if (art == 0) {
					art++;
				}
			}

			if (key == 'q') { // Exemplo de saída do loop ao pressionar 'q'
				break;
			}
		}
	}

	return 0;
}
/* fim Menu opções de temas */

/* inicio Menu opções de arte */

/* Avalia uma arte */
int evaluate_art(char art_name[20]) {
	int rate;
	char option;
	char feedback[200];

	printf("Dê uma nota para a arte: ");
	scanf_s("%d", &rate);

	printf("Deseja adicionar um comentário? [s]im [n]ão ");

	if (option == 's') {
		char comment[100];

		/* Calcula o tamanho do array 'comment' */
		int comment_size = sizeof(comment) / sizeof(comment[0]);

		printf("Digite seu comentário (máx. 100 caracteres): ");
		scanf_s("%s", &comment);

		if (sizeof(comment) > comment_size) {
			printf("Seu comentário é muito grande! O tamanho máximo é de 100 caracteres.");
			return 1;
		}
		else {
			sprintf(feedback, "%s,%s,%d\n", art_name, comment, rate);

			/* Registra a avaliação da arte no sistema */
			append_to_file(path, feedback);

			printf("Obrigado!\n");
			return 0;
		}
	}
	else if(option == 'n'){
		sprintf(feedback, "%s,%d\n", art_name, rate);
	
		/* Registra a avaliação da arte no sistema */
		append_to_file(path, feedback);

		printf("Obrigado!\n");
		return 0;
	}
	else {
		printf("Opção inválida!");
		return 1;
	}
}

/* fim Menu opções de arte */