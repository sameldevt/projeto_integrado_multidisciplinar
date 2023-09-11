#include <stdio.h>
#include "error_handling.h"

/* Verifica se o arquivo existe */
int verify_file(FILE* file) {
	if (file == NULL) {
		perror("Error opening the file: \n");
		return 0;
	}
	return 1;
}
