#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#include "files.h"
#include "misc.h"
#include "menu.h"
#include "arts.h"

/* Arquivo com funções que envolvem todo o sistema de artes */

void setArtScreenSize(char theme[100]) {
	if (theme == ARTS_MODERN_WEEK || theme == ARTS_SANTOS_DUMONT) {
		setVerticalSize();
	}
	else {
		setHorizontalSize();
	}
}

double calculateFeedbackAverage(double feedback) {
	return feedback / 5;
}

char addComment() {
	int key;
	loadLoadingScreen();

	while (_kbhit() == NULL) {
		loadScreen(ADD_COMMENT_SCREEN1);
		key = _getch();
		switch (key) {
		case 49:
			break;
		case 50:
			return '----';
		default:
			continue;
		}
		break;
	}

	char comment[200];

	while (1) {
		loadScreen(ADD_COMMENT_SCREEN);
		scanf("&s", &comment);

		if (sizeof(comment) > 200) {
			loadScreen(INVALID_COMMENT_SCREEN);
			continue;
		}
		break;
	}
	return comment;
}

int answerSurvey() {
	int key;

	while (_kbhit() == NULL) {
		key = _getch();
		switch (key) {
			/* Tecla 1 */
		case 49:
			return 50;
			/* Tecla 2 */
		case 50:
			return 40;
			/* Tecla 3 */
		case 51:
			return 30;
			/* Tecla 4 */
		case 52:
			return 20;
			/* Tecla 5 */
		case 53:
			return 10;
		case 81:
		case 113:
			return 0;
		default:
			continue;
		}
		Sleep(500);
	}
}

int continueProgramFlow() {
	int key;

	while (_kbhit() == NULL) {
		loadScreen(CONTINUE_SCREEN);
		key = _getch();
		switch (key) {
		case 49:
			return 1;
		case 50:
			return 0;
		default:
			continue;
		}
		Sleep(500);
	}
}

int keyChecker() {
	int key;
	while (_kbhit() == NULL) {
		if (key = _getch()) {
			switch (key) {
			case 81:
			case 113:
				return 0;
			case 224:
				key = _getch();

				switch (key) {
				case 77:
					return 1;
				}
			default:
				continue;
			}
		}
		Sleep(500);
	}
}

void registerArtFeedback(char art_name[25], double score, char comment[200]) {
	char feedback[200];
	double score_average = ceil(calculateFeedbackAverage(score));

	sprintf(feedback, "Arte: %s  Nota: %.0f\n\n%s\n", art_name, score_average, comment);

	FILE** fp = fopen(CSV_USER_FEEDBACK, "a");

	fprintf(fp, "%s\n", feedback);

	fclose(fp);
}

int loadSurvey(char art_name[100]) {
	char survey_path[100];
	char survey[256];
	int art_score = 0;

	setHorizontalSize();
	loadLoadingScreen();

	FILE* fp1 = fopen(SURVEY_PATHS, "r");

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

		art_score += answerSurvey();
		system("cls");
	}
	fclose(fp1);

	registerArtFeedback(art_name, art_score, addComment());

	if (continueProgramFlow()) {
		return 1;
	}
	endProgram();
}

int loadArts(char theme[100]) {
	char art_path[100];
	char art[256];
	int pointer_location = 0;
	int key;

	// setArtScreenSize(theme);

	FILE** fp1 = fopen(theme, "r");

	if (fp1 == NULL) {
		perror("Error when attempting to open the file!");
		exit(1);
	}

	while (fgets(art_path, sizeof(art_path), fp1) != NULL) {
		size_t length = strlen(art_path);

		if (length > 0 && art_path[length - 1] == '\n') {
			art_path[length - 1] = '\0';
		}

		FILE** fp2 = fopen(art_path, "r");

		if (fp2 == NULL) {
			perror("Error when attempting to open the file!");
			exit(1);
		}

		while (fgets(art, sizeof(art), fp2) != NULL) {
			printf(art);
		}

		fclose(fp2);

		switch (keyChecker()) {
		case 0:
			fseek(fp1, 0, SEEK_END);
			break;
		case 1:
			if (pointer_location == 3) {
				fseek(fp1, 0, SEEK_SET);
				pointer_location = 0;
				break;
			}
			pointer_location++;
			system("cls");
			continue;
		}	
		continue;
	}

	fclose(fp1);

	if (loadSurvey(art)) {
		return 1;
	}
}
