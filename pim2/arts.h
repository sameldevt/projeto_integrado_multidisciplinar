#pragma once
#ifndef ARTS
#define ARTS

/* Fun��o para carregar uma arte de acordo com o seu tema */
int loadArt(char theme, int art);

/* Fun��o para carregar um question�rio de acordo com o seu tema */
int loadSurvey(int theme, int question);

/* Fun��o para registrar a avalia��o de uma arte no sistema */
void registerArtFeedback(char file_path[100], char feedback[201]);

/* Fun��o para responder um question�rio de acordo com o seu tema */
int answerSurvey(int theme, char survey[51]);

/* Fun��o para avaliar uma arte */
int appraiseArt(char art_name[21]);

/* Fun��o para navegar pelas artes de um tema */
int browseBetweenArts(char theme);

#endif