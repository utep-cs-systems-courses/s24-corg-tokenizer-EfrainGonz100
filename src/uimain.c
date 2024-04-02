#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char hello[] = "Hello World";
  char *str = hello;
  int id_tracker = 1;
  
  char array [50];

  while (1)
    {
      char* temp = str;
      List *strings;
      strings = init_history();

      printf("Please type a small sentence:\n ");
      printf("$ --> ");
      fgets(array, 49, stdin);
      char *str = &array[0];

      if (*str == 'q') // quit
	{
	  exit(0);
	}

      char** tokenizer = tokenize(str);
      print_tokens(tokenizer);

      List *list = init_history();
      
      add_history(list, str);
      print_history(list);


      free_tokens(tokenizer);
      free_history(list);
      id_tracker++;

    }
}
