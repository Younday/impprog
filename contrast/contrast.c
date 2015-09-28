#include <stdio.h>
#include <stdlib.h>

/* safe replacement for malloc. */
void *safeMalloc(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("\nError: memory allocation failed....abort\n");
    exit(-1);
  }
  return ptr;
}

/* make a 2D dynamic array */
int **makeIntArray2D(int width, int height) {
  int row, **arr;
  arr = safeMalloc(height*sizeof(int *));
  for (row=0; row<height; row++) {
    arr[row] = safeMalloc(width*sizeof(int));
  }
  return arr;
}

/* DO NOT EDIT THIS FUNCTION! */
/* read PGM file and return image. */
int **readPGM(int *width, int *height) {
  int pgmtype, dummy;
  int row, column;
  int **pixel;

  scanf("P%d", &pgmtype);
  if ((pgmtype != 2) && (pgmtype != 5)) {
    printf("Error: this program can only read PGM images ");
    printf("of the types P2 and P5.\n");
    exit(-1);
  }
  while (getchar() != '\n');
  dummy = getchar();
  while (dummy == '#') {
    /* skip comment line(s) of PGM file */
    while (getchar() != '\n');
    dummy = getchar();
  }
  ungetc(dummy, stdin);  /* push character back to input */
  scanf("%d %d\n", width, height);
  scanf("%d\n", &dummy);

  pixel = makeIntArray2D(*width, *height);

  if (pgmtype == 2) {
    for (row = 0; row < *height; row++) {
      for (column = 0; column < *width; column++) {
        scanf("%d", &pixel[row][column]);
      }
    }
  } else {
    for (row = 0; row < *height; row++) {
      for (column = 0; column < *width; column++) {
        pixel[row][column] = getchar();
      }
    }
  }
  return pixel;
}

/* DO NOT EDIT THIS FUNCTION! */
/* save image as PGM file. */
void savePGM(int width, int height, int **pixel) {
  int row, column, cnt;
  printf("P2\n");
  printf("%d %d\n255\n", width, height);
  cnt = 0;
  for (row=0; row < height; row++) {
    for (column=0; column < width; column++) {
      printf("%3d ", pixel[row][column]);
      cnt = (cnt + 1)%17;
      if (cnt == 0) {
        printf("\n");
      }
    }
  }
  printf("\n");
}

int minimumValue(int width, int height, int **pixel) {
	int row, column, min = 255;
	for(row = 0; row < height; row++) {
		for(column = 0; column <  width; column++) {
			if(pixel[row][column] < min) {
				min = pixel[row][column];
			}
		}
	}
	return min;
}

int maximumValue(int width, int height, int **pixel) {
	int row, column, max = 0;
	for(row = 0; row < height; row++) {
		for(column = 0; column <  width; column++) {
			if(pixel[row][column] > max) {
				max = pixel[row][column];
			}
		}
	}
	return max;
}

void enhanceContrast(int width, int height, int **pixel) {
	int max, min, row, column;
	minimumValue(width, height, pixel);
    maximumValue(width, height, pixel);
	if(max - min > 255) {
		for(row = 0; row < height; row++) {
			for(column = 0; column < width; column++) {
				pixel[row][column] = ((pixel[row][column] - min) * 255) / (max - min);
			}
		}
	}
}
		

int main(int argc, char *argv[]) {
  int width, height;
  int **pixel;
  int min, max;

  pixel = readPGM(&width, &height);
  savePGM(width, height, pixel);
  
  enchanceContrast(width, height, pixel);
  return 0;
}
