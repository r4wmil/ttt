#include <stdio.h>

char field[9];

void field_init() {
	for (int i = 0; i < 9; i++) { field[i] = '0' + i; }
}

void field_draw() {
	char* f = field;
	printf("\n");
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

bool place_sym(bool is_o, int i) {
	char s = is_o ? 'o' : 'x';
	if (field[i] == 'o' || field[i] == 'x') {
		return 0;
	}
	field[i] = s;
	return 1;
}

char check_win() {
	const int wl[] = {
		0,1,2,
		3,4,5,
		6,7,8,
		0,3,6,
		1,4,7,
		2,5,8,
		0,4,8,
		2,4,6
	};
	char* f = field;
	for (int i = 0; i < sizeof(wl) / sizeof(*wl) / 3; i++) {
		char c1, c2, c3;
		c1 = f[wl[i * 3 + 0]];
		if (c1 != 'o' && c1 != 'x') continue;
		c2 = f[wl[i * 3 + 1]];
		c3 = f[wl[i * 3 + 2]];
		if (c1 == c2 && c2 == c3) { return c1; }
	}
	for (int i = 0; i < 9; i++) {
		if (f[i] != 'o' && f[i] != 'x')
			return '.';
	}
	return 'n';
}

int main() {
	field_init();
	bool is_o = false;
	field_draw();
	char w;
	while (1) {
		printf(" %c turn: ", is_o ? 'o' : 'x');
		int i = get_input();
		if (i == -1) {
			printf("Error. Input: 0-9\n");
			continue;
		}
		if (!place_sym(is_o, i)) {
			printf("Error. Illegal move\n");
			continue;
		}
		field_draw();
		w = check_win();
		if (w != '.') break;
		is_o = !is_o;
	}
	if (w == 'n') {
		printf(" -> Draw.\n");
	}
	if (w == 'x') {
		printf(" -> X won.\n");
	}
	if (w == 'o') {
		printf(" -> O won.\n");
	}
	return 0;
}
