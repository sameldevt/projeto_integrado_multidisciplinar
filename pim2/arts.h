#pragma once
#ifndef ERROR_HANDLING
#define ERROR_HANDLING

/* Função para carregar uma arte de acordo com o seu tema */
int loadArt(char theme, int art);

/* Função para carregar um questionário de acordo com o seu tema */
int loadSurvey(int theme, int question);

/* Função para responder um questionário de acordo com o seu tema */
int answerSurvey(int theme, char survey[51]);

/* Função para avaliar uma arte */
int appraiseArt(char art_name[21]);

/* Função para navegar pelas artes de um tema */
int switchThroughArts(char theme);

#endif