/*
 * discs.c
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
#include <math.h>

void *safeMalloc(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("\nError: memory allocation failed....abort\n");
    exit(-1);
  }
  return ptr;
}

int **makeDiscs(int sz) {
  int row, **arr;
  arr = safeMalloc(sz*sizeof(int *));
  for (row=0; row<sz; row++) {
    arr[row] = safeMalloc(4*sizeof(int));
  }
  return arr;
}

int intersect(int disc1, int disc2, int **discs) {
	int sxD, syD, count = 0;
	int xD = discs[disc1][0] - discs[disc2][0];
	int yD = discs[disc1][1] - discs[disc2][1];
	sxD = xD * xD;
	syD = yD * yD;
	if(sxD + syD <= (discs[disc1][2]+discs[disc2][2])*(discs[disc1][2]+discs[disc2][2])) {
		count = 1;
	}
	return count;
}

int countIntersect(int sz, int **discs) {
	int count = 0;
	for(int i = 0; i < (sz-1); i++) {
		for(int j = i + 1; j < sz; j++) {
			if(intersect(i, j, discs)) {
				discs[i][3] = 1;
				discs[j][3] = 1;
			}
		}
	}
	for(int i = 0; i < sz; i++) {
		if(discs[i][3]) {
			count++;
		}
	}
	return count;
}



int main(int argc, char **argv)
{
	int count;
	int sz;
	int **discs;
	scanf("%d\n", &sz);
	discs = makeDiscs(sz);
	for(int i = 0; i < sz; i++) {
		scanf("%d %d %d\n", &discs[i][0], &discs[i][1], &discs[i][2]);
	}
	count = countIntersect(sz, discs);
	printf("number of discs: %d\n", sz);
	printf("number of non-overlapping discs: %d\n", sz-count);
	return 0;
}
