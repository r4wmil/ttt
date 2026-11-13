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


int main() {
	field_init();
	sfield[1][2] = 'x';
	field_draw(-2);
	field_draw(-1);
	field_draw(0);
	field_draw(1);
	field_draw(2);
	field_draw(3);
	field_draw(4);
	field_draw(5);
	field_draw(6);
	field_draw(7);
	field_draw(8);
	while (1) {
		break;
	}
	return 0;
}
