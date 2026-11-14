#include <stdio.h>

char wins[9];
char sfield[9][9];

bool is_xo(char c) { return c == 'x' || c == 'o'; }

void field_init() {
	for (int i = 0; i < 81; i++) {
		sfield[i / 9][i % 9] = '.';
	}
}

void field_draw(int mode) {
	for (int y = 0; y < 9; y++) {
		if (y % 3 == 0) {
			if (mode != -1) {
				printf("------+-------+------\n");
			} else {
				printf("-<%d>--+-<%d>---+-<%d>--\n", y + 1, y + 2, y + 3);
			}
		}
		for (int x = 0; x < 9; x++) {
			int i = (y / 3) * 3 + (x / 3);
			int j = (y % 3) * 3 + (x % 3);
			char c = sfield[i][j];
			if (is_xo(wins[i])) {
				printf("%c ", wins[i]);
			} else {
				bool is_num = (c == '.' && i == mode);
				printf("%c ", is_num ? '1' + j : c);
			}
			if (x != 8 && x % 3 == 2) printf("| ");
			if (x == 8) printf("\n");
		}
	}
	printf("\n");
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
	if (f < '1' || f > '9') return -1;
	return f - '1';
}

bool place_sym(bool is_o, int i, int j) {
	char s = is_o ? 'o' : 'x';
	if (is_xo(sfield[i][j])) {
		return 0;
	}
	sfield[i][j] = s;
	return 1;
}

char check_win(char* f) {
	const int wl[] = {
		0,1,2, 3,4,5, 6,7,8,
		0,3,6, 1,4,7, 2,5,8,
		0,4,8, 2,4,6
	};
	for (int i = 0; i < sizeof(wl) / sizeof(*wl) / 3; i++) {
		char c1, c2, c3;
		c1 = f[wl[i * 3 + 0]];
		c2 = f[wl[i * 3 + 1]];
		c3 = f[wl[i * 3 + 2]];
		if (!is_xo(c1)) continue;
		if (c1 == c2 && c2 == c3) { return c1; }
	}
	for (int i = 0; i < 9; i++) {
		if (!is_xo(f[i])) return '.';
	}
	return 'n';
}

int main() {
	field_init();
	field_draw(-1);
	int mode = -1;
	bool is_o = 0;
	char w;
	while (1) {
		int i;
		if (mode == -1 || is_xo(wins[mode])) {
			printf("%c turn. Field: ", is_o ? 'O' : 'X');
			i = get_input();
			if (i == -1) {
				printf("Error. Input: 1-9\n");
				continue;
			}
			if (is_xo(wins[i])) {
				printf("Error. Can't choose this field.\n");
				continue;
			}
			mode = i;
			field_draw(mode);
		}
		printf("%c turn: ", is_o ? 'O' : 'X');
		i = get_input();
		if (i == -1) {
			printf("Error. Input: 1-9\n");
			continue;
		}
		if (!place_sym(is_o, mode, i)) {
			printf("Error. Illegal move\n");
			continue;
		}
		w = check_win(sfield[mode]);
		if (is_xo(w)) {
			wins[mode] = w;
		}
		mode = i;
		if (is_xo(wins[mode])) mode = -1;
		field_draw(mode);
		w = check_win(wins);
		if (is_xo(w)) { break; }
		is_o = !is_o;
	}
	switch (w) {
		case 'n': printf(" -> Draw.\n"); break;
		case 'x': printf(" -> X won.\n"); break;
		case 'o': printf(" -> O won.\n"); break;
	}
	return 0;
}
