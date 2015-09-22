#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* type definition of student */
typedef struct student {
  int who;     /* 0=John, 1=Peter, 2=William */
  float paid;  /* amount that student paid   */
} student;

/* global variables */
student firstStudent, secondStudent, thirdStudent;

/************************************************************************
 * ABSTRACT DATA TYPE: the following functions form the ADT student.
 * Do not change the ADT part of this program !
 */

/* read the info of a student from the keyboard and return it. */
void readStudent(student *stud) {
  scanf("%d %f", &stud->who, &stud->paid);
}

/* print the name of a student. */
void printNameOfStudent(student stud) {
  printf("%s", (stud.who == 0 ? "John" : (stud.who == 1 ? "Peter" : "William")));
}

/* returns the amount that a student paid. */
float paidByStudent(student stud) {
  return stud.paid;
}

/* swaps two students */
void swapStudents(student *a, student *b) {
  student h = *a;
  *a = *b;
  *b = h;
}

/************************************************************************/


/* remainder of the program in which the ADT student is used. */

/*
 * Reads the entire input from the keyboard and stores 
 * it in the appropriate global variables.
 */
void readInput() {
  readStudent(&firstStudent);
  readStudent(&secondStudent);
  readStudent(&thirdStudent);
}


int main(int argc, char *argv[]) {
  readInput();

  float average =  (paidByStudent(firstStudent) + paidByStudent(secondStudent) + paidByStudent(thirdStudent)) / 3;
  
  if(paidByStudent(secondStudent) < average && paidByStudent(secondStudent) < paidByStudent(firstStudent) && paidByStudent(secondStudent) < paidByStudent(thirdStudent)) {
	  swapStudents(&firstStudent, &secondStudent);
  }
  else if(paidByStudent(thirdStudent) < average && paidByStudent(thirdStudent) < paidByStudent(firstStudent) && paidByStudent(thirdStudent) < paidByStudent(secondStudent)){
	  swapStudents(&firstStudent, &thirdStudent);
  }
  else if(paidByStudent(thirdStudent) < paidByStudent(secondStudent)) {
	  swapStudents(&secondStudent, &thirdStudent);
  }

  
  float remainderFirst = paidByStudent(firstStudent) - average;
  float remainderSecond = paidByStudent(secondStudent) - average;
  float remainderThird = paidByStudent(thirdStudent) - average;
  

  if(paidByStudent(firstStudent) > average) {
	  printNameOfStudent(firstStudent);
	  printf(" receives %3.2f\n", remainderFirst);
  }
  else if(paidByStudent(firstStudent) < average) {
	  printNameOfStudent(firstStudent);
	  printf(" pays %3.2f\n", average - paidByStudent(firstStudent));
  }
  
  if(paidByStudent(secondStudent) > average) {
	  printNameOfStudent(secondStudent);
	  printf(" receives %3.2f\n", remainderSecond);
  }
  else if(paidByStudent(secondStudent) < average) {
	  printNameOfStudent(secondStudent);
	  printf(" pays %3.2f\n", average - paidByStudent(secondStudent));
  }
  
  if(paidByStudent(thirdStudent) > average) {
	  printNameOfStudent(thirdStudent);
	  printf(" receives %3.2f\n", remainderThird);
  }
  else if(paidByStudent(thirdStudent) < average) {
	  printNameOfStudent(thirdStudent);
	  printf(" pays %3.2f\n", average - paidByStudent(thirdStudent));
  }
  return 0;
}
