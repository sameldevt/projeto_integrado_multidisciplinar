#include <stdio.h>
#include <time.h>
#include <conio.h>

char keyboardCheck(){
	char key;

	while (1) {
		if (_kbhit()) { // Verifica se uma tecla foi pressionada
			key = _getch(); // Obt�m a tecla pressionada
			printf("Tecla pressionada: %c\n", key);
			if (key == 'q') { // Exemplo de sa�da do loop ao pressionar 'q'
				break;
			}
		}
	}

	return key;
}

/*
  O direito da meia entrada foi concedido pela implementa��o
  da lei 9.349/96, para estudantes de educa��o infantil, ensino fundamental,
  ensino m�dio e ensino superior, incluindo p�s gradua��o.
*/
int tun {
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

int pix_payment_validation(double value) {
	if (value < 20.0) {
		perror("Quantia insufici�nte");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}

int card_payment_validation(char cardHolder[100], int cardNumber, int identificationNumber) {
	if (sizeof(cardNumber) < 12 && sizeof(cardNumber) > 12) {
		perror("O n�mero do cart�o informado n�o � v�lido");
		return 0;
	}

	if (identificationNumber > 3 && identificationNumber < 3) {
		perror("C�digo de seguran�a inv�lido");
		return 0;
	}

	printf("Pagamento feito com sucesso\n");
	return 1;
}