/*
 * file : pythagoras.c
 * author: Younes Moustaghfir
 * date: Thursday August 9 2015
 * version: 1.0
 * 
 * Description:
 * This program takes a positive integer n and decides whether it is
 * a prime number
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv[])
{
	int n, count = 0;
	
	printf("Type a non-negative integer:\n");
	scanf("%d", &n);
	
	for(int i = 2; i <= n / 2; i++){
		if(n % i == 0){
			count++;
			break;
		}
	}

	if(count == 0 && n != 1 && n!= 0){
		printf("%d is a prime number.\n", n);
	}
	else {
		printf("%d is not a prime number.\n", n);
	}
}
