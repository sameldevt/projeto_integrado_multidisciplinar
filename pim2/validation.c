#include <stdio.h>
#include <time.h>

/*
  O direito da meia entrada foi concedido pela implementação
  da lei 9.349/96, para estudantes de educação infantil, ensino fundamental,
  ensino médio e ensino superior, incluindo pós graduação.
*/
int studentIDValidation(char name[100], int studentId) {
	if (sizeof(studentId) > 8) {
		perror("O número de identificação precisa ter, no máximo, 8 digitos!");
		return 0;
	}

	printf("Usuário identificado com sucesso\n");
	return 1;
}

/*
 A carteira de identidade diferenciada é destinada às pessoas
 com deficiência. Ela é uma carteira de identidade civil como outra qualquer,
 mas aponta que seu dono tem algum tipo de deficiência.
 Essa modalidade de documento, no entanto, é emitida de forma gratuita.
 */

int disabledPersonValidation(int disabledPersonId) {
	if (sizeof(disabledPersonId) > 11) {
		perror("O número de identificação precisa ter, no máximo, 11 digitos!");
		return 0;
	}

	printf("Usuário identificado com sucesso\n");
	return 1;
}

int pixPaymentValidation(double value) {
	if (value < 20.0) {
		perror("Quantia insuficiênte");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}

int cardPaymentValidation(char cardHolder[100], int cardNumber, time_t cardExpirationDate, int identificationNumber) {
	if (sizeof(cardNumber) < 12 && sizeof(cardNumber) > 12) {
		perror("O número do cartão informado não é válido");
		return 0;
	}

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if (cardExpirationDate < tm.tm_year) {
		perror("Este cartão está fora do prazo de validade");
		return 0;
	}

	if (identificationNumber > 3 && identificationNumber < 3) {
		perror("Código de segurança inválido");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}