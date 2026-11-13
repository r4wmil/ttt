#include <stdio.h>

char field[81];

void field_draw() {
	char* f = field;
	for (int i = 0; i < 81; i++) {
		if (i % 9 == 0)
			printf("  ");
		printf("%c ", f[i]);
		if (i % 9 != 8 && i % 3 == 2)
			printf("|");
		if (i % 9 == 8)
			printf("\n");
		if (i != 80 && i % 27 == 26)
			printf("  ------+------+------\n");
	}
}

void field_init() {
	for (int i = 0; i < 81; i++) { field[i] = '.'; }
}


int main() {
	field_init();
	field_draw();
	while (1) {
		break;
	}
	return 0;
}
