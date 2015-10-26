/* NOTE: for this exercise you need two files: demo.c (this file)
 * and knows.o.
 * The file knows.o is a binary file! It is compiled on a 
 * 64 bit linux machine, so you need to use a 64 bit Linux system.
 * If you use a 32 bit Linux system, then you can use the file 
 * knows32.o, which is a 32 bit compiled version. It is NOT possible
 * to use Windows (XP/Vista/7/8/whatever) or any other NON-Linux
 * operating system (like Mac OSX) for this exercise!
 *
 * Compilation is as follows:
 *   gcc -Wall -ansi demo.c knows.o
 * If the compilation succeeds, this will produce an executable a.out. 
 * In the file knows.o the following function is implemented:
 *    int knows(int a, int b);
 * The function returns 1 (TRUE) if "a knows b", otherwise 
 * it returns 0 (FALSE).
 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

/*** DO NOT EDIT THE FOLLOWING TWO LINES !!!!!! ******/
int numberOfGuests; /* number of guests at the party (including the king) */
extern int knows(int a, int b); /* returns: TRUE if "a knows b", otherwise FALSE  */
/*****************************************************/

int king() {
  /* please implement this function */
  int left = 0;
  int right = numberOfGuests - 1;
  
  while(left < right) {
	  if(knows(left, right) == 1) {
		  left++;
	  }
	  else if(knows(left, right) == 0) {
		  right--;
	  }
  }
  return right;
}

void demo() {
  int i, j;
  printf("DEMO: The matrix knows(i,j):\n");
  for (i=0; i < numberOfGuests; i++) {
    for (j=0; j < numberOfGuests; j++) {
      printf("%d ", knows(i, j));
    }
    printf("\n");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  printf("Number of guests: ");
  scanf("%d", &numberOfGuests);

  //demo();

  printf("The king has number: %d\n", king());

  return 0;
}
