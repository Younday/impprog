/*
 * guess.c
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

char *readString() {
	char longString[21];
	char *string;
	scanf("%s", longString);
	string = malloc((1+strlen(longString))*sizeof(char));
	strcpy(string, longString);
	return string;
}

void guess() {
	int right = 100;
	int left = 0;
	int mid;
	char *string;
	char l[7] = "lower";
	char c[10] = "correct";
	
	while(strcmp(string, c) > 0) {
		mid = (left + right)/2;
		printf("%d\n", mid);
		string = readString();
		if(strcmp(string, l) == 0) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	free(string);
		
}	

int main(int argc, char **argv)
{
	guess();
	return 0;
}

