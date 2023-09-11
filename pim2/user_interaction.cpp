#include <stdio.h>
#include <stdlib.h>

#include "file_management.h"

char path[100] = "\\pim2\\resources\\";

/* inicio Menu principal */

/* Função para escolher uma opção do menu principal */
int select_main_menu_option() {
	int choice;

	/* Imprime o menu principal */
	readFile(path);

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1: 
		/* Abre menu de ingressos */
		select_ticket_type();
	case 2: 
		/* Imprime lista de temas */
		readFile(path);
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

int select_ticket_type() {
	int choice;

	/* Imprime opções de ingresso */
	readFile(path);

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

/* Registra um cliente no sistema */
int register_client(char name[50]) {

}

/* fim Menu Ingressos */

/* inicio Menu Pagamento */

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
	}
}

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

/* fim Menu Pagamento */

/* inicio Menu Temas */

int select_theme_option(){
	int choice;

	/* Imprime a lista de temas */
	read_file(path);

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);
	
	switch (choice) {
	case 1:
		theme_1();
	case 2:
		theme_2();
	case 3:
		theme_3();
	case 4:
		theme_4();
	default:
		printf("\nOpção invalida!");
	}
}

int theme_1() {
	/* Imprime tema 1 */
	read_file(path);
}

int theme_2() {
	/* Imprime tema 2 */
	read_file(path);
}

int theme_3() {
	/* Imprime tema 3 */
	read_file(path);
}

int theme_4() {
	/* Imprime tema 4 */
	read_file(path);
}

/* fim Menu Temas */

/* inicio Menu opções de temas */

int select_art_option() {
	int choice;

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		select_art();
	case 2:
		/* Volta para o menu de temas */
		select_theme_option();
	case 3:
		/* Finaliza o programa */
		return 0;
	default:
		printf("\nOpção invalida!");
	}
}

int select_art() {
	int choice;

	/* Imprime a lista de artes */
	read_file(path);

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		art_1();
	case 2:
		art_2();
	case 3:
		art_3();
	case 4:
		art_4();
	default:
		printf("\nOpção invalida!");
	}
}

int art_1() {

}

int art_2() {

}

int art_3() {

}

int art_4() {

}

/* fim Menu opções de temas */

/* inicio Menu opções de arte */

int give_art_feedback() {
	int choice;

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		rate();
	case 2:
		/* Volta para o menu de artes */
		select_art();
	default:
		printf("\nOpção invalida!");
	}
}

int rate() {
	int rate;
	int option;

	printf("Dê uma nota para a arte: ");
	scanf_s("%d", &rate);

	printf("Deseja adicionar um comentário? [s]im [n]ão ");

	if (option == 's') {
		char comment[256];
		printf("Digite seu comentário: ");
		scanf_s("%s", &comment);
		("Obrigado!\n");
	}
	else {
		printf("Obrigado!\n");
	}
}

int register_feedback() {

	/* Registra o feedback no sistema */
	append_to_file();

	/* Volta para o menu de artes */
	select_art();
}

/* fim Menu opções de arte */