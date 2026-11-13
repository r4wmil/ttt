#include <stdio.h>

char field[9];

void field_init() {
	for (int i = 0; i < 9; i++) { field[i] = '.'; }
}

void field_draw() {
	char* f = field;
	printf("  %c %c %c\n", f[0], f[1], f[2]);
	printf("  %c %c %c\n", f[3], f[4], f[5]);
	printf("  %c %c %c\n", f[6], f[7], f[8]);
}

int main() {
	field_init();
	field_draw();
	return 0;
}
