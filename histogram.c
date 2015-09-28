#include <stdio.h>
#include <stdlib.h>
int sz;
int freq[10];

int *readGrades() {
  scanf("%d\n", &sz);
  int *grades = malloc(sz*sizeof(int));
  
  for(int i = 0; i < sz; i++){
	   scanf("%d", &grades[i]);
   }
  return grades;
}
	
void computeFrequencies(int grades[]) {
  for(int i = 0; i < sz ; i++) {
	  freq[grades[i]]++;
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
  int max;
  max = arrayMax(10, freq);
  for(int j = max; j > 0; j--){
	   
	   for(int i = 0; i < 10; i++) {
		   
		  if(freq[i] < 0) {
			  
			  printf(". ");
		  }
		  else {
			  printf("* ");
		  }
	  }
	  printf("\n");
  }
  printf("1 2 3 4 5 6 7 8 9 10\n");
}

int main(int argc, char *argv[]) {
  int *grades;
  int frequencies[10];
  //memset(frequencies, 0, sizeof(int)*sz);

  grades = readGrades();
  computeFrequencies(grades);
  printHistogram(frequencies);

  return 0;
}
