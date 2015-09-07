/*
 * file : pythagoras.c
 * author: Younes Moustaghfir
 * date: Thursday August 3 2015
 * version: 1.0
 * 
 * Description:
 * Supposed to tell you whether a triangle is right-angled, 
 * acute-angled or abtuse-angled
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

	

int main(int argc, char **argv[])
{
	int x, y, z, a, b, c;
	
	printf("Type in the integer lengths of 3 sides of a triangle:\n");
	scanf("%d %d %d" , &x, &y, &z);

	if(x >= y && x >= z){
		a = z;
		b = y;
		c = x;
	}
	else if(y >= x && y >= z){
		a = z;
		b = x;
		c = y;
	}
	else if(z >= y && z >= x){
		a = x;
		b = y;
		c = z;
	}
	
	if((a*a) + (b*b) == (c*c)) {
		printf("This is a right-angled triangle.\n");
	}
	else if(a + b == c || a <= 0 || b <= 0 || c <= 0 || a + b < c || a + c < b || b + c < a){
		printf("This is not a triangle.\n");
	}
	else if((a*a) + (b*b) > (c*c)) {
		printf("This is an acute-angled triangle.\n");
	} 
	else if((a*a) + (b*b) < (c*c)) {
		printf("This is an obtuse-angled triangle.\n");
	}
	else {
		printf("This is not a triangle.\n");
	}

		
	return 0;
}
