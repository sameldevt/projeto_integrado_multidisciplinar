#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "user.h"
#include "files.h"
#include "misc.h"
#include "menu.h"

/* Arquivo com funções de verificação de entrada de usuários */

void verifyPersonEntry() {
	char name[51];

	system("cls");
	readFile(MENU_FULLPRICE);

	printf("   >> Nome: ");
	scanf_s("%50s", name, 51);

	registerUser(name);

	printf("Usuário Identificado com sucesso!");
	threeSecTimer();

	selectPaymentOption();
}

void verifyStudentEntry() {
	char name[51];
	int student_id;

	system("cls");
	readFile(MENU_STUDENT_ENTRY);

	printf("   >> Nome: ");
	scanf_s("%51s", name, 51);

	while (1) {
		printf("   >> RA: ");
		scanf_s("%d", &student_id);

		if (sizeof(student_id) > 8) {
			perror("RA inválido! O tamanho máximo para este documento é de 8 digitos.");
			threeSecTimer();
			continue;
		}
		break;
	}

	printf("Estudante identificado com sucesso\n");
	threeSecTimer();

	selectPaymentOption();
}

void verifySeniorEntry() {
	char name[51];
	int age;

	system("cls");
	readFile(MENU_SENIOR_ENTRY);

	printf("   >> Nome: ");
	scanf_s("%51s", name, 51);

	while (1) {
		printf("   >> Idade: ");
		scanf_s("%d", &age);

		if (age < 60) {
			perror("Idade abaixo do limite de 60 anos!");
			threeSecTimer();
			continue;
		}
		break;
	}
	
	printf("Usuário verificado com sucesso!");
	threeSecTimer();

	selectPaymentOption();
}

void verifyJuniorEntry() {
	char name[51];
	int age;

	int name_length = sizeof(name) / sizeof(name[0]);
	system("cls");
	readFile(MENU_JUNIOR_ENTRY);

	printf("   >> Nome: ");
	scanf_s("%51s", name, name_length);

	while(1){
		printf("   >> Idade: ");
		scanf_s("%d", &age);
		
		if (age > 5) {
			perror("Idade acima do limite de 5 anos!");
			threeSecTimer();
			continue;
		}
		break;
	}
	
	printf("Usuário verificado com sucesso!");
	threeSecTimer();

	selectPaymentOption();
}

void verifyDisabledPersonEntry() {
	int disabled_person_id;
	char name[51];

	system("cls");
	readFile(MENU_DISABLED_PERSON_ENTRY);

	printf("   >> Nome: ");
	scanf_s("%51s", name, 51);

	while (1) {
		printf("   >> Identificação: ");
		scanf_s("%d", &disabled_person_id);

		if (sizeof(disabled_person_id) > 11) {
			perror("Identidade inválida! O tamanho máximo para este documento é de 11 digitos.");
			threeSecTimer();
			continue;
		}
		break;
	}

	printf("Usuário verificado com sucesso!");
	threeSecTimer();

	selectPaymentOption();
}