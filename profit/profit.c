/*
 * profit.c
 * 
 * Copyright 2015 Younes Moustaghfir(s2909758) && Sharif Hamed (s2562677)
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

char *readString() {
	char longString[21];
	char *string;
	scanf("%s", longString);
	string = malloc((1+strlen(longString))*sizeof(char));
	strcpy(string, longString);
	return string;
}

void *safeMalloc(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("\nError: memory allocation failed....abort\n");
    exit(-1);
  }
  return ptr;
}

int **makeArray(int sz) {
  int row, **arr;
  arr = safeMalloc(sz*sizeof(int *));
  for (row=0; row<sz; row++) {
    arr[row] = safeMalloc(2*sizeof(int));
  }
  return arr;
}

int countProfit(int **array, int pr, int products) {
	int firstCase, secondCase;
	//First base case: production resources is 0 or below 0 or we've run out of products
	if(products == 0 || pr <= 0) {
		return 0;
	}
	firstCase = countProfit(array, pr, products - 1); //This is to decrement over the different products
	if(pr >= array[products - 1][0]) { //If the avaialble production resources are bigger than the cost of the product, then we can iniate the recursive function
		secondCase = countProfit(array, (pr - array[products - 1][0]), (products - 1)) + array[products - 1][1]; 
		if(secondCase > firstCase) {
			return secondCase; 
		}
	}
	return firstCase;
}

int main(int argc, char **argv)
{
	int size, pr;
	int **array;
	char *word;
	
	printf("number of products: ");
	scanf("%d", &size);

	array = makeArray(size);
	for(int i = 0; i < size; i++) {
		printf("product: ");
		word = readString();
		printf("resource cost for %s: ", word);
		scanf("%d", &array[i][0]);
		printf("profit for %s: ", word);
		scanf("%d", &array[i][1]);
	}

	printf("available production resources: ");
	scanf("%d", &pr);
	int a = countProfit(array, pr, size);
	
	printf("Maximum profit: %d\n", a);
	
	return 0;
}
