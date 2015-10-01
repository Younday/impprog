#include <stdio.h>
#include <stdlib.h>

void *safeMalloc(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("\nError: memory allocation failed....abort\n");
    exit(-1);
  }
  return ptr;
}

int **makeDiscs(int number) {
  int row, **arr;
  arr = safeMalloc(number*sizeof(int *));
  for (row=0; row<number; row++) {
    arr[row] = safeMalloc(4*sizeof(int));
  }
  return arr;
}
int testIntersects(int number1, int number2, int **discs) {
	int xDif = discs[number1][0] - discs[number2][0];
	int yDif = discs[number1][1] - discs[number2][1];
	int intersects =0;
	if(xDif*xDif+yDif*yDif<=(discs[number1][2]+discs[number2][2])*(discs[number1][2]+discs[number2][2]))
	{
		intersects = 1;
	}
	return intersects;
}
int countIntersects(int number, int **discs) {
	int intersects =0;
	for(int i = 0; i<(number-1); i++) {
		for(int j=i+1; j<number; j++) {
			if(testIntersects(i,j,discs))
			{
				discs[i][3] = 1;
				discs[j][3] = 1;
			}
		}
	}
	for(int i = 0;i<number;i++) {
		if(discs[i][3]) {
			intersects++;
		}
	}
	return intersects;
}

int main(int argc, char *argv[]) {
	int number;
	int **discs;
	int intersects;
	scanf("%d", &number);
	discs = makeDiscs(number);
	for(int i=0;i<number;i++)
	{
		scanf("%d %d %d", &discs[i][0], &discs[i][1], &discs[i][2]);
	}
	intersects = countIntersects(number,discs);
	printf("number of discs: %d\n", number);
	printf("number of non-overlapping discs: %d\n", number-intersects);
	return 0;
}
