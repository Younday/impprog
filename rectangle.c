/* file : rectangle.c
 * author : Younes Moustaghfir
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * The function drawLine prints a sequence of
 * asterisks of the specified width.
 */
void drawLine(int width) {
  for(int i = 0; i < width; i++) {
	  printf("*");
  }
printf("\n");
}

/*
 * The function drawSides prints the vertical sides of
 * a rectangle with the specified dimensions.
 */
void drawSides(int width, int height) {
  for(int i = 0; i < height - 2; i++) {
	  for(int j = 0; j < width; j++) {
		  if(j == 0 || j == width-1) {
			  printf("*");
		  }
		  else {
			  printf(" ");
		  }
		}
	printf("\n");
	}
}

/*
 * The function drawRectangle prints a rectangle
 * with the specified dimensions.
 */
void drawRectangle(int width, int height) {
	  drawLine(width);
	  drawSides(width, height);
	  drawLine(width);
}

int main(int argc, char*argv[]) {
  int width, height;
  printf("Width of the rectangle: ");
  scanf("%d", &width);
  printf("Height of the rectangle: ");
  scanf("%d", &height);
  if (height < 2 || width < 2) {
    printf("Height and width must be at least 2.\n");
  } else {
    drawRectangle(width, height);
  }
  return 0;
}
