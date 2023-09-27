#pragma once
#ifndef FILES
#define FILES

#define CSV_USERS "resources\\csv_files\\users.csv"
#define CSV_USER_FEEDBACK "resources\\csv_files\\user_feedback.csv"
#define CSV_SURVEY_SUMARY "resources\\csv_files\\survey_sumary.csv"

#define INITIAL_SCREEN "ansi\\initialscreen.ans"
#define FINAL_SCREEN "ansi\\finalscreen.ans"
#define LOADING_SCREEN "ansi\\loadingscreen.ans"

#define MENU_MAIN "ansi\\mainmenu.ans"
#define MENU_BUY_TICKETS "ansi\\buyticket.ans"
#define MENU_THEMES "ansi\\themes.ans"

#define MENU_PAYMENT "ansi\\payment.ans"
#define MENU_PIX_PAYMENT "ansi\\paymentpix_paths.txt"
#define MENU_CARD_PAYMENT "ansi\\paymentcard_paths.txt"

#define MENU_HALFPRICE_ENTRY "ansi\\halfentry.ans"
#define MENU_FREE_ENTRY "ansi\\freeentry.ans"
#define MENU_FULLPRICE "ansi\\normalentry.ans"

#define MENU_JUNIOR_ENTRY "ansi\\juniorentry_paths.txt"
#define MENU_SENIOR_ENTRY "ansi\\seniorentry_paths.txt"
#define MENU_DISABLED_PERSON_ENTRY "ansi\\disabledperson_paths.txt"
#define MENU_STUDENT_ENTRY "ansi\\student_paths.txt"

#define MENU_SANTOS_DUMONT "ansi\\santosdumont.ans"
#define MENU_OLIMPIC_GAMES "ansi\\olimpicgames.ans"
#define MENU_MODERN_WEEK "ansi\\artweek.ans"
#define MENU_TECNOLOGY_SECURITY "ansi\\tecnologysecurity.ans"

#define ARTS_SANTOS_DUMONT "ansi\\santosdumont_paths.txt"
#define ARTS_OLIMPIC_GAMES "ansi\\olimpicgames_paths.txt"
#define ARTS_MODERN_WEEK "ansi\\modernweek_paths.txt"
#define ARTS_TECNOLOGY_SECURITY "ansi\\tecnologysecurity_paths.txt"

#define SURVEY_SANTOS_DUMONT1 "ansi\\santosdumont1survey_paths.txt"
#define SURVEY_SANTOS_DUMONT2 "ansi\\santosdumont2survey_paths.txt"
#define SURVEY_SANTOS_DUMONT3 "ansi\\santosdumont3survey_paths.txt"
#define SURVEY_SANTOS_DUMONT4 "ansi\\santosdumont4survey_paths.txt"

#define SURVEY_OLIMPIC_GAMES1 "ansi\\olimpicgames1survey_paths.txt"
#define SURVEY_OLIMPIC_GAMES2 "ansi\\olimpicgames2survey_paths.txt"
#define SURVEY_OLIMPIC_GAMES3 "ansi\\olimpicgames3survey_paths.txt"
#define SURVEY_OLIMPIC_GAMES4 "ansi\\olimpicgames4survey_paths.txt"

#define SURVEY_MODERN_WEEK1 "ansi\\modernweek1survey_paths.txt"
#define SURVEY_MODERN_WEEK2 "ansi\\modernweek2survey_paths.txt"
#define SURVEY_MODERN_WEEK3 "ansi\\modernweek3survey_paths.txt"
#define SURVEY_MODERN_WEEK4 "ansi\\modernweek4survey_paths.txt"

#define SURVEY_TECNOLOGY_SECURITY1 "ansi\\tecnologysecurity1survey_paths.txt"
#define SURVEY_TECNOLOGY_SECURITY2 "ansi\\tecnologysecurity2survey_paths.txt"
#define SURVEY_TECNOLOGY_SECURITY3 "ansi\\tecnologysecurity3survey_paths.txt"
#define SURVEY_TECNOLOGY_SECURITY4 "ansi\\tecnologysecurity4survey_paths.txt"

/* Função para abrir e ler um arquivo a partir do caminho informado */
void readFile(char file_path[100]);

/* Função para abrir e reescrever um arquivo a partir do caminho informado */
void writeFile(char file_path[100], char input[]);

/* Função para acrescentar uma linha ao arquivo informado */
void appendToFile(char file_path[100], char input[]);

#endif