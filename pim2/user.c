#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "files.h"
#include "validation.h"

void registerUser(char name[]) {
	char refac_name[100];
	fsprintf(refac_name, "%s %n", strlen(name));

	appendToFile(csv_users,refac_name);
}