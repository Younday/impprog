/*
 * profit.c
 * 
 * Copyright 2015 Younes <younes@younes-PNB-series>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *safeMalloc(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("\nError: memory allocation failed....abort\n");
    exit(-1);
  }
  return ptr;
}

int **makeIntArray2D(int size) {
  int row, **arr;
  arr = safeMalloc(size*sizeof(int *));
  for (row=0; row<size; row++) {
    arr[row] = safeMalloc(3*sizeof(int));
  }
  return arr;
}

int main(int argc, char **argv)
{
	int size, **arr;
	
	printf("Number of products: ");
	scanf("%d", &size);
	arr = makeIntArray2D(size);
	char word[size][21];
	
	for(int i = 0; i < size; i++) {
		printf("product: ");
		scanf("%s", &word);
		arr[i][0] = word[i][21];
		printf("resource cost for %s: ", arr[i][0]);
		scanf("%d", &arr[i][1]);
		printf("profit for %s: ", arr[i][0]);
		scanf("%d", &arr[i][2]);
	}
	
	return 0;
}

