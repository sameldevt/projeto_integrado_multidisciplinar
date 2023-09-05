#include <stdio.h>
#include "print_functions.h"
#include <time.h>

int printArt() {
	return 0;
}

int printArtSurvey(char survey[]) {
	return 0;
}


int printMenuOptions(char menu[]) {
	return 0;
}

struct User{
	char name[100];
	int type = NULL;
}

void printMainMenu(){
	printf("+------------------------------------------+");	
	printf("| > Escolha uma opção                      |");
	printf("+------------------------------------------+");
	printf("| 1. Comprar ingresso                      |");
	printf("| 2. Ver lista de obras                    |");
	printf("| 3. Sair								   |");
	printf("+------------------------------------------+");
}

void printTicketShopMenu{
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

int pixPaymentValidation(double value){
	if(value < 20.0){
		perror("Quantia insuficiênte");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}

int cardPaymentValidation(char cardHolder[100], int cardNumber, time_t cardExpirationDate, int identificationNumber){
	if(sizeof(cardNumber) < 12 && sizeof(cardNumber) > 12){
		perror("O número do cartão informado não é válido");
		return 0;
	}

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if(cardExpirationDate < tm.tm_year){
		perror("Este cartão está fora do prazo de validade");
		return 0;
	}

	if(identificationNumber > 3 && identificationNumber < 3){
		perror("Código de segurança inválido");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
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

/*
  O direito da meia entrada foi concedido pela implementação 
  da lei 9.349/96, para estudantes de educação infantil, ensino fundamental,
  ensino médio e ensino superior, incluindo pós graduação.
*/
int studentIDValidation(char name[100], int studentId){
	if(sizeof(studentId) > 8){
		perror("O número de identificação precisa ter, no máximo, 8 digitos!");
		return 0;
	}

	struct User user;
	user->name = name;
	user->type = 1;

	printf("Usuário identificado com sucesso\n");
	return 1;
}

/*
 A carteira de identidade diferenciada é destinada às pessoas 
 com deficiência. Ela é uma carteira de identidade civil como outra qualquer,
 mas aponta que seu dono tem algum tipo de deficiência.
 Essa modalidade de documento, no entanto, é emitida de forma gratuita.
 */

int disabledPersonValidation(int disabledPersonId){
	if(sizeof(disabledPersonId) > 11){
		perror("O número de identificação precisa ter, no máximo, 11 digitos!");
		return 0;
	}

	struct User user;
	user->name = name;
	user->type = 2;

	printf("Usuário identificado com sucesso\n");
	return 1;
}

int choice;
printf("Choose an option: ");
scanf("%d", &choice);

switch (choice) {
	case 1: {
		
	}
	case 2:
	case 3:

	break;

default:
	break;
}
