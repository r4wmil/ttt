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
	// mode -> -1 0 1 2 3 4 5 6 7 8
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			int i = (y / 3) * 3 + (x / 3);
			int j = (y % 3) * 3 + (x % 3);
			//printf("%c ", '0' + j);//sfield[i][j]);
			printf("%c ", sfield[i][j]);
			if (x != 8 && x % 3 == 2)
				printf("| ");
			if (x == 8)
				printf("\n");
		}
		if (y % 3 == 2)
			printf("------+-------+------\n");
	}
}


int main() {
	field_init();
	sfield[1][2] = 'x';
	field_draw(0);
	while (1) {
		break;
	}
	return 0;
}
