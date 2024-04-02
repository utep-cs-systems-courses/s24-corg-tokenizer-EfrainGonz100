#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c){
if ( c != '\t' || c != ' '|| c != '\0'){
  return 0;
 }
 else {
   return 1;
 }
}


/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c)
{
  if (space_char(c)){
  return 0;
  }
  else
    {
   return 1;
    }
}


/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */

char *token_start(char *str)
{
  while (!(non_space_char(*str)))
    {
      if (*str == '\0')
	{
	  return str;
	}
      str++;
    }
  return str;
}

/* Returns a pointer terminator char following *token */

char *token_terminator(char *token)
{
  if(space_char(*token))
  {
    return token;
  }
  else
    {
      while(non_space_char(*token))
	{
	  token++;
	}
      return token;
    }
}


/* Counts the number of tokens in the string argument. */

int count_tokens(char** tokens)
{
  int counter = 0;

  while (*tokens != NULL)
    {
      counter++;
      tokens++;
    }
  return counter;
}

int count_words(char *str)
{
  if ((str!=NULL) && (str[0] == '\0'))
    {
      return 0;
    }
  int count = 1;

  while(*str++)
    {
      if (*str == ' ')
	{
	  count++;
	}
    }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)
{
  char *copy = (char*)malloc((len+1)*sizeof(char));
  short counter = 0;

  for (int i = 0; i < len; i++)
    {
      copy[counter] = inStr[counter];
      counter++;
    }
  copy[counter] = '\0';
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.



   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char** tokenize(char* str)
{
  int count = count_words(str);
  char** tokens = (char**)malloc((count+1) * (sizeof(char*)));
  char* temp = str;
  
  for (int i = 0; i < count; i++)
    {
      temp = word_start(temp);
      tokens[i] = copy_str(temp, (word_terminator(temp) - word_start(temp)));
      temp = word_terminator(temp);
    }
  tokens[count] = '\0';
  return tokens;
}

/* Prints all tokens. */

void print_tokens(char** tokens)
{
  int end = count_tokens(tokens);
  int counter = 0;


  printf("Tokens: %d\n", end+1);
  while (counter < end)
    {
      if (counter == (end-1))
	{
	  printf("token[%d] = %s", counter, *tokens);
	  printf("token[%d] = 0\n", counter+1);
	  counter++;
	}
      else
	{
	  printf("token[%d] = %s\n",counter, *tokens);
	  counter++;
	  tokens++;
	}
    }
  printf("-------------\n");
}

/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != 0; i++)
    {
      free(tokens[i]);
    }
  free(tokens);
}

short token_length(char *str)

{
  char* temp = str;
  short size = 0;
  while (non_space_char(*temp))
    {
      temp++;
      size++;
    }
  return size;
}
