#pragma once
#ifndef FILES
#define FILES

#define CSV_USERS "resources\\csv_files\\register\\users.csv"
#define CSV_USER_FEEDBACK "resources\\csv_files\\register\\user_feedback.csv"
#define CSV_SURVEY_SUMARY "resources\\csv_files\\register\\survey_sumary.csv"

#define INITIAL_SCREEN "ansi\\initialscreen.ans"
#define FINAL_SCREEN "ansi\\finalscreen.ans"
#define LOADING_SCREEN "ansi\\loadingscreen.ans"
#define INVALID_OPTION_SCREEN "ansi\\invalidoptionscreen.ans"
#define SANTOS_DUMONT_SCREEN "ansi\\santosdumont.ans"
#define OLIMPIC_GAMES_SCREEN "ansi\\olimpicgames.ans"
#define MODERN_WEEK_SCREEN "ansi\\artweek.ans"
#define TECNOLOGY_SECURITY_SCREEN "ansi\\tecnologysecurity.ans"
#define CONTINUE_SCREEN "ansi\\continuescreen.ans"
#define ADD_COMMENT_SCREEN "ansi\\addcomment.ans"
#define ADD_COMMENT_SCREEN1 "ansi\\addcomment1.ans"
#define INVALID_COMMENT_SCREEN "ansi\\addcommentfail.ans"

#define MENU_MAIN "ansi\\mainmenu.ans"
#define MENU_BUY_TICKETS "ansi\\buyticket.ans"
#define MENU_THEMES "ansi\\themes.ans"
#define MENU_THEMES_CHOICE "ansi\\themeschoice.ans"

#define MENU_PAYMENT "ansi\\payment.ans"
#define MENU_PIX_PAYMENT "ansi\\paymentpix.ans"
#define MENU_PIX_PAYMENT_1 "ansi\\paymentpix1.ans"
#define MENU_PIX_PAYMENT_1_FAIL "ansi\\paymentpix1fail.ans"
#define MENU_CARD_PAYMENT "ansi\\paymentcard.ans"
#define MENU_CARD_PAYMENT_1 "ansi\\paymentcard1.ans"
#define MENU_CARD_PAYMENT_1_FAIL "ansi\\paymentcard1fail.ans"
#define MENU_CARD_PAYMENT_2 "ansi\\paymentcard2.ans"
#define MENU_CARD_PAYMENT_2_FAIL "ansi\\paymentcard2fail.ans"

#define MENU_FULLPRICE "ansi\\normalentry.ans"
#define MENU_FULLPRICE_1 "ansi\\normalentry1.ans"

#define MENU_FREE_ENTRY "ansi\\freeentry.ans"
#define MENU_JUNIOR_ENTRY "ansi\\freeentryjunior.ans"
#define MENU_JUNIOR_ENTRY_1 "ansi\\freeentryjunior1.ans"
#define MENU_JUNIOR_ENTRY_2 "ansi\\freeentryjunior2.ans"
#define MENU_JUNIOR_ENTRY_2_FAIL "ansi\\freeentryjunior2fail.ans"
#define MENU_SENIOR_ENTRY "ansi\\freeentrysenior.ans"
#define MENU_SENIOR_ENTRY_1 "ansi\\freeentrysenior1.ans"
#define MENU_SENIOR_ENTRY_2 "ansi\\freeentrysenior2.ans"
#define MENU_SENIOR_ENTRY_2_FAIL "ansi\\freeentrysenior2fail.ans"

#define MENU_HALFPRICE_ENTRY "ansi\\halfentry.ans"
#define MENU_DISABLED_PERSON_ENTRY "ansi\\halfentrydisabledperson.ans"
#define MENU_DISABLED_PERSON_ENTRY_1 "ansi\\halfentrydisabledperson1.ans"
#define MENU_DISABLED_PERSON_ENTRY_2 "ansi\\halfentrydisabledperson2.ans"
#define MENU_DISABLED_PERSON_ENTRY_2_FAIL "ansi\\halfentrydisabledperson2fail.ans"
#define MENU_STUDENT_ENTRY "ansi\\halfentrystudent.ans"
#define MENU_STUDENT_ENTRY_1 "ansi\\halfentrystudent1.ans"
#define MENU_STUDENT_ENTRY_2 "ansi\\halfentrystudent2.ans"
#define MENU_STUDENT_ENTRY_2_FAIL "ansi\\halfentrystudent2fail.ans"

#define SURVEY_PATHS "ansi\\surveypaths.txt"

#define ARTS_SANTOS_DUMONT "ansi\\santosdumont_paths.txt"
#define ARTS_OLIMPIC_GAMES "ansi\\olimpicgames_paths.txt"
#define ARTS_MODERN_WEEK "ansi\\modernweek_paths.txt"
#define ARTS_TECNOLOGY_SECURITY "ansi\\tecnologysecurity_paths.txt"

void loadScreen(char screen[100]);

/* Função para abrir e ler um arquivo a partir do caminho informado */
void readFile(char file_path[100]);

/* Função para abrir e reescrever um arquivo a partir do caminho informado */
void writeFile(char file_path[100], char input[]);

/* Função para acrescentar uma linha ao arquivo informado */
void appendToFile(char file_path[100], char input[]);

#endif