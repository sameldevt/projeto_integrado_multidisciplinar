#include <stdio.h>
#include "file_management.h"

const FILE** filePointer;

void readFile(char filePath[50]) {

	filePointer = fopen(filePath, "r");

	if (verifyFileExistence(filePointer)) {
		perror("File not found");
	}

	char buffer[256];

	while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
		printf("%s", buffer);
	}

	fclose(filePointer);
}

void reWriteFile(char filePath[], char input[]) {

	filePointer = fopen(filePath, "w");

	if (verifyFileExistence(filePointer)) {
		perror("Error opening the file");
	}

	/* logic to re-write the file */

	fputs(input, filePointer);

	/*------------------------------------*/
	fclose(filePointer);
}

void appendToFile(char filePath[], char input[]) {

	filePointer = fopen(filePath, "a");

	if (verifyFileExistence(filePointer)) {
		perror("Error opening the file");
	}

	/* logic to append to the file */

	fprintf(filePointer, input);

	/*------------------------------------*/
	fclose(filePointer);
}
