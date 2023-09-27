#pragma once
#ifndef ARTS
#define ARTS

/* Função para carregar uma arte de acordo com o seu tema */
void loadArts(char theme[100]);

/* Função para registrar a avaliação de uma arte no sistema */
void registerArtFeedback(char art[100], int feedback);

/* Função para carregar um questionário de acordo com o seu tema */
void loadSurvey(char art[100]);

/* Função para avaliar uma arte */
int appraiseArt(char art_name[21]);

#endif