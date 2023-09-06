#include <stdio.h>
#include <time.h>

#include "print_functions.h"
#include "file_management.h"

int printArt(char artPath[50]) {

	readFile(artPath);

	return 0;
}

int printArtSurvey(char artSurvey[50]) {
	
	readFile(artSurvey);
	
	return 0;
}

void printMainMenu(){
	
}

void printTicketShopMenu(){
	printf("+------------------------------------------+");	
	printf("| > Escolha o tipo de ingresso             |");
	printf("+------------------------------------------+");
	printf("| 1. Entrada normal                        |");
	printf("| 2. Meia entrada	                       |");
	printf("| 3. Entrada gratuita                      |");
	printf("| 4. Voltar								   |");
	printf("+------------------------------------------+");
}

void printPaymentMenu(){
	printf("+------------------------------------------+");	
	printf("| > Escolha o tipo de pagamento            |");
	printf("+------------------------------------------+");
	printf("| 1. Cartão de crédito/débito              |");
	printf("| 2. Pix 			                       |");
	printf("| 3. Voltar								   |");
	printf("+------------------------------------------+");	
}

/* 
  lei 12933 2013

  Relata o benefício do pagamento de meia-entrada para estudantes, 
  pessoas com deficiência, idosos e jovens carentes com idade entre   
  15 e 29 anos em eventos culturais, esportivos e artísticos, revogando a
  medida provisória de 2001, nº 2.208
  */

void printBenefitValidationMenu(){
	printf("+------------------------------------------+");	
	printf("| > Escolha uma opção                      |");
	printf("+------------------------------------------+");
	printf("| 1. Pessoa com deficiência                |");
	printf("| 2. Pessoa com mais de 60 anos de idade   |");
	printf("| 3. Pessoa estudante                      |");
	printf("| 4. Voltar								   |");
	printf("+------------------------------------------+");	
}
