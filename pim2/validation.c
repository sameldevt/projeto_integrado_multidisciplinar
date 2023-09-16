﻿#include <stdio.h>
#include <time.h>
#include <conio.h>

/*
  O direito da meia entrada foi concedido pela implementa��o
  da lei 9.349/96, para estudantes de educa��o infantil, ensino fundamental,
  ensino m�dio e ensino superior, incluindo p�s gradua��o.
*/
int validateStudentId(int student_id) {
	if (sizeof(student_id) > 8) {
		return 0;
	}
	return 1;
}

/*
 A carteira de identidade diferenciada � destinada �s pessoas
 com defici�ncia. Ela � uma carteira de identidade civil como outra qualquer,
 mas aponta que seu dono tem algum tipo de defici�ncia.
 Essa modalidade de documento, no entanto, � emitida de forma gratuita.
 */

int vaslidateDisabledPersonId(int disabled_person_id) {
	
}

int validatePixPayment(float value) {
	if (value < 20.0) {
		perror("Saldo insufici�nte");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}

int validateCardPayment(char card_holder[101], int card_number, int identification_number) {
	if (sizeof(card_number) < 12 && sizeof(card_number) > 12) {
		perror("O n�mero do cart�o informado n�o � v�lido");
		return 0;
	}

	if (identification_number > 3 && identification_number < 3) {
		perror("C�digo de seguran�a inv�lido");
		return 0;
	}

	return 1;
}