#include <stdio.h>
#include <stdlib.h>

int **creategame(FILE *cp);
void freegame(int **game);
void printgame(int **game);
int check_row(int **game, int row, int column, int num);
int check_column(int **game,int row, int column, int num);
int check_square(int **game, int row, int column, int num);
int check_num(int **game, int row, int column, int num);
void find_next(int **game, int *x, int *y);
int check_all(int **game);
int backtracking(int **game, int x, int y);

int main() {
	FILE *pfile = fopen("Sudoku.txt","r");
	int **sudoku = creategame(pfile);
	backtracking(sudoku, 0, 0);
	printgame(sudoku);
	freegame(sudoku);
	return 0;
}

int **creategame(FILE *cp) {
	int **game;
	if ( (game = (int**) malloc(9*sizeof(int*))) != NULL) {
		for (int i = 0; i < 9; i++) {
			if ( (game[i] = (int*) malloc(9*sizeof(int))) == NULL) {
				while (i) {
					i--;
					free(game[i]);
				}
				free(game);
				return NULL;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fscanf(cp, "%d", &game[i][j]);
		}
		fseek(cp, 2, SEEK_CUR);
	}
	return game;
}

void freegame(int **game) {
	for (int i = 0; i < 9; i++) {
		free(game[i]);
	}
}

void printgame(int **game) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", game[i][j]);
		}
		printf("\n");
	}
}

int check_row(int **game, int row, int column, int num) {
	for (int i = 0; i < 9; ++i) {
		if (game[row][i] == num) {
			if (i != column) {
				return 0;
			}
		}
	}
	return 1;
}

int check_column(int **game,int row, int column, int num) {
	for (int i = 0; i < 9; ++i) {
		if (game[i][column] == num) {
			if (i != row) {
				return 0;
			}
		}
	}
	return 1;
}

int check_square(int **game, int row, int column, int num) {
	int i, j, p, q;
	if (row <= 2) {
		i = 0; j = 2;
	}
	else if (row <= 5) {
		i = 3; j = 5;
	}
	else {
		i = 6; j = 8;
	}
	if (column <= 2) {
		p = 0; q = 2;
	}
	else if (column <= 5) {
		p = 3; q = 5;
	}
	else {
		p = 6; q = 8;
	}
	for (int b = i; b <= j; b++) {
		for (int n = p; n <= q; n++) {
			if (game[b][n] == num) {
				if (b != row || n != column) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int check_num(int **game, int row, int column, int num) {
	int flag1, flag2, flag3;
	flag1 = check_row(game, row, column, num);
	flag2 = check_column(game, row, column, num);
	flag3 = check_square(game, row, column, num);
	if (flag1 == 1 && flag2 == 1 && flag3 == 1) {
		return 1;
	}
	return 0;
}

void find_next(int **game, int *x, int *y) {
	while (game[*x][*y] != 0) {
		if ((*y) != 8) { (*y)++; }
		else { (*x)++; (*y) = 0; }
	}
}

int check_all(int **game) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (game[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int backtracking(int **game, int x, int y) {
	if (check_all(game)) {
		return 1;
	}
	for (int test = 1; test <= 9; test++) {
		find_next(game, &x, &y);
		if (check_num(game, x, y, test)) {
			game[x][y] = test;
			if (backtracking(game, x, y)) {
				return 1;
			}
			game[x][y] = 0;
		}
	}
	return 0;
}
