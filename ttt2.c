#include <stdio.h>
#include <string.h>

char sfield[9][9];

void field_init() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sfield[i][j] = '.';
		}
	}
}

void field_draw(int mode) {
	// mode -> -2 -1 0 1 2 3 4 5 6 7 8
	for (int y = 0; y < 9; y++) {
		if (y % 3 == 0) {
			if (mode != -1) {
				printf("------+-------+------\n");
			} else {
				printf("-<%d>--+-<%d>---+-<%d>--\n", y + 0, y + 1, y + 2);
			}
		}
		for (int x = 0; x < 9; x++) {
			int i = (y / 3) * 3 + (x / 3);
			int j = (y % 3) * 3 + (x % 3);
			char c = sfield[i][j];
			if (c == '.' && i == mode) {
				printf("%c ", '0' + j);//sfield[i][j]);
			} else {
				printf("%c ", c);
			}
			if (x != 8 && x % 3 == 2)
				printf("| ");
			if (x == 8)
				printf("\n");
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
	if (f < '0' || f > '9') return -1;
	return f - '0';
}

bool place_sym(bool is_o, int i, int j) {
	char s = is_o ? 'o' : 'x';
	if (sfield[i][j] == 'o' || sfield[i][j] == 'x') {
		return 0;
	}
	sfield[i][j] = s;
	return 1;
}

int main() {
	field_init();
	field_draw(-1);
	int mode = -1;
	bool is_o = 0;
	while (1) {
		if (mode == -1) {
			printf("Choose field: ");
			int i = get_input();
			if (i == -1) {
				printf("Error. Input: 0-9\n");
				continue;
			}
			mode = i;
			field_draw(mode);
		}
		printf("Choose field cell: ");
		int i = get_input();
		if (i == -1) {
			printf("Error. Input: 0-9\n");
			continue;
		}
		if (!place_sym(is_o, mode, i)) {
			printf("Error. Illegal move\n");
			continue;
		}
		field_draw(mode);
		is_o = !is_o;
		break;
	}
	return 0;
}
