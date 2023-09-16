#pragma once
#ifndef ERROR_HANDLING
#define ERROR_HANDLING

/* Fun��o para carregar uma arte de acordo com o seu tema */
int loadArt(char theme, int art);

/* Fun��o para carregar um question�rio de acordo com o seu tema */
int loadSurvey(int theme, int question);

/* Fun��o para responder um question�rio de acordo com o seu tema */
int answerSurvey(int theme, char survey[51]);

/* Fun��o para avaliar uma arte */
int appraiseArt(char art_name[21]);

/* Fun��o para navegar pelas artes de um tema */
int switchThroughArts(char theme);

#endif