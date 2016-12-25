#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_HEIGHT_SIZE 70
#define MIN_HEIGHT_SIZE 10
#define MAX_WIDTH_SIZE 70
#define MIN_WIDTH_SIZE 10
#define PLAYER_COLOR 'R'
#define COMPUTER_COLOR 'G'

void printBoard(const char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE], int width, int height);
void getDimentions(int* width, int* height);

int readNumberInRageFromUser(int min, int max, char *message);
int isValidInputInRage(int min, int max, int input);


int main() {

	char board[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE] = {{'R', '-', '-', '-', '-'},
																								 {'-', '-', '-', '-', '-'},
																							 	 {'-', 'G', '-', '-', '-'},
																							 	 {'-', '-', '-', '-', '-'},
																							 	 {'-', '-', 'R', '-', '-'}};

	 printBoard(board, 5, 5);

   int *a, *b;
   getDimentions(a, b);
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

void getDimentions(int* width, int* height) {
  int inWidth, inHeigth;

  inWidth = readNumberInRageFromUser(MIN_WIDTH_SIZE, MAX_WIDTH_SIZE, "Enter width (10-70):");
  inHeigth = readNumberInRageFromUser(MIN_WIDTH_SIZE, MAX_WIDTH_SIZE, "Enter height (10-70):");
}

int readNumberInRageFromUser(int min, int max, char *message) {
  int userInput;

  do {
    printf("%s\n", message);
    scanf("%d", &userInput);

    printf("userInput: %d\n", userInput);
  } while (isValidInputInRage(min, max, userInput) == FALSE);

  return userInput;
}

int isValidInputInRage(int min, int max, int input) {
  if (input < min || max < input)
    return FALSE;
  else
    return TRUE;
}
