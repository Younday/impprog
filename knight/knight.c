/*
 * knight.c
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

int numRoute(int xb, int yb, int xe, int ye, int n) {
	int dx = xe - xb;
	int dy = ye - yb;
	int count = 0;
	
	if(n == 0) {
		return count;
	}
	else {
		if(numRoute(xb = xe, yb = ye, xe + dx, ye + dy, n - 1)) {
			return count++;
		}
	}
	
}

int main(int argc, char **argv)
{
	int xb, yb, xe, ye, n, count = 0;
	
	printf("Start coordinate: ");
	scanf("%d %d", &xb, &yb);
	printf("End coordinate: ");
	scanf("%d %d", &xe, &ye);
	printf("Length: ");
	scanf("%d", &n);
	
	numRoute(xb, yb, xe, ye, n);
	
	printf("Number of routes: %d\n", count);
	
	return 0;
}

