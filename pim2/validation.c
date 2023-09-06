#include <stdio.h>
#include <time.h>

/*
  O direito da meia entrada foi concedido pela implementa��o
  da lei 9.349/96, para estudantes de educa��o infantil, ensino fundamental,
  ensino m�dio e ensino superior, incluindo p�s gradua��o.
*/
int studentIDValidation(char name[100], int studentId) {
	if (sizeof(studentId) > 8) {
		perror("O n�mero de identifica��o precisa ter, no m�ximo, 8 digitos!");
		return 0;
	}

	printf("Usu�rio identificado com sucesso\n");
	return 1;
}

/*
 A carteira de identidade diferenciada � destinada �s pessoas
 com defici�ncia. Ela � uma carteira de identidade civil como outra qualquer,
 mas aponta que seu dono tem algum tipo de defici�ncia.
 Essa modalidade de documento, no entanto, � emitida de forma gratuita.
 */

int disabledPersonValidation(int disabledPersonId) {
	if (sizeof(disabledPersonId) > 11) {
		perror("O n�mero de identifica��o precisa ter, no m�ximo, 11 digitos!");
		return 0;
	}

	printf("Usu�rio identificado com sucesso\n");
	return 1;
}

int pixPaymentValidation(double value) {
	if (value < 20.0) {
		perror("Quantia insufici�nte");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}

int cardPaymentValidation(char cardHolder[100], int cardNumber, time_t cardExpirationDate, int identificationNumber) {
	if (sizeof(cardNumber) < 12 && sizeof(cardNumber) > 12) {
		perror("O n�mero do cart�o informado n�o � v�lido");
		return 0;
	}

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if (cardExpirationDate < tm.tm_year) {
		perror("Este cart�o est� fora do prazo de validade");
		return 0;
	}

	if (identificationNumber > 3 && identificationNumber < 3) {
		perror("C�digo de seguran�a inv�lido");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}