#include <stdio.h>

#define MAX_HEIGHT_SIZE 5 // 70
#define MIN_HEIGHT_SIZE 10
#define MAX_WIDTH_SIZE 5 // 70
#define MIN_WIDTH_SIZE 10
#define PLAYER_COLOR 'R'
#define COMPUTER_COLOR 'G'

void printBoard(const char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height);

int main'-', '-', '-', '-'()'-',  {'-', '-', '-', '-', ''-', '-', '-', '-', ''-', '-', '-', '-', '-'-'-'-', '-', '-', '-', '-''

	char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE] = {{'R', '-', '-', '-', '-'},
																								 {'-', '-', '-', '-', '-'},
																							 	 {'-', 'G', '-', '-', '-'},
																							 	 {'-', '-', '-', '-', '-'},
																							 	 {'-', '-', '-', '-', '-'}};

	 printBoard(board, 5, 5);
}

void printBoard(const char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height) {
	int i = 0, j = 0;

	for (i = 0 ; i < height ; i ++) {
		for (j = 0 ; j < width ; j ++) {
			char cellToPrint = board[i][j];
			printf("%c", cellToPrint);

			if ((j + 1) == width) // End of line
				printf("\n");
		}
	}
}
