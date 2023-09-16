#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "files.h"

char keyboardCheck() {
	char key;

	while (1) {
		if (_kbhit()) {
			key = _getch();
			return key;
		}
	}
}

void threeSecTimer() {
	int time = 0;
	while (time < 3) {
		printf(" .");
		Sleep(1000);
		time++;
	}
}
