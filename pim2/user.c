#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "files.h"

/* Arquivo com funções de manipulação de usuários */

int registerUser(char name[51]) {
	appendToFile(CSV_USERS, name);
	return 0;
}