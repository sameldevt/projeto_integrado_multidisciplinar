#include <stdio.h>
#include "error_handling.h"

int verifyFileExistence(FILE* file) {
	if (file == NULL) {
		perror("Error opening the file: \n");
		return 0;
	}
	return 1;
}
