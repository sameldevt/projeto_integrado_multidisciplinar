#include <stdio.h>
#include "error_handling.h"

/* Função para verificar se o arquivo a ser aberto existe */

int verify_file_existence(FILE** file) {
	if (file == NULL) {
		perror("Error opening the file: \n");
		return 0;
	}
	return 1;
}
