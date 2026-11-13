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

int get_input() {
	char c, f;
	f = getc(stdin);
	int i = 0;
	while (1) {
		c = getc(stdin);
		if (c == '\n') break;
		i++;
	}
	if (i != 0) return -1;
	if (f < '0' || f > '9') return -1;
	return f - '0';
}

int main() {
	field_init();
	while (1) {
		int i = get_input();
		printf("%d\n", i);
		field_draw();
	}
	return 0;
}
