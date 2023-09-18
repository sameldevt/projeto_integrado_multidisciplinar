#pragma once
#ifndef ARTS
#define ARTS

/* Função para carregar uma arte de acordo com o seu tema */
int loadArt(char theme, int art);

/* Função para carregar um questionário de acordo com o seu tema */
int loadSurvey(int theme, int question);

/* Função para registrar a avaliação de uma arte no sistema */
void registerArtFeedback(char file_path[100], char feedback[201]);

/* Função para responder um questionário de acordo com o seu tema */
int answerSurvey(int theme, char survey[51]);

/* Função para avaliar uma arte */
int appraiseArt(char art_name[21]);

/* Função para navegar pelas artes de um tema */
int browseBetweenArts(char theme);

#endif