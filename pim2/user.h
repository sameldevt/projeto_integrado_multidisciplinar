#pragma once
#ifndef USER
#define USER

/* Fun��o para registrar um usu�rio no sistema */
void registerUser(char name[100]);

void registerStudent(char name[100], char student_id[8]);

void registerSenior(char name[100], int age);

void registerJunior(char name[100], int age);

void registerDisabledPerson(char name[100], char disabled_person_id[11]);

#endif