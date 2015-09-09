/*
 * file : pythagoras.c
 * author: Younes Moustaghfir
 * date: Thursday August 9 2015
 * version: 1.0
 * 
 * Description:
 * Given a non-negative numbers, this program calculates the
 * factorial of that number.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv[])
{
	long n, fact = 1;
	
	printf("Type a non-negative integer :\n");
	scanf("%ld", &n);
	
	for(int i = 1; i <= n; i++) {
		fact = fact * i;
	}
	
	printf("The factorial of %ld is %ld.\n", fact, n);
}
