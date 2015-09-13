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
	
	printf("price of an orange: ");
	scanf("%d", &op);
	printf("price of a grapefruit: ");
	scanf("%d", &gp);
	printf("price of a melon: ");
	scanf("%d", &mp);
	
	for(int i = 0; i <= 100; i++) {
		obought = i * op;
		for(int j = 0; j <= 100; j++) {
			gbought = j * gp;
			for(int k = 0; k <= 100; k++) {
				mbought = k * mp;
				if(mbought/mp == 0 && mbought == 0) {
					total = (gbought/gp) + (obought/op);
					totalp = gbought + obought;
				}
				else if(obought/op == 0 && obought == 0){
					total = (gbought/gp) + (mbought/mp);
					totalp = obought + mbought;
				}
				else if(gbought/mp == 0 && gbought == 0){
					total = (mbought/mp) + (obought/op);
					totalp = mbought + obought;
				}
				else {
					total = (mbought/mp) + (gbought/gp) + (obought/op);
					totalp = mbought + gbought + obought;
				}
				
				if(totalp == 10000 && total == 100 && obought/op == 1) {
					printf("%d orange, %d grapefruits, %d melons\n", obought/op, gbought/gp, mbought/mp);
				}
				else if(totalp == 10000 && total == 100 && obought/op != 1) {
					printf("%d oranges, %d grapefruits, %d melons\n", obought/op, gbought/gp, mbought/mp);
					
				}
			}
		}
	}
		
}

