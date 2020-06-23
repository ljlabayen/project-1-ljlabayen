#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

/* Returns true (non-zero if c is a whitespace char: ' ' or '\t'. */
int space_char(char c) {
  if (c==' ' || c =='\t') {
    return true;
  } else {
    return false;
  }
}

/* Returns true (non-zero) if c is a non-whitespace char: not ' ' or '\t' */
int non_space_char(char c) {
  if (c != ' ' && c != '\t') {
    return true;
  } else {
    return false;
  }
}

char *word_start(char *str){
  while(!non_space_char(*str)) {
    str = str + 1;
  }
  return str;
  
}

char *word_terminator(char *word) {
  while (non_space_char((*word))) {
    word = word + 1;
  }
  return word;
}

int count_words(char* str) {
  int OUT = 0;
  int IN = 1;
  int state = OUT;
  int count = 0; //count words to return

  while(*str) {
    if (*str == ' ' || *str == '\n' || *str == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      count++;
    }
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char* helper = inStr;
  char* copyStr =  NULL;

  //allocate extra memory for '\0' at the end of the string
  copyStr = (char*) malloc(sizeof(char) * (len + 1));

  //add '\0' at the end of the string
  copyStr[len] = '\0';

  int index = 0;
  while(*helper != '\0') {
    copyStr[index++] = *helper++;
  }
  return copyStr;
}
