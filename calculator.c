#include <stdio.h>
#include <stdlib.h>

double R0 = 0, R1 = 0, R2 = 0, R3 = 0;

void storeValue(int registerNumber, double value) {
  if(registerNumber == 0){
	  R0 = value;
  }
  else if(registerNumber == 1){
	  R1 = value;
  }
  else if(registerNumber == 2){
	  R2 = value;
  }
  else if(registerNumber == 3){
	  R3 = value;
	}
}

double readValue(int registerNumber) {
  if(registerNumber == 0){
	  return R0;
  }
  else if(registerNumber == 1){
	  return R1;
  }
  else if(registerNumber == 2){
	  return R2;
  }
  else if(registerNumber == 3){
	  return R3;
	}
}

void showRegisters() {
  printf("R0=%lf R1=%lf R2=%lf R3=%lf\n", R0, R1, R2, R3);
}

int inputFromRange(int lwb, int upb) {
  /* read from the keyboard a value from the
   * interval [lwb,upb] and return it.
   */
  int value;
  do {
    scanf("%d", &value);
    if ((value < lwb) || (value > upb)) {
      printf("Error: input must be from the range [%d,%d].\n", lwb, upb);
      printf("       Please, try again.\n");
    }
  } while ((value < lwb) || (value > upb));
  return value;
}

int inputRegister(char *message) {
  printf("%s", message);
  return inputFromRange(0, 3);
}

double inputValue(char *message) {
  double value;
  printf("%s", message);
  scanf("%lf", &value);
  return value;
}

void assignment() {
  int x;
  double y;
  printf(" Rx=y: \n");
  x = inputRegister(" x=");
  y = inputValue(" y=");
  storeValue(x, y);
}

void addRegisters() {
  int x, y, z;
  printf(" Rx=Ry+Rz: \n");
  x = inputRegister(" x=");
  y = inputRegister(" y=");
  z = inputRegister(" z=");
  /* write here your own code */
  storeValue(x,(readValue(y) + readValue(z)));
}

void subtractRegisters() {
  int x, y, z;
  printf(" Rx=Ry-Rz: \n");
  x = inputRegister(" x=");
  y = inputRegister(" y=");
  z = inputRegister(" z=");
  /* write here your own code */
}

void multiplyRegisters() {
  int x, y, z;
  printf(" Rx=Ry*Rz: \n");
  x = inputRegister(" x=");
  y = inputRegister(" y=");
  z = inputRegister(" z=");
  /* write here your own code */
}

void divideRegisters() {
  int x, y, z;
  printf(" Rx=Ry/Rz: \n");
  x = inputRegister(" x=");
  y = inputRegister(" y=");
  z = inputRegister(" z=");
  /* write here your own code */
}

int inputCommand() {
  printf("command: stop(0) =(1) +(2) -(3) *(4) /(5): ");
  return inputFromRange(0, 5);
}

int main(int argc, char *argv[]) {
  int keepRunning = 1;
  int command;

  while (keepRunning == 1) {
    showRegisters();
    command = inputCommand();
    switch (command) {
    case 0:  keepRunning--;
      break;
    case 1: assignment();
      break;
    case 2: addRegisters();
	  break;
	case 3: subtractRegisters();
	  break;
    }
  }

  return 0;
}
