#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "files.h"

/* Arquivo com funções de manipulação de usuários */

void registerUser(char name[100]) {
	char user[100];
	sprintf(user, "%s\n", name);
	appendToFile(CSV_USERS, user);
}

void registerStudent(char name[100], char student_id[8]) {
	char student[100];
	sprintf(student, "%s,%s\n", name, student_id);
	appendToFile(CSV_USERS, student);
}

void registerSenior(char name[100], int age) {
	char senior[100];
	sprintf(senior, "%s,%d\n", name, age);
	appendToFile(CSV_USERS, senior);
}

void registerJunior(char name[100], int age) {
	char senior[100];
	sprintf(senior, "%s,%d\n", name, age);
	appendToFile(CSV_USERS, senior);
}

void registerDisabledPerson(char name[100], char disabled_person_id[11]) {
	char disabled_person[100];
	sprintf(disabled_person, "%s,%s\n", name, disabled_person_id);
	appendToFile(CSV_USERS, disabled_person);
}