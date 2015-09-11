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
	int obought, gbought, mbought, op, gp, mp, total, totalp;
	
	printf("price of an orange:\n");
	scanf("%d", &op);
	printf("price of a grapefruit:\n");
	scanf("%d", &gp);
	printf("price of a melon:\n");
	scanf("%d", &mp);
	
	for(int i = 1; i <= 100; i++) {
		obought = i * op;
		for(int j = 1; j <= 100; j++) {
			gbought = j * gp;
			mbought = 100 - (obought+gbought);
			total = mbought/mp + gbought/gp + obought/op;
			totalp = mbought + gbought + obought;
			if(mbought > 0 && total == 100 && totalp <= 10000) {
				printf("%d, %d, %d\n", obought/op, gbought/gp, mbought/mp);
			}
		}
	}
		
	}

