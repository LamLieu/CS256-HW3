#include <stdio.h>

void displayBoard(char array[3][3]);
int checkRowWin(char array[3][3], char playerChar);
int checkColumnWin(char array[3][3], char playerChar);
int checkDiagonalWin(char array[3][3], char playerChar);
int checkTie(char array[3][3]);

void displayBoard(char array[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int column; column < 3; column++) {
			printf("%c ", array[row][column]);
			fflush(stdout);
		}
		printf("\n");
	}
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

int checkDiagonalWin(char array[3][3], char playerChar) {
	int count = 0;
	for (int rowIndex = 0, columnIndex = 0; rowIndex < 3 && columnIndex < 3; rowIndex++, columnIndex++) {
		if (array[rowIndex][columnIndex] == playerChar) {
			count++;
		}
	}

	return count;
}

int checkTie(char array[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (array[row][column] == '*') {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	char array[3][3];
	int player = 1; // odd for player 1, even for player 2
	int win = 0, tie = 0; // 1 = true, 0 = false

	//Initializing board with asterisk
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			array[i][j] = '*';
		}
	}

	while (win == 0 && tie == 0) {
		int row, column;
		char playerChar = 'X';

		if (player % 2 == 1) { //Player 1
			playerChar = 'X';

			do {
				while(row > 3 || row < 1) {
					printf("Player 1, please enter a row (1-3): ");
					fflush(stdout);
					scanf("%d", &row);
				}
				while(column > 3 || column < 1) {
					printf("Player 1, please enter a column (1-3): ");
					fflush(stdout);
					scanf("%d", &column);
				}

				if (array[row - 1][column - 1] == '*') {
					array[row - 1][column - 1] = 'X';
				}
			} while (array[row - 1][column - 1] != '*');
		}
		else { //Player 2
			playerChar = 'O';

			do {
				while(row > 3 || row < 1) {
					printf("Player 2, please enter a row (1-3): ");
					fflush(stdout);
					scanf("%d", &row);
				}
				while(column > 3 || column < 1) {
					printf("Player 2, please enter a column (1-3): ");
					fflush(stdout);
					scanf("%d", &column);
				}

				if (array[row - 1][column - 1] == '*') {
					array[row - 1][column - 1] = 'O';
				}
			} while (array[row - 1][column - 1] != '*');
		}

		printf("fdsafds");
		displayBoard(array);

		if (checkRowWin(array, playerChar) == 3) {
			win = 1;
		}
		if (checkColumnWin(array, playerChar) == 3) {
			win = 1;
		}
		if (checkDiagonalWin(array, playerChar) == 3) {
			win = 1;
		}

		tie = checkTie(array);

		if (win == 1) {
			printf("Player %d has won the game!\n", (player % 2) + 1);
		}

		if (tie == 1) {
			printf("It's a tie!\n");
		}
		player++;
	}

	return 0;
}
