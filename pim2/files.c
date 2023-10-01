#include <stdio.h>
#include <stdlib.h>

void loadScreen(char screen[100]) {
	system("cls");

	FILE** file_pointer;

	file_pointer = fopen(screen, "r");

	char buffer[256];

	while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
		printf("%s", buffer);
	}

	fclose(file_pointer);
}

void readFile(char file_path[100]) {

	FILE** file_pointer;

	file_pointer = fopen(file_path, "r");

	char buffer[256];

	while (fgets(buffer, sizeof(buffer), file_pointer) != NULL) {
		printf("%s", buffer);
	}

	fclose(file_pointer);
}

void writeFile(char file_path[100], char input[]) {

	FILE** file_pointer;

	file_pointer = fopen(file_path, "w");

	fputs(input, file_pointer);

	fclose(file_pointer);
}

void appendToFile(char file_path[100], char input[]) {
	char input_ref[100];

	FILE** file_pointer;

	file_pointer = fopen(file_path, "a");

	sprintf(input_ref, "%s,", input);

	fprintf(file_pointer, input);

	fclose(file_pointer);
}