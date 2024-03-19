#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#inlcude "history.h"

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

int non_space_char(char c){
if ( c != ' '|| != '\t' || c != '\0'){
  return 1;
 }
 else{
   return 0;
 }
}


/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */

char *token_start(char *str){
  int i = 0;
  while (*(str + i){
      if(non_space_char(*(str + i))){
	return str + i;
      }
      i++;
    }
    return str + i;
  }
}

/* Returns a pointer terminator char following *token */

char *token_terminator(char *token){
  int i = 0;
  while(*(str + i)){
    if( space_char(*(str+i))){
      return str + 1;
    }
    i++
  }
  return str + 1:
}


/* Counts the number of tokens in the string argument. */

int count_tokens(char *str){
  char *temp =  str;
  int count = 0;
  int i= 0;
  temp  token_start(temp);
  while (*temp){
    if(non_space_char(*temp)){
      count++;
    }
    temp token_terminator(temp);
    temp token_start(temp);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){
  char *copyStr = malloc(( len + 10 * sizeof(char);
        int i;
       for (i = 0; i < len; i++){
      copyStr[i] = intStr[i];
     }
    copyStr[i] = '\0';
    return copyStr;
  }
 }
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.



   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str){
  int size = count_token(str);
  char **tokens = malloc ((size + 1) * sizeof(char *));
  int i;
  int length;
  char *p = str;
  for (i = 0; i < size; i++){
    p = token_start(p);
    length = token_length(p);
    tokens[i] = copy_str(p, length);
    p = token_terminator(p);
  }
  tokens[i] = '\0';
  return tokens;
}

/* Prints all tokens. */

void print_tokens(char **tokens){
  int i = 0;
  while (tokens[i]){
    printf("Token[%d] = %s\n", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++
  }
}

int word_length(char *str)

{

  char *tmpS = word_start(str);

  char *tmpE = word_terminator(tmpS);

  int i = 0;

  int length = 0;

  length = tmpE - tmpS;

  //     printf("the size was %d",length);

  return length;

}
