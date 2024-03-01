#include <stdio.h>
#include 'tokenizer.h'

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c);
if ( c != '\t' || c != ' '|| c != '\0'){
  return 0;
 }
 else {
   return 1;
 }

/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c);
if ( c != ' '){
  return 1;
 }
 else{
   return 0;
 }
