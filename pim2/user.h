#pragma once
#ifndef USER
#define USER

/* Função para registrar um usuário no sistema */
void registerUser(char name[100]);

void registerStudent(char name[100], char student_id[8]);

void registerSenior(char name[100], int age);

void registerJunior(char name[100], int age);

void registerDisabledPerson(char name[100], char disabled_person_id[11]);

#endif