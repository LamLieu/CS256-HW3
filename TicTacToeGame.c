#include <stdio.h>

void displayBoard(char array[3][3]);
int checkWin(char array[3][3], char playerChar);
int checkRowWin(char array[3][3], char playerChar);
int checkColumnWin(char array[3][3], char playerChar);
int checkDiagonalWin(char array[3][3], char playerChar);


void displayBoard(char array[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int column; column < 3; column++) {
			printf("%c ", array[row][column]);
		}
		printf("\n");
	}
}

int checkWin(char array[3][3], char playerChar) {
	if (checkRowWin(array, playerChar) == 3) {
		return 1;
	}
	if (checkColumnWin(array, playerChar) == 3) {
		return 1;
	}
	if (checkDiagonalWin(array, playerChar) == 3) {
		return 1;
	}
	return 0;
}

int checkRowWin(char array[3][3], char playerChar) {
	int count = 0;
	for (int columnIndex = 0; columnIndex < 3; columnIndex++) {
		for (int rowIndex = 0; rowIndex < 3; rowIndex++) {
			if (array[rowIndex][columnIndex] == playerChar) {
               count++;
			}
		}
	}
	return count;
}

int checkColumnWin(char array[3][3], char playerChar) {
	int count = 0;
	for (int rowIndex = 0; rowIndex < 3; rowIndex++) {
		for (int columnIndex = 0; columnIndex < 3; columnIndex++) {
			if (array[rowIndex][columnIndex] == playerChar) {
				count++;
            }
		}
	}
	return count;
}

int checkDiagonalWin(char array[3][3], char playerChar) {
	int count = 0;
	for (int rowIndex = 0, columnIndex = 0; rowIndex < 3 || columnIndex < 3; rowIndex++, columnIndex++) {
		if (array[rowIndex][columnIndex] == playerChar) {
			count++;
		}
	}
	return count;
}

int main() {
	char array[3][3];
	int player = 1; // odd for player 1, even for player 2
	int win = 0; // 0 for no win, 1 for win
	int row, column;

	//Initializing board with asterisk
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			array[i][j] = '*';
		}
	}

	while (win == 0) {
		char playerChar = 'X';

		if (player % 2 == 1) {
			playerChar = 'O';
			while(row > 3 || row < 1) {
				printf("Player 2, please enter a row (1-3): ");
				scanf("%d", &row);
			}

			while(column > 3 || column < 1) {
				printf("Player 2, please enter a column (1-3): ");
				scanf("%d", &column);
			}
			array[row - 1][column - 1] = 'O';
		}
		else {
			playerChar = 'X';
			while(row > 3 || row < 1) {
				printf("Player 1, please enter a row (1-3): ");
				scanf("%d", &row);
			}

			while(column > 3 || column < 1) {
				printf("Player 1, please enter a column (1-3): ");
				scanf("%d", &column);
			}
			array[row - 1][column - 1] = 'X';
		}
		displayBoard(array);
		win = checkWin(array, playerChar);

		if (win == 1) {
			printf("Player %d has won!", (player % 2) + 1);
		}

		player++;
	}

	return 0;
}
