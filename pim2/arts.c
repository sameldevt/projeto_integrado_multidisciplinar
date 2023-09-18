#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"

/* Arquivo com funções que envolvem todo o sistema de artes */

int loadArt(char theme, int art) {
	switch (theme) {
	case '0':
		switch (art) {
		case 0:
			readFile(ART_A_NEGRA);
			break;
		case 1:
			readFile(ART_ABAPORU);
			break;
		case 2:
			readFile(ART_ESTRADA_DE_FERRO);
			break;
		case 3:
			readFile(ART_OPERARIOS);
			break;
		}
	case '1':
		switch (art) {
		case 0:
			readFile(ART_OLIMPIC_GAMES1);
			break;
		case 1:
			readFile(ART_OLIMPIC_GAMES2);
			break;
		case 2:
			readFile(ART_OLIMPIC_GAMES3);
			break;
		case 3:
			readFile(ART_OLIMPIC_GAMES4);
			break;
		}
	case '2':
		switch (art) {
		case 0:
			readFile(ART_SANTOS_DUMONT);
			break;
		case 1:
			readFile(ART_SANTOS_DUMONT2);
			break;
		case 2:
			readFile(ART_SANTOS_DUMONT3);
			break;
		case 3:
			readFile(ART_SANTOS_DUMONT4);
			break;
		}
	case '3':
		switch (art) {
		case 0:
			readFile(ART_TEMA_A_SER_DEFINIDO1);
			break;
		case 1:
			readFile(ART_TEMA_A_SER_DEFINIDO2);
			break;
		case 2:
			readFile(ART_TEMA_A_SER_DEFINIDO3);
			break;
		case 3:
			readFile(ART_TEMA_A_SER_DEFINIDO4);
			break;
		}
	}
}

int loadSurvey(int theme, int question) {
	switch (theme) {
	case 0:
		switch (question) {
		case 0:
			readFile(SURVEY_SANTOS_DUMONT1);
			break;
		case 1:
			readFile(SURVEY_SANTOS_DUMONT2);
			break;
		case 2:
			readFile(SURVEY_SANTOS_DUMONT3);
			break;
		case 3:
			readFile(SURVEY_SANTOS_DUMONT4);
			break;
		}
	case 1:
		switch (question) {
		case 0:
			readFile(SURVEY_OLIMPIC_GAMES1);
			break;
		case 1:
			readFile(SURVEY_OLIMPIC_GAMES2);
			break;
		case 2:
			readFile(SURVEY_OLIMPIC_GAMES3);
			break;
		case 3:
			readFile(SURVEY_OLIMPIC_GAMES4);
			break;
		}
	case 2:
		switch (question) {
		case 0:
			readFile(SURVEY_MODERN_WEEK1);
			break;
		case 1:
			readFile(SURVEY_MODERN_WEEK2);
			break;
		case 2:
			readFile(SURVEY_MODERN_WEEK3);
			break;
		case 3:
			readFile(SURVEY_MODERN_WEEK4);
			break;
		}
	case 3:
		switch (question) {
		case 0:
			readFile(SURVEY_TEMA_A_SER_DEFINIDO1);
			break;
		case 1:
			readFile(SURVEY_TEMA_A_SER_DEFINIDO2);
			break;
		case 2:
			readFile(SURVEY_TEMA_A_SER_DEFINIDO3);
			break;
		case 3:
			readFile(SURVEY_TEMA_A_SER_DEFINIDO4);
			break;
		}
	}
}

void registerArtFeedback(char file_path[100], char feedback[201]) {
	FILE** file_pointer;

	file_pointer = fopen(file_path, "a");

	fprintf(file_pointer, feedback);

	fclose(file_pointer);
}

int answerSurvey(int theme, char survey[51]) {
	int option;
	char answer[101];

	int survey_count = 5;
	int question = 0;

	while (question < survey_count) {
		loadSurvey(theme, question);
		printf("\nDigite uma opção: ");
		scanf_s("%d", &option);

		scanf_s("%100s", answer, 101);

		system("cls");
		sprintf(answer, "%d,", option);
		appendToFile(CSV_SURVEY_SUMARY, answer);

		question++;
	}
}

int appraiseArt(char art_name[21]) {
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

			registerArtFeedback(CSV_USER_FEEDBACK, feedback);

			printf("Obrigado!\n");
			return 0;
		}
	}
	else if (option == 'n') {
		sprintf(feedback, "%s,%d\n", art_name, rate);

		registerArtFeedback(CSV_USER_FEEDBACK, feedback);

		printf("Obrigado!\n");
		return 0;
	}
	else {
		printf("Opção inválida!");
		return 1;
	}
}

int browseBetweenArts(char theme) {
	char key;
	int art = 0;

	while (_kbhit() != 'q') {
		key = _getch();
		if (key == '.') {
			loadArt(theme, art);
			readFile(MENU_NEXT_ART);
			art++;
			if (art == 3) {
				art = 0;
			}
		}
	}

	return 0;
}
