#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15

int main(void)
{
  int square[MAX_SIZE][MAX_SIZE];
  int i, j, row, column;
  int count;
  int size;

  printf("Enter the size of the square:");
  scanf("%d", &size);

  if (size < 1 || (size > MAX_SIZE + 1)) {
    fprintf(stderr, "Error! Size is out od range\n");
    exit(EXIT_FAILURE);
  }
  if (!(size %2)) {
    fprintf(stderr, "Error! Size is even\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < size; i++)
    for(j = 0; j < size; j++)
      square[i][j] = 0;
  square[0][(size - 1)/2] = 1;

  i = 0;
  j = (size - 1)/2;
  for(count = 2; count <= size * size; count++) {
    row = (i - 1 < 0) ? (size - 1) : (i - 1);
    column = (j - 1 < 0) ? (size - 1) : (j - 1);
    if (square[row][column])
      i = (i + 1) % size;
    else {
      i = row;
      j = (j - 1 < 0) ? (size - 1) : --j;
    }
    square[i][j] = count;
  }

  printf("Magic Squre of size %d : \n\n", size);
  for (i = 0; i < size; i++) {
    for(j = 0; j < size; j++)
      printf("%5d", square[i][j]);
    printf("\n");
  }
  printf("\n\n");
}
