/* lab6.c */

#include <stdio.h>

char make_upper(char);
char make_lower(char);
char swap_case(char);


char make_upper(char c) {
    if (c >= 97 && c <= 122){
        return c - 32;
    }
    else{
        return c;
    }
}


char make_lower(char c) {

    if (c >= 65 && c <= 90){
        return c + 32;
    }
    else{
        return c;}
}

char swap_case(char c) {
    if (c >= 97 && c <= 122){
        return c - 32;
    }
    else{
        return c + 32;
    }
}

int main(void) {
  char c;
  char cl;
  char cu;
  char cs;

  int  count;

  fprintf(stdout, "\n\nEnter a letter: ");
  count = fscanf(stdin, "%c", &c);
  cu = make_upper(c);
  cl = make_lower(c);
  cs = swap_case(c);
  fprintf(stdout, "%c - %c %c %c \n", c, cu, cl, cs);
}