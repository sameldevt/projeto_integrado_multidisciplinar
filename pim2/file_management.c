#include <stdio.h>
#include "file_management.h"

/* Lista de caminhos de arquivos 'menu' */
char menu_main[100] = "resources\\menus\\menu_principal.txt";
char menu_buy_tickets[100] = "resources\\menus\\menu_comprar_ingresso.txt";
char menu_themes[100] = "resources\\menus\\menu_lista_de_temas.txt";
char menu_halfprice_entry[100] = "resources\\menus\\menu_meia_entrada.txt";
char menu_free_entry[100] = "resources\\menus\\menu_entrada_gratuita.txt";
char menu_payment[100] = "resources\\menus\\menu_tipo_de_pagamento.txt";

char menu_santos_dumont_arts[100] = "resources\\menus\\artes_santos_dumont_obras.txt";
char menu_olimpic_games_arts[100] = "resources\\menus\\artes_jogos_olimpicos_obras.txt";
char menu_modern_week_arts[100] = "resources\\menus\\artes_semana_arte_moderna.txt";

char menu_theme4[100] = "resources\\menus\\artes_tema_a_ser_definido.txt";

char menu_next_art[100] = "resources\\menus\\menu_proxima_arte.txt";

/* Lista de caminhos de arquivos 'ansi' */
/* Artes semana da arte moderna */
char art_a_negra[100] = "resources\\100_anos_arte_moderna\\a_negra\\a_negra_ansi.ans";
char art_abaporu[100] = "resources\\100_anos_arte_moderna\\abaporu\\abaporu_ansi.ans";
char art_estrada_de_ferro[100] = "resources\\100_anos_arte_moderna\\estrada_de_ferro\\estrada_de_ferro_ansi.ans";
char art_operarios[100] = "resources\\100_anos_arte_moderna\\operarios\\operarios_ansi.ans";

/* Artes 150 anos Santos Dumont */
char art_santos_dumont[100] = "resources\\santos_dumont_150_anos\\santos_dumont\\santos_dumont_ansi.ans";
char art_santos_dumont2[100] = "resources\\santos_dumont_150_anos\\";
char art_santos_dumont3[100] = "resources\\santos_dumont_150_anos\\";
char art_santos_dumont4[100] = "resources\\santos_dumont_150_anos\\";

/* Artes jogos olímpicos 2024 */
char art_olimpic_games1[100] = "resources\\jogos_olimpicos_2024\\";
char art_olimpic_games2[100] = "resources\\jogos_olimpicos_2024\\";
char art_olimpic_games3[100] = "resources\\jogos_olimpicos_2024\\";
char art_olimpic_games4[100] = "resources\\jogos_olimpicos_2024\\";

/* Artes tema a ser definido */
char art_tema_a_ser_definido1[100] = "resources\\";
char art_tema_a_ser_definido2[100] = "resources\\";
char art_tema_a_ser_definido3[100] = "resources\\";
char art_tema_a_ser_definido4[100] = "resources\\";

/* Questionarios */
/* Santos Dumont */
char survey_santos_dumont1[100] = "resources\\santos_dumont\\questionarios\\";
char survey_santos_dumont2[100] = "resources\\santos_dumont\\questionarios\\";
char survey_santos_dumont3[100] = "resources\\santos_dumont\\questionarios\\";
char survey_santos_dumont4[100] = "resources\\santos_dumont\\questionarios\\";

/* Jogos olimpicos */
char survey_olimpic_games1[100] = "resources\\jogos_olimpicos_2024\\questionarios\\";
char survey_olimpic_games2[100] = "resources\\jogos_olimpicos_2024\\questionarios\\";
char survey_olimpic_games3[100] = "resources\\jogos_olimpicos_2024\\questionarios\\";
char survey_olimpic_games4[100] = "resources\\jogos_olimpicos_2024\\questionarios\\";

/* Arte moderna */
char survey_modern_week1[100] = "resources\\100_anos_arte_moderna\\questionarios\\";
char survey_modern_week2[100] = "resources\\100_anos_arte_moderna\\questionarios\\";
char survey_modern_week3[100] = "resources\\100_anos_arte_moderna\\questionarios\\";
char survey_modern_week4[100] = "resources\\100_anos_arte_moderna\\questionarios\\";

/* Tema a ser definido */
char survey_tema_a_ser_definido1[100] = "resources\\tema_a_ser_definido\\questionarios\\";
char survey_tema_a_ser_definido2[100] = "resources\\tema_a_ser_definido\\questionarios\\";
char survey_tema_a_ser_definido3[100] = "resources\\tema_a_ser_definido\\questionarios\\";
char survey_tema_a_ser_definido4[100] = "resources\\tema_a_ser_definido\\questionarios\\";

/* Lista de arquivos .csv */
char csv_users[100] = "resources\\csv_files\\users.csv";
char csv_user_feedback[100] = "resources\\csv_files\\user_feedback.csv";


/* Abre um arquivo a partir do caminho informado */
void read_file(char file_path[100]) {

	FILE** file_pointer;

	file_pointer = fopen(file_path, "r");



	char buffer[256];

	while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
		printf("%s", buffer);
	}

	fclose(file_pointer);
}

/* Reescreve o arquivo por completo */
void rewrite_file(char file_path[100], char input[]) {

	FILE** file_pointer;

	file_pointer = fopen(file_path, "w");

	fputs(input, file_pointer);

	fclose(file_pointer);
}

/* Acrescenta uma linha ao arquivo informado */
void append_to_file(char file_path[100], char input[]) {

	FILE** file_pointer;

	file_pointer = fopen(file_path, "a");

	fprintf(file_pointer, input);

	fclose(file_pointer);
}

/* Carrega uma arte de acordo com o seu tema */
int load_art(int theme, int art) {
	switch (theme) {
	case 0: 
		switch(art){
		case 0: 
			read_file(art_a_negra);
			break;
		case 1: 
			read_file(art_abaporu);
			break;
		case 2: 
			read_file(art_estrada_de_ferro);
			break;
		case 3: 
			read_file(art_operarios);
			break;
		}
	case 1:
		switch(art){
		case 0: 
			read_file(art_olimpic_games1);
			break;
		case 1: 
			read_file(art_olimpic_games2);
			break;
		case 2: 
			read_file(art_olimpic_games3);
			break;
		case 3: 
			read_file(art_olimpic_games4);
			break;
		}
	case 2:
		switch(art){
		case 0: 
			read_file(art_santos_dumont);
			break;
		case 1: 
			read_file(art_santos_dumont2);
			break;
		case 2: 
			read_file(art_santos_dumont3);
			break;
		case 3: 
			read_file(art_santos_dumont4);
			break;
		}
	case 3:
		switch(art){
		case 0: 
			read_file(art_tema_a_ser_definido1);
			break;
		case 1: 
			read_file(art_tema_a_ser_definido2);
			break;
		case 2: 
			read_file(art_tema_a_ser_definido3);
			break;
		case 3: 
			read_file(art_tema_a_ser_definido4);
			break;
		}
	}
}

/* Registra um usuario no sistema */
void register_user(char name[50]) {
	char user[50];
	int i = 0;

	while (user[i]) {
        user[i] = toupper(name[i]);
        i++;
    }
	
	append_to_file(csv_users, user);
}
