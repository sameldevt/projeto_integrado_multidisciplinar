#pragma once
#ifndef ARTS
#define ARTS

/* Fun��o para carregar uma arte de acordo com o seu tema */
void loadArts(char theme[100]);

/* Fun��o para registrar a avalia��o de uma arte no sistema */
void registerArtFeedback(char art[100], int feedback);

/* Fun��o para carregar um question�rio de acordo com o seu tema */
void loadSurvey(char art[100]);

/* Fun��o para avaliar uma arte */
int appraiseArt(char art_name[21]);

#endif