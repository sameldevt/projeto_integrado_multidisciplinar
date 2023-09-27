#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"
#include "misc.h"
#include "menu.h"

/* Arquivo com funções que envolvem todo o sistema de artes */

void registerArtFeedback(char art[100], int feedback) {
	FILE** file_pointer;

	file_pointer = fopen(art, "a");

	fprintf(file_pointer, feedback);

	fclose(file_pointer);
}

void loadSurvey(char art[100]) {
	char survey_path[100];
	char survey[256];
	int aux = 0;
	int value = 0;

	FILE* fp1 = fopen(art, "r");

	while (fgets(survey_path, sizeof(survey_path), fp1) != NULL) {

		/* Substitui '\n' por '\0' */
		size_t length = strlen(survey_path);
		if (length > 0 && survey_path[length - 1] == '\n') {
			survey_path[length - 1] = '\0';
		}

		FILE* fp2 = fopen(survey_path, "r");

		if (fp2 == NULL) {
			perror("Error when attempting to open the file!");
			exit(1);
		}

		while (fgets(survey, sizeof(survey), fp2) != NULL) {
			printf(survey);
		}

		fclose(fp2);

		int key;

		if (key = _getch()) {
			switch (key) {
				/* Tecla 1 */
			case 49:
				value += 10;
				break;
				/* Tecla 2 */
			case 50:
				value += 20;
				break;
				/* Tecla 3 */
			case 51:
				value += 30;
				break;
				/* Tecla 4 */
			case 52:
				value += 40;
				break;
				/* Tecla 5 */
			case 53:
				value += 50;
				break;
			}
		}
		continue;
	}

	fclose(fp1);

	int result = value / 5;
	registerArtFeedback(art, result);

	while (1) {
		system("cls");
		printf("Deseja continuar? ");

		int option = keyboardCheck();

		switch (option) {
		case 49:
			selectThemeOption();
			break;
		case 50:
			readFile(FINAL_SCREEN);
			exit(0);
		default:
			printf("Opção inválida!\n");
			threeSecTimer();
			continue;
		}
	}
}

void loadArts(char theme[100]) {
	system("cls");
	char art_path[100];
	char art[256];
	int aux = 0;
	int key;

	FILE* fp1 = fopen(theme, "r");

	while (fgets(art_path, sizeof(art_path), fp1) != NULL) {

		/* Substitui '\n' por '\0' */
		size_t length = strlen(art_path);
		if (length > 0 && art_path[length - 1] == '\n') {
			art_path[length - 1] = '\0';
		}

		FILE* fp2 = fopen(art_path, "r");

		if (fp2 == NULL) {
			perror("Error when attempting to open the file!");
			exit(1);
		}

		while (fgets(art, sizeof(art), fp2) != NULL) {
			printf(art);
		}

		fclose(fp2);

		if (key = _getch()) {
			switch (key) {
			/* Letra 'Q'*/
			case 81:
			case 113:
				loadSurvey(art);
				break;
			/* Código especial para setas */
			case 224:
				/* Obtém o código da seta */
				key = _getch();
				switch (key) {
				case 77:
					system("cls");
					if (aux == 3) {
						// retorna para o inicio do arquivo fp1
						fseek(fp1, 0, SEEK_SET);
						aux = 0;
						break;
					}
					aux++;
					break;
				}
			default:
				printf("tecla invalida");
				threeSecTimer();
				break;
			}
		}
	continue;
	}
	fclose(fp1);
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
