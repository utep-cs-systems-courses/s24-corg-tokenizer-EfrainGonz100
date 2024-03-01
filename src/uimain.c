#include <stdio.h>



int main() {

  char stringInput[50];

  printf("Type a small sentence: \n");

  fgets(stringInput, sizeof(stringInput), stdin);

  printf("You typed:\n %s", stringInput);

  return 0;
}
