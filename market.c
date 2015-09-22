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
	
	for(obought = 0; obought <= 100; obought++) {
		for(gbought = 0; gbought <= 100; gbought++) {
			mbought = 100 - obought - gbought;
			total = obought + gbought + mbought;
			totalp = (gbought*gp) + (obought*op) + (mbought*mp);
			if(totalp == 10000 && total == 100 && obought != 1 && gbought != 1 && mbought != 1 && !(mbought < 0)) {
				printf("%d oranges, ", obought);
				printf("%d grapefruits, ", gbought);
				printf("%d melons\n", mbought);
			}
			else if(totalp == 10000 && total == 100 && obought == 1 && mbought != 1 && gbought != 1 && !(mbought < 0)) {
				printf("%d orange, %d grapefruits, %d melons\n", obought, gbought, mbought); 
			}
			else if(totalp == 10000 && total == 100 && mbought == 1 && gbought != 1 && obought != 1) {
				printf("%d oranges, %d grapefruits, %d melon\n", obought, gbought, mbought);
			}
			else if(totalp == 10000 && total == 100 && gbought == 1 && mbought != 1 && obought != 1 && !(mbought < 0)) {
				printf("%d oranges, %d grapefruit, %d melons\n", obought, gbought, mbought);
			}
			else if(totalp == 10000 && total == 100 && gbought == 1 && obought == 1 && mbought != 1 && !(mbought <0)) {
				printf("%d orange, %d grapefruit, %d melons\n", obought, gbought, mbought);
			}
			else if(totalp == 10000 && total == 100 && gbought == 1 && mbought == 1 && obought != 1) {
				printf("%d oranges, %d grapefruit, %d melon\n", obought, gbought, mbought);
			}
			else if(totalp == 10000 && total == 100 && obought == 1 && mbought == 1 && gbought != 1) {
				printf("%d orange, %d grapefruits, %d melon\n", obought, gbought, mbought);
			}
			else if(totalp == 10000 && total == 100 && obought == 1 && gbought == 1 && mbought == 1) {
				printf("%d orange, %d grapefruit, %d melon\n", obought, gbought, mbought);
			}
		}
	}
}
