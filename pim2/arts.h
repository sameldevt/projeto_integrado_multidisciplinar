#pragma once
#ifndef ARTS
#define ARTS

void setArtScreenSize(char theme[100]);

double calculateFeedbackAverage(double feedback);

char addComment();

int answerSurvey();

int continueProgramFlow();

int keyChecker();

/* Função para registrar a avaliação de uma arte no sistema */
void registerArtFeedback(char art[100], float score, char comment[200]);

/* Função para carregar um questionário de acordo com o seu tema */
int loadSurvey(char art[30]);

/* Função para carregar uma arte de acordo com o seu tema */
int loadArts(char theme[100]);

#endif