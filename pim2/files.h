#pragma once
#ifndef FILES
#define FILES

#define MENU_MAIN "resources\\menus\\primary\\main.txt"
#define MENU_BUY_TICKETS "resources\\menus\\primary\\buy_ticket.txt"
#define MENU_THEMES "resources\\menus\\primary\\theme_list.txt"
#define MENU_PAYMENT "resources\\menus\\primary\\payment_type.txt"

#define MENU_PIX_PAYMENT "resources\\menus\\secundary\\payment\\pix.txt"
#define MENU_CARD_PAYMENT "resources\\menus\\secundary\\payment\\card.txt"

#define MENU_HALFPRICE_ENTRY "resources\\menus\\secundary\\entry\\half_price\\half_price_entry.txt"
#define MENU_FREE_ENTRY "resources\\menus\\secundary\\entry\\free\\free_entry.txt"
#define MENU_FULLPRICE "resources\\menus\\secundary\\entry\\full_price_entry.txt"

#define SUBMENU_COMMON_ENTRY "resources\\menus\\secundary\\entry\\full_price_entry.txt"
#define SUBMENU_JUNIOR_ENTRY "resources\\menus\\secundary\\entry\\free\\junior_entry.txt"
#define SUBMENU_SENIOR_ENTRY "resources\\menus\\secundary\\entry\\free\\senior_entry.txt"
#define SUBMENU_DISABLED_PERSON_ENTRY "resources\\menus\\secundary\\entry\\half_price\\disabled_person.txt"
#define SUBMENU_STUDENT_ENTRY "resources\\menus\\secundary\\entry\\half_price\\student.txt"

#define MENU_SANTOS_DUMONT_ARTS "resources\\menus\\secundary\\themes\\santos_dumont.txt"
#define MENU_OLIMPIC_GAMES_ARTS "resources\\menus\\secundary\\themes\\jogos_olimpicos.txt"
#define MENU_MODERN_WEEK_ARTS "resources\\menus\\secundary\\themes\\semana_arte_morderna.txt"

#define MENU_THEME4 "resources\\menus\\secundary\\themes\\tema_a_ser_definido.txt"

#define MENU_NEXT_ART "resources\\menus\\tertiary\\next_art.txt"
#define MENU_BACK "resources\\menus\\tertiary\\back.txt"
#define MAIN_SCREEN "resources\\menus\\tertiary\\main_screen.ans"

/* Lista de caminhos de arquivos 'ansi' */
/* Artes semana da arte moderna */
#define ART_A_NEGRA "resources\\themes\\100_anos_arte_moderna\\a_negra\\a_negra_ansi.ans"
#define ART_ABAPORU "resources\\themes\\100_anos_arte_moderna\\abaporu\\abaporu_ansi.ans"
#define ART_ESTRADA_DE_FERRO "resources\\themes\\100_anos_arte_moderna\\estrada_de_ferro\\estrada_de_ferro_ansi.ans"
#define ART_OPERARIOS "resources\\themes\\100_anos_arte_moderna\\operarios\\operarios_ansi.ans"

/* Artes 150 anos Santos Dumont */
#define ART_SANTOS_DUMONT "resources\\themes\\santos_dumont_150_anos\\santos_dumont\\santos_dumont_ansi.ans"
#define ART_SANTOS_DUMONT2 ""
#define ART_SANTOS_DUMONT3 ""
#define ART_SANTOS_DUMONT4 ""

/* Artes jogos olímpicos 2024 */
#define ART_OLIMPIC_GAMES1 ""
#define ART_OLIMPIC_GAMES2 ""
#define ART_OLIMPIC_GAMES3 ""
#define ART_OLIMPIC_GAMES4 ""

/* Artes tema a ser definido */
#define ART_TEMA_A_SER_DEFINIDO1 ""
#define ART_TEMA_A_SER_DEFINIDO2 ""
#define ART_TEMA_A_SER_DEFINIDO3 ""
#define ART_TEMA_A_SER_DEFINIDO4 ""

/* Questionários */
/* Santos Dumont */
#define SURVEY_SANTOS_DUMONT1 ""
#define SURVEY_SANTOS_DUMONT2 ""
#define SURVEY_SANTOS_DUMONT3 ""
#define SURVEY_SANTOS_DUMONT4 ""

/* Jogos olímpicos */
#define SURVEY_OLIMPIC_GAMES1 ""
#define SURVEY_OLIMPIC_GAMES2 ""
#define SURVEY_OLIMPIC_GAMES3 ""
#define SURVEY_OLIMPIC_GAMES4 ""

/* Arte moderna */
#define SURVEY_MODERN_WEEK1 ""
#define SURVEY_MODERN_WEEK2 ""
#define SURVEY_MODERN_WEEK3 ""
#define SURVEY_MODERN_WEEK4 ""

/* Tema a ser definido */
#define SURVEY_TEMA_A_SER_DEFINIDO1 ""
#define SURVEY_TEMA_A_SER_DEFINIDO2 ""
#define SURVEY_TEMA_A_SER_DEFINIDO3 ""
#define SURVEY_TEMA_A_SER_DEFINIDO4 ""

/* Lista de arquivos .csv */
#define CSV_USERS "resources\\csv_files\\users.csv"
#define CSV_USER_FEEDBACK "resources\\csv_files\\user_feedback.csv"
#define CSV_SURVEY_SUMARY "resources\\csv_files\\survey_sumary.csv"

/* Função para abrir e ler um arquivo a partir do caminho informado */
void readFile(char file_path[100]);

/* Função para abrir e reescrever um arquivo a partir do caminho informado */
void writeFile(char file_path[100], char input[]);

/* Função para acrescentar uma linha ao arquivo informado */
void appendToFile(char file_path[100], char input[]);

#endif