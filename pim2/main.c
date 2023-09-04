#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "print_functions.h"
#include "file_management.h"

const char art1Description[100] = "Resource Files\\arts\\art1\\art.txt";

int main() {

	readFile(art1Description);

	return 0;
}
