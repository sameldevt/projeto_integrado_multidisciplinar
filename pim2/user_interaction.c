#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "file_management.h"
#include "validation.h"

void three_sec_timer() {
	int time = 0;
	while (time < 3) {
		printf(" .");
		Sleep(1000);
		time++;
	}
}

/* Função para responder o questionario do tema */
int answer_survey(int theme, char survey[51]) {
	int option;
	char answer[101];

	int survey_count = 5;
	int question = 0;

	while (question < survey_count) {
		load_survey(theme, question);
		printf("\nDigite uma opção: ");
		scanf_s("%d", &option);

		scanf_s("%100s", answer, 101);

		system("cls");
		sprintf(answer, "%d,", option);
		append_to_file(csv_survey_sumary, answer);

		question++;
	}
}

/* inicio Menu op��es de arte */
/* Avalia uma arte */
int evaluate_art(char art_name[21]) {
	int rate;
	char option;
	char feedback[201];

	printf("D� uma nota para a arte: ");
	scanf_s("%d", &rate);

	printf("Deseja adicionar um comentário? [s]im [n]ão ");
	scanf_s("%c", &option, 1);

	if (option == 's') {
		char comment[101];

		int comment_size = 101;

		printf("Digite seu comentário (máx. 100 caracteres): ");
		scanf_s("%100s", comment, sizeof(comment) == 1);

		if (comment > comment_size) {
			printf("Seu comentário é muito grande! O tamanho máximo é de 100 caracteres.");
			return 1;
		}
		else {
			sprintf(feedback, "%s,%s,%d\n", art_name, comment, rate);

			/* Registra a avaliação da arte no sistema */
			append_to_file(csv_user_feedback, feedback);

			printf("Obrigado!\n");
			return 0;
		}
	}
	else if (option == 'n') {
		sprintf(feedback, "%s,%d\n", art_name, rate);

		/* Registra a avalia��o da arte no sistema */
		append_to_file(csv_user_feedback, feedback);

		printf("Obrigado!\n");
		return 0;
	}
	else {
		printf("Opção inválida!");
		return 1;
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

void select_theme_menu_option() {
	system("cls");
	int theme;

	/* Imprime a lista de temas */
	read_file(menu_themes);

	printf("Escolha uma op��o: ");
	scanf_s("%d", &theme);

	if (theme > 4) {
		printf("\nOpção invalida!");
		select_theme_menu_option();
	}
	else {
		switch_arts(theme);
	}
}

int select_art(int theme) {
	int art;

	printf("Escolha uma opção: ");
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
		printf("\nOpção invalida!");
	}
}

int card_payment() {
	system("cls");
	int card_number;
	char card_holder[101];
	int identification_number;

	printf("Digite o nome do titular do cartão: ");
	scanf_s("%100s", card_holder, 101);

	printf("Digite o número do seu cartão (max. 12 digitos): ");
	scanf_s("%d", &card_number);

	printf("Digite o número de segurança do cartão: ");
	scanf_s("%d", &identification_number);

	if (validate_card_payment(card_holder, card_number, identification_number)) {
		perror("Transação falhou!\n");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}

int pix_payment() {
	float value;

	printf("Digite o valor que deseja pagar: ");
	scanf_s("%f", &value);

	if (validate_pix_payment(value)) {
		return 1;
	}

	return 0;
}

int select_payment_menu() {
	system("cls");
	int choice;

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		if (card_payment()) {
			select_theme_menu_option();
		}
		else {
			select_payment_menu();
		}
	case 2:
		if (pix_payment()) {
			select_theme_menu_option();
		}
		else {
			select_payment_menu();
		}
	case 3:
		select_ticket_type();
	default:
		return 0;
	}
}

int full_price_ticket() {
	char name[51];

	system("cls");
	read_file(menu_fullprice);

	printf("Digite seu nome: ");
	scanf_s("%50s", name, 51);

	if(validate_name(name)) {
		printf("Usuário Identificado com sucesso!");
		register_user(name);
		three_sec_timer();
		return 1;
	}

	return 0;
}

int student_ticket() {
	char name[51];
	int student_id;

	system("cls");
	read_file(submenu_student_entry);

	printf("Nome: ");
	scanf_s("%51s", name, 51);

	if (validate_name(name)) {
		printf("RA: ");
		scanf_s("%d", &student_id);

		if (!(validate_student_id(name, student_id))) {
			perror("O número de identificação precisa ter, no máximo, 8 digitos!");
			three_sec_timer();
			return 0;
		}
		printf("Estudante identificado com sucesso\n");
		three_sec_timer();
		return 1;
	}
	return 0;
}

int senior_ticket() {
	char name[51];
	int age;

	system("cls");
	read_file(submenu_senior_entry);

	printf(" >> Nome: ");
	scanf_s("%51s", name, 51);

	if (validate_name(name)) {
		printf(" >> idade: ");
		scanf_s("%d", &age);

		if (age < 60) {
			perror("Idade abaixo do limite de 60 anos!");
			three_sec_timer();
			return 0;
		}

		printf("Usuário verificado com sucesso!");
		three_sec_timer();
		return 1;
	}
	return 0;
}

int junior_ticket() {
	char name[51];
	int age;

	system("cls");
	read_file(submenu_junior_entry);

	printf(" >> Nome: ");
	scanf_s("%51s", name, 51);

	if (validate_name(name)) {
		printf(" >> idade: ");
		scanf_s("%d", &age);

		if (age > 5) {
			perror("Idade acima do limite de 5 anos!");
			three_sec_timer();
			return 0;
		}

		printf("Usuário verificado com sucesso!");
		three_sec_timer();
		return 1;
	}

	return 0;
}

int disabled_ticket() {
	int disabled_person_id;
	char name[51];

	system("cls");
	read_file(submenu_disabled_person_entry);

	printf(" >> Nome: ");
	scanf_s("%51s", name, 51);

	if (validate_name(name)) {
		printf(" >> Identificação: ");
		scanf_s("%d", &disabled_person_id);

		if (!(validate_disabled_person_id(disabled_person_id))) {
			perror("O número de identificação precisa ter, no máximo, 11 digitos!");
			three_sec_timer();
			return 0;
		}

		printf("Usuário verificado com sucesso!");
		three_sec_timer();
		return 1;
	}
	return 0;
}

/* Função para escolher uma op��o do menu principal */
int select_main_menu_option() {
	system("cls");
	int choice;

	/* Imprime o menu principal */
	read_file(menu_main);

	printf("Escolha uma opção: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		/* Abre menu de ingressos */
		select_ticket_type();
		break;
	case 2:
		/* Imprime lista de temas */
		system("cls");
		read_file(menu_themes);
		read_file(menu_back);

		char key;

		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 'q') {
					select_main_menu_option();
				}
			}
		}
	case 3:
		/* Finaliza o programa */
		printf("\nObrigado por usar o sistema do museu!");
		return 0;
	default:
		printf("\nOpção invalida!");
	}
}

int select_ticket_type() {
	int choice;

	while (1) {
		system("cls");
		read_file(menu_buy_tickets);

		printf("Escolha uma opção: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			if (full_price_ticket()) {
				select_payment_menu();
			}
			else {
				select_ticket_type();
			}
		case 2:
			if (student_ticket()) {
				select_payment_menu();
			}
			else {
				select_ticket_type();
			}
		case 3:
			if (senior_ticket()) {
				select_payment_menu();
			}
			else {
				select_ticket_type();
			}
		case 4:
			if (disabled_ticket()) {
				select_payment_menu();
			}
			else {
				select_ticket_type();
			}
		case 5:
			/* Volta para o menu principal */
			select_main_menu_option();
			break;
		default:
			printf("\nOpção inválida!");
		}
	}
}

void start_program() {
	select_main_menu_option();
}
