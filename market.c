/* File : market.c
 * Author: Younes Moustaghfir
 * Date : Thu September 10 2015
 * Version: 1.0
 * 
 * Description:
 * Asks for the prices of the fruit and then returns all the possibilities
 * of fruit you can buy.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int orange, grapefruit, melons, obought, gbought, mbougt, op, gp, mp, x, y, z;
	
	printf("price of an orange : \n");
	scanf("%d", &op);
	printf("price of a grapefruit : \n");
	scanf("%d", &gp);
	printf("price of a melon :\n");
	scanf("%d", &mp);
	
	x = (op/10000);
	y = (gp/10000);
	z = (mp/10000);
	
	printf("%d, %d, %d\n", x, y, z);
	
	for(int i = 0; i <= x; i++) {
		printf("%d", i);
	}
}
	
	
	
	
	
