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
	int orange, grapefruit, melons, obought, gbought, mbought, op, gp, mp, totalo = 100;
	
	printf("price of an orange:\n");
	scanf("%d", &op);
	printf("price of a grapefruit:\n");
	scanf("%d", &gp);
	printf("price of a melon:\n");
	scanf("%d", &mp);
	
	for(int i = 0; i <= totalo; i++) {
		for(int j = 0; i <= totalo; i++) {
			obought = i * op;
			gbought = i * gp;
			mbought = i * mp;
			if(obought <= 10000 && gbought <= 10000-obought && mbought <= 10000-(obought+gbought)) {
				printf("%d, %d, %d\n", obought, gbought, mbought);
		}
	}
}
}
