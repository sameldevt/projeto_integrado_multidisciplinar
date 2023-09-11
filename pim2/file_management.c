#include <stdio.h>
#include "file_management.h"

/* Lista de caminhos de arquivos 'menu' */

char main_menu[100] = "resources\\menus\\menu_principal.txt";
char buy_tickets_menu[100] = "resources\\menus\\comprar_ingresso.txt";
char art_list_menu[100] = "resources\\menus\\lista_de_obras.txt";
char person_type_menu[100] = "resources\\menus\\tipo_de_pessoa.txt";
char payment_type_menu[100] = "resources\\menus\\tipo_de_pagamento.txt";
char theme4_menu[100] = "resources\\menus\\tema_a_ser_definido.txt";
char santos_dumont_arts_menu[100] = "resources\\menus\\santos_dumont_obras.txt";
char olimpic_games_2024_arts_menu[100] = "resources\\menus\\jogos_olimpicos_obras.txt";
char modern_week_arts_menu[100] = "resources\\menus\\comprar_ingresso.txt";


/* Abre um arquivo a partir do caminho informado */

void readFile(char filePath[50]) {

	FILE** filePointer;

	filePointer = fopen(filePath, "r");

	char buffer[256];

	while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
		printf("%s", buffer);
	}

	fclose(filePointer);
}

/* Reescreve o arquivo por completo */

void rewriteFile(char filePath[], char input[]) {

	FILE** filePointer;

	filePointer = fopen(filePath, "w");

	fputs(input, filePointer);

	fclose(filePointer);
}

/* Acrescenta uma linha ao arquivo informado */

void appendToFile(char filePath[], char input[]) {

	FILE** filePointer;

	filePointer = fopen(filePath, "a");

	fprintf(filePointer, input);

	fclose(filePointer);
}

