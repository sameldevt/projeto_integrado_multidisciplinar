#pragma once
#ifndef FILE_MANAGEMENT
#define FILE_MANAGEMENT

/* Lista de caminhos de arquivos 'menu' */
const char menu_main[100];
const char menu_buy_tickets[100];
const char menu_themes[100];
const char menu_halfprice_entry[100];
const char menu_free_entry[100];
const char menu_payment[100];

const char menu_fullprice[100];

const char submenu_junior_entry[100];
const char submenu_senior_entry[100];
const char submenu_disabled_person_entry[100];
const char submenu_student_entry[100];

const char menu_santos_dumont_arts[100];
const char menu_olimpic_games_arts[100];
const char menu_modern_week_arts[100];

const char menu_theme4[100];

const char menu_next_art[100];
const char menu_back[100];

/* Lista de caminhos de arquivos 'ansi' */
/* Artes semana da arte moderna */
const char art_a_negra[100];
const char art_abaporu[100];
const char art_estrada_de_ferro[100];
const char art_operarios[100];

/* Artes 150 anos Santos Dumont */
const char art_santos_dumont[100];
const char art_santos_dumont2[100];
const char art_santos_dumont3[100];
const char art_santos_dumont4[100];

/* Artes jogos olímpicos 2024 */
const char art_olimpic_games1[100];
const char art_olimpic_games2[100];
const char art_olimpic_games3[100];
const char art_olimpic_games4[100];

/* Artes tema a ser definido */
const char art_tema_a_ser_definido1[100];
const char art_tema_a_ser_definido2[100];
const char art_tema_a_ser_definido3[100];
const char art_tema_a_ser_definido4[100];

/* Questionarios */
/* Santos Dumont */
const char survey_santos_dumont1[100];
const char survey_santos_dumont2[100];
const char survey_santos_dumont3[100];
const char survey_santos_dumont4[100];

/* Jogos olimpicos */
const char survey_olimpic_games1[100];
const char survey_olimpic_games2[100];
const char survey_olimpic_games3[100];
const char survey_olimpic_games4[100];

/* Arte moderna */
const char survey_modern_week1[100];
const char survey_modern_week2[100];
const char survey_modern_week3[100];
const char survey_modern_week4[100];

/* Tema a ser definido */
const char survey_tema_a_ser_definido1[100];
const char survey_tema_a_ser_definido2[100];
const char survey_tema_a_ser_definido3[100];
const char survey_tema_a_ser_definido4[100];

/* Lista de arquivos .csv */
const char csv_users[100];
const char csv_user_feedback[100];
const char csv_survey_sumary[100];

void read_file(char file_path[100]);

void rewrite_file(char file_path[100], char input[]);

void append_to_file(char file_path[100], char input[]);

void register_user(char name[50]);

int load_art(int theme, int art);

int load_survey(int theme, int question);

#endif