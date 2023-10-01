#pragma once
#ifndef ARTS
#define ARTS

void setArtScreenSize(char theme[100]);

double calculateFeedbackAverage(double feedback);

char addComment();

int answerSurvey();

int continueProgramFlow();

int keyChecker();

/* Fun��o para registrar a avalia��o de uma arte no sistema */
void registerArtFeedback(char art[100], double score, char comment[200]);

/* Fun��o para carregar um question�rio de acordo com o seu tema */
int loadSurvey(char art[30]);

/* Fun��o para carregar uma arte de acordo com o seu tema */
int loadArts(char theme[100]);

#endif