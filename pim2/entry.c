#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "user.h"
#include "files.h"
#include "misc.h"

/* Arquivo com fun��es de verifica��o de entrada de usu�rios */

int verifyPersonEntry() {
	char name[51];

	system("cls");
	readFile(menu_fullprice);

	printf("Digite seu nome: ");
	scanf_s("%50s", name, 51);

	printf("Usu�rio Identificado com sucesso!");
	registerUser(name);
	threeSecTimer();

	return 0;
}

int verifyStudentEntry() {
	char name[51];
	int student_id;

	system("cls");
	readFile(submenu_student_entry);

	printf("Nome: ");
	scanf_s("%51s", name, 51);

	while (1) {
		if (sizeof(student_id) > 8) {
			perror("RA inv�lido! O tamanho m�ximo para este documento � de 8 digitos.");
			continue;
		}
		break;
	}

	printf("Estudante identificado com sucesso\n");
	threeSecTimer();
	
	return 0;
}

int verifySeniorEntry() {
	char name[51];
	int age;

	system("cls");
	readFile(submenu_senior_entry);

	printf(" >> Nome: ");
	scanf_s("%51s", name, 51);

	if (age < 60) {
		perror("Idade abaixo do limite de 60 anos!");
		threeSecTimer();
		return 1;
	}
	else {
		printf("Usu�rio verificado com sucesso!");
		threeSecTimer();
		return 0;
	}
}

int verifyJuniorEntry() {
	char name[51];
	int age;

	int name_length = sizeof(name) / sizeof(name[0]);
	system("cls");
	readFile(submenu_junior_entry);

	printf(" >> Nome: ");
	scanf_s("%51s", name, name_length);

	if (age > 5) {
		perror("Idade acima do limite de 5 anos!");
		threeSecTimer();
		return 1;
	}
	else {
		printf("Usu�rio verificado com sucesso!");
		threeSecTimer();
		return 0;
	}
}

int verifyDisabledPersonTicket() {
	int disabled_person_id;
	char name[51];

	system("cls");
	readFile(submenu_disabled_person_entry);

	printf(" >> Nome: ");
	scanf_s("%51s", name, 51);
	while (1) {
		printf(" >> Identifica��o: ");
		scanf_s("%d", &disabled_person_id);

		if (sizeof(disabled_person_id) > 11) {
			perror("Identidade inv�lida! O tamanho m�ximo para este documento � de 11 digitos.");
			threeSecTimer();
			system("cls");
			continue;
		}
		break;
	}
	printf("Usu�rio verificado com sucesso!");
	threeSecTimer();

	return 0;
}