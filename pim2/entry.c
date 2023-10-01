#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "user.h"
#include "files.h"
#include "misc.h"
#include "menu.h"

/* Arquivo com funções de verificação de entrada de usuários */

int verifyPersonEntry() {
	char name[100];

	loadLoadingScreen();
	loadScreen(MENU_FULLPRICE);

	scanf_s("%50s", name, 100);

	registerUser(name);

	loadScreen(MENU_FULLPRICE_1);
	Sleep(1500);

	return 1;
}

int verifyStudentEntry() {
	char name[100];
	char student_id[8];

	loadLoadingScreen();
	loadScreen(MENU_STUDENT_ENTRY);
	scanf_s("%100s", name, 100);

	while (1) {
		loadScreen(MENU_STUDENT_ENTRY_1);
		scanf_s("%8s", &student_id, 8);

		if (sizeof(student_id) > 8) {
			loadScreen(MENU_STUDENT_ENTRY_2_FAIL);
			Sleep(1500);
			continue;
		}
		else if (sizeof(student_id) < 8) {
			loadScreen(MENU_STUDENT_ENTRY_2_FAIL);
			Sleep(1500);
			continue;
		}
		break;
	}

	registerStudent(name, student_id);
	loadScreen(MENU_STUDENT_ENTRY_2);
	Sleep(1500);

	return 1;
}

int verifySeniorEntry() {
	char name[100];
	int age;

	loadLoadingScreen();
	loadScreen(MENU_SENIOR_ENTRY);
	scanf_s("%100s", name, 100);

	while (1) {
		loadScreen(MENU_SENIOR_ENTRY_1);
		scanf_s("%d", &age);

		if (age < 60) {
			loadScreen(MENU_SENIOR_ENTRY_2_FAIL);
			continue;
		}
		break;
	}
	
	registerSenior(name, age);
	loadScreen(MENU_SENIOR_ENTRY_2);
	Sleep(1500);

	return 1;
}

int verifyJuniorEntry() {
	char name[100];
	int age;

	loadLoadingScreen();
	loadScreen(MENU_JUNIOR_ENTRY);
	scanf_s("%100s", name, 100);

	while(1){
		loadScreen(MENU_JUNIOR_ENTRY_1);
		scanf_s("%d", &age);
		
		if (age > 5) {
			loadScreen(MENU_JUNIOR_ENTRY_2_FAIL);
			Sleep(1500);
			continue;
		}
		break;
	}
	
	registerJunior(name, age);
	loadScreen(MENU_JUNIOR_ENTRY_2);
	Sleep(1500);
	return 1;
}

int verifyDisabledPersonEntry() {
	char name[100];
	char disabled_person_id[11];

	loadLoadingScreen();
	loadScreen(MENU_DISABLED_PERSON_ENTRY);
	scanf_s("%51s", name, 100);

	while (1) {
		loadScreen(MENU_DISABLED_PERSON_ENTRY_1);
		scanf_s("%11s", &disabled_person_id, 11);

		if (sizeof(disabled_person_id) > 11) {
			loadScreen(MENU_DISABLED_PERSON_ENTRY_2_FAIL);
			Sleep(1500);
			continue;
		}
		else if (sizeof(disabled_person_id) < 11) {
			loadScreen(MENU_DISABLED_PERSON_ENTRY_2_FAIL);
			Sleep(1500);
			continue;
		}
		break;
	}

	registerDisabledPerson(name, disabled_person_id);
	loadScreen(MENU_DISABLED_PERSON_ENTRY_2);
	Sleep(1500);
	return 1;
}