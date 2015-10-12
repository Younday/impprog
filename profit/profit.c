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

int countProfit(int cost[100], int profit[100], int pr) {
	//First base case: production resources is 0
	for(int i = 0; )
	
	if(pr == 0) {
		return 1;
	}
	
	if()

int main(int argc, char **argv)
{
	int size, pr, *profit, *cost;
	char word[21] = {0};
	profit = safeMalloc(100);
	cost = safeMalloc(100);
	
	printf("Number of products: ");
	scanf("%d", &size);
	for(int i = 0; i < size; i++) {
		printf("product: ");
		scanf("%s", &word);
		printf("resource cost for %s: ", word);
		scanf("%d", &cost[i]);
		printf("profit for %s: ", word);
		scanf("%d", &profit[i]);
	}
	printf("available production resources: ");
	scanf("%d", &pr);
	
	return 0;
}
