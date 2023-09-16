#include <stdio.h>
#include "files.h"

/* Lista de caminhos de arquivos 'menu' */
const char menu_main[100] = "resources\\menus\\primary\\main.txt";
const char menu_buy_tickets[100] = "resources\\menus\\primary\\buy_ticket.txt";
const char menu_themes[100] = "resources\\menus\\primary\\theme_list.txt";
const char menu_payment[100] = "resources\\menus\\primary\\payment_type.txt";

const char menu_halfprice_entry[100] = "resources\\menus\\secundary\\entry\\half_price\\half_price_entry.txt";
const char menu_free_entry[100] = "resources\\menus\\secundary\\entry\\free\\free_entry.txt";
const char menu_fullprice[100] = "resources\\menus\\secundary\\entry\\full_price_entry.txt";


const char submenu_junior_entry[100] = "resources\\menus\\secundary\\entry\\free\\junior_entry.txt";
const char submenu_senior_entry[100] = "resources\\menus\\secundary\\entry\\free\\senior_entry.txt";
const char submenu_disabled_person_entry[100] = "resources\\menus\\secundary\\entry\\half_price\\disabled_person.txt";
const char submenu_student_entry[100] = "resources\\menus\\secundary\entry\\half_price\\student.txt";

const char menu_santos_dumont_arts[100] = "resources\\menus\\secundary\\themes\\santos_dumont.txt";
const char menu_olimpic_games_arts[100] = "resources\\menus\\secundary\\themes\\jogos_olimpicos.txt";
const char menu_modern_week_arts[100] = "resources\\menus\\secundary\\themes\\semana_arte_morderna.txt";

const char menu_theme4[100] = "resources\\menus\\secundary\\themes\\tema_a_ser_definido.txt";

const char menu_next_art[100] = "resources\\menus\\tertiary\\next_art.txt";
const char menu_back[100] = "resources\\menus\\tertiary\\back.txt";

/* Lista de caminhos de arquivos 'ansi' */
/* Artes semana da arte moderna */
const char art_a_negra[100] = "resources\\themes\\100_anos_arte_moderna\\a_negra\\a_negra_ansi.ans";
const char art_abaporu[100] = "resources\\themes\\100_anos_arte_moderna\\abaporu\\abaporu_ansi.ans";
const char art_estrada_de_ferro[100] = "resources\\themes\\100_anos_arte_moderna\\estrada_de_ferro\\estrada_de_ferro_ansi.ans";
const char art_operarios[100] = "resources\\themes\\100_anos_arte_moderna\\operarios\\operarios_ansi.ans";

/* Artes 150 anos Santos Dumont */
const char art_santos_dumont[100] = "resources\\themes\\santos_dumont_150_anos\\santos_dumont\\santos_dumont_ansi.ans";
const char art_santos_dumont2[100] = "";
const char art_santos_dumont3[100] = "";
const char art_santos_dumont4[100] = "";

/* Artes jogos ol�mpicos 2024 */
const char art_olimpic_games1[100] = "";
const char art_olimpic_games2[100] = "";
const char art_olimpic_games3[100] = "";
const char art_olimpic_games4[100] = "";

/* Artes tema a ser definido */
const char art_tema_a_ser_definido1[100] = "";
const char art_tema_a_ser_definido2[100] = "";
const char art_tema_a_ser_definido3[100] = "";
const char art_tema_a_ser_definido4[100] = "";

/* Questionarios */
/* Santos Dumont */
const char survey_santos_dumont1[100] = "";
const char survey_santos_dumont2[100] = "";
const char survey_santos_dumont3[100] = "";
const char survey_santos_dumont4[100] = "";

/* Jogos olimpicos */
const char survey_olimpic_games1[100] = "";
const char survey_olimpic_games2[100] = "";
const char survey_olimpic_games3[100] = "";
const char survey_olimpic_games4[100] = "";

/* Arte moderna */
const char survey_modern_week1[100] = "";
const char survey_modern_week2[100] = "";
const char survey_modern_week3[100] = "";
const char survey_modern_week4[100] = "";

/* Tema a ser definido */
const char survey_tema_a_ser_definido1[100] = "";
const char survey_tema_a_ser_definido2[100] = "";
const char survey_tema_a_ser_definido3[100] = "";
const char survey_tema_a_ser_definido4[100] = "";

/* Lista de arquivos .csv */
const char csv_users[100] = "resources\\csv_files\\users.csv";
const char csv_user_feedback[100] = "resources\\csv_files\\user_feedback.csv";
const char csv_survey_sumary[100] = "resources\\csv_files\\survey_sumary.csv";

void readFile(char file_path[100]) {

	FILE** file_pointer;

	file_pointer = fopen(file_path, "r");

	char buffer[256];

	while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
		printf("%s", buffer);
	}

	fclose(file_pointer);
}

void writeFile(char file_path[100], char input[]) {

	FILE** file_pointer;

	file_pointer = fopen(file_path, "w");

	fputs(input, file_pointer);

	fclose(file_pointer);
}

void appendToFile(char file_path[100], char input[]) {
	char input_ref[100];

	FILE** file_pointer;

	file_pointer = fopen(file_path, "a");

	fsprintf(input_ref, "%s,", input);

	fprintf(file_pointer, input);

	fclose(file_pointer);
}