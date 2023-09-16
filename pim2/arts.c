#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"
#include "validation.h"

/* Arquivo com funções que envolvem todo o sistema de artes */

int loadArt(char theme, int art) {
	switch (theme) {
	case '0':
		switch (art) {
		case 0:
			readFile(art_a_negra);
			break;
		case 1:
			readFile(art_abaporu);
			break;
		case 2:
			readFile(art_estrada_de_ferro);
			break;
		case 3:
			readFile(art_operarios);
			break;
		}
	case '1':
		switch (art) {
		case 0:
			readFile(art_olimpic_games1);
			break;
		case 1:
			readFile(art_olimpic_games2);
			break;
		case 2:
			readFile(art_olimpic_games3);
			break;
		case 3:
			readFile(art_olimpic_games4);
			break;
		}
	case '2':
		switch (art) {
		case 0:
			readFile(art_santos_dumont);
			break;
		case 1:
			readFile(art_santos_dumont2);
			break;
		case 2:
			readFile(art_santos_dumont3);
			break;
		case 3:
			readFile(art_santos_dumont4);
			break;
		}
	case '3':
		switch (art) {
		case 0:
			readFile(art_tema_a_ser_definido1);
			break;
		case 1:
			readFile(art_tema_a_ser_definido2);
			break;
		case 2:
			readFile(art_tema_a_ser_definido3);
			break;
		case 3:
			readFile(art_tema_a_ser_definido4);
			break;
		}
	}
}

int loadSurvey(int theme, int question) {
	switch (theme) {
	case 0:
		switch (question) {
		case 0:
			readFile(survey_santos_dumont1);
			break;
		case 1:
			readFile(survey_santos_dumont2);
			break;
		case 2:
			readFile(survey_santos_dumont3);
			break;
		case 3:
			readFile(survey_santos_dumont4);
			break;
		}
	case 1:
		switch (question) {
		case 0:
			readFile(survey_olimpic_games1);
			break;
		case 1:
			readFile(survey_olimpic_games2);
			break;
		case 2:
			readFile(survey_olimpic_games3);
			break;
		case 3:
			readFile(survey_olimpic_games4);
			break;
		}
	case 2:
		switch (question) {
		case 0:
			readFile(survey_modern_week1);
			break;
		case 1:
			readFile(survey_modern_week2);
			break;
		case 2:
			readFile(survey_modern_week3);
			break;
		case 3:
			readFile(survey_modern_week4);
			break;
		}
	case 3:
		switch (question) {
		case 0:
			readFile(survey_tema_a_ser_definido1);
			break;
		case 1:
			readFile(survey_tema_a_ser_definido2);
			break;
		case 2:
			readFile(survey_tema_a_ser_definido3);
			break;
		case 3:
			readFile(survey_tema_a_ser_definido4);
			break;
		}
	}
}

int answerSurvey(int theme, char survey[51]) {
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
		appendToFile(csv_survey_sumary, answer);

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

			registerFeedback(csv_user_feedback, feedback);

			printf("Obrigado!\n");
			return 0;
		}
	}
	else if (option == 'n') {
		sprintf(feedback, "%s,%d\n", art_name, rate);

		registerFeedback(csv_user_feedback, feedback);

		printf("Obrigado!\n");
		return 0;
	}
	else {
		printf("Opção inválida!");
		return 1;
	}
}

int switchThroughArts(char theme) {
	char key;
	int art = 0;

	while (1) {
		Sleep(500);
		if (_kbhit()) {
			key = _getch();
			if (key == '.') {
				load_art(theme, art);
				readFile(menu_next_art);
				art++;
				if (art == 3) {
					art = 0;
				}
			}
		}
	}

	return 0;
}

/* Registra a avalia��o da arte no sistema */
void registerArtFeedback(char file_path[100], char feedback[201]) {
	FILE** file_pointer;

	file_pointer = fopen(file_path, "a");

	fprintf(file_pointer, feedback);

	fclose(file_pointer);
}
