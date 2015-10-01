#include <stdio.h>
#include <stdlib.h>
#define END -324
int *dynamicIntArray(int size) {
	int *ptr = malloc(size*sizeof(int));
	if(ptr == NULL) {
		printf("Error: memory allocation failed (out of memory?).\n");
		exit(-1);
	}
	return ptr;
}
int * readGrades() {
  int *grades;
  int number;
  scanf("%d", &number);
  grades = dynamicIntArray(number+1);
  for(int i=0;i<number;i++) {
	  scanf("%d", (grades+i));
  }
  grades[number] = END; //to denote the end of the array
  return grades;
}
	
void computeFrequencies(int grades[], int freq[10]) {
  for(int i=0; i<10; i++) {
	  freq[i]=0;
  }
  for(int i=0;grades[i]!=END;i++){
	  freq[grades[i]-1]++;
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
	

void printHistogram(int freq[10]) {
  for(int i = arrayMax(10,freq); i>0; i--) {
	  for(int j = 0; j<10; j++) {
		  if(freq[j] >= i) {
			  printf("*");
		  }
		  else {
			  printf(".");
		  }
		  printf(" ");
	  }
	  printf("\n");
  }
  printf("1 2 3 4 5 6 7 8 9 10\n");
}

int main(int argc, char *argv[]) {
  int *grades;
  int frequencies[10];

  grades = readGrades();
  computeFrequencies(grades,frequencies);
  printHistogram(frequencies);

  return 0;
}
