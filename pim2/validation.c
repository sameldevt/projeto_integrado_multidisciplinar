#include <stdio.h>
#include <time.h>
#include <conio.h>

char keyboardCheck(){
	char key;

	while (1) {
		if (_kbhit()) { // Verifica se uma tecla foi pressionada
			key = _getch(); // Obtém a tecla pressionada
			printf("Tecla pressionada: %c\n", key);
			if (key == 'q') { // Exemplo de saída do loop ao pressionar 'q'
				break;
			}
		}
	}

	return key;
}

/*
  O direito da meia entrada foi concedido pela implementação
  da lei 9.349/96, para estudantes de educação infantil, ensino fundamental,
  ensino médio e ensino superior, incluindo pós graduação.
*/
int tun {
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

int pix_payment_validation(double value) {
	if (value < 20.0) {
		perror("Quantia insuficiênte");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}

int card_payment_validation(char cardHolder[100], int cardNumber, int identificationNumber) {
	if (sizeof(cardNumber) < 12 && sizeof(cardNumber) > 12) {
		perror("O número do cartão informado não é válido");
		return 0;
	}

	if (identificationNumber > 3 && identificationNumber < 3) {
		perror("Código de segurança inválido");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}