#include <stdio.h>

char field[9];

void field_init() {
	for (int i = 0; i < 9; i++) { field[i] = '0' + i; }
}

void field_draw() {
	char* f = field;
	printf("  %c | %c | %c\n", f[0], f[1], f[2]);
	printf(" ---+---+---\n");
	printf("  %c | %c | %c\n", f[3], f[4], f[5]);
	printf(" ---+---+---\n");
	printf("  %c | %c | %c\n", f[6], f[7], f[8]);
}

int main() {
	field_init();
	while (1) {
		char c;
		while (1) {
			c = getc(stdin);
			if (c == '\n') break;
		}
		field_draw();
	}
	return 0;
}
