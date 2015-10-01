#include <stdio.h>
#include <stdlib.h>
int sz;
static int frequencies[10];

int *readGrades() {
  scanf("%d\n", &sz);
  int *grades = malloc(sz+1*sizeof(int));
  
  for(int i = 0; i < sz; i++){
	   scanf("%d", &grades[i]);
   }
  return grades;
}
	
void computeFrequencies(int grades[], int frequencies[]) {
  for(int i = 0; i < sz ; i++) {
	  frequencies[grades[i]-1]++;
  }
}

int arrayMax(int length, int arr[]) {
  int i, max = arr[0];
  for (i=1; i < length; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
	

void printHistogram(int frequencies[10]) {
  for(int j = arrayMax(10, frequencies); j > 0; j--){
	   
	   for(int i = 0; i < 10; i++) {
		   
		  if(frequencies[i] >= j) {
			  
			  printf("* ");
		  }
		  else {
			  printf(". ");
		  }
	  }
	  printf("\n");
  }
  printf("1 2 3 4 5 6 7 8 9 10\n");
}

int main(int argc, char *argv[]) {
  int *grades;
 
  grades = readGrades();
  computeFrequencies(grades, frequencies);
  printHistogram(frequencies);

  return 0;
}
