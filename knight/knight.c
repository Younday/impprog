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
#include <math.h>


int numRoute(int xb, int yb, int xe, int ye, int n) {
	int count = 0;
	
	if(n == 0 && xb == xe && yb == ye) {
		return 1;
	}
	
	if(abs(xe - xb) + abs(ye - yb) > 3*n) {
		return 0;
	}
	
	if(n % 2 == 0 && (abs(xe - xb) + abs(ye - yb)) % 2 != 0) {
		return 0;
	}
	
	count += numRoute(xb + 2, yb + 1, xe, ye, n-1);
	count += numRoute(xb + 2, yb - 1, xe, ye, n-1);
	count += numRoute(xb + 1, yb + 2, xe, ye, n-1);
	count += numRoute(xb + 1, yb - 2, xe, ye, n-1);
	count += numRoute(xb - 2, yb + 1, xe, ye, n-1);
	count += numRoute(xb - 2, yb - 1, xe, ye, n-1);
	count += numRoute(xb - 1, yb + 2, xe, ye, n-1);
	count += numRoute(xb - 1, yb - 2, xe, ye, n-1);
	
	return count;
}

int main(int argc, char **argv)
{
	int xb, yb, xe, ye, n, count = 0;
	
	printf("Start coordinate: ");
	scanf("%d %d", &xb, &yb);
	printf("End coordinate: ");
	scanf("%d %d", &xe, &ye);
	printf("Length: \n");
	scanf("%d", &n);
	
	count = numRoute(xb, yb, xe, ye, n);
	
	printf("Number of routes: %d\n", count);
	
	return 0;
}

