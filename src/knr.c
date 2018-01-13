#include "knr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 1.1 */
/* 1.2 */
void knr_hello_world() {
  printf("Hello world!\n");
}

/* 1.3 */
/* modified in 1.5 original at commit d097fb4*/
void knr_f_c_table() {
  printf("%10s\t%10s\n", "fahrenheit", "celsius");

  for(int f = 120; f >= 0; f -= 20) {
    printf("%10.0f\t%10.1f\n", (float) f, (5.0 / 9.0) * (f - 32));
  }
}

/* 1.4 */
void knr_c_f_table() {
  float c, f;
  int lower = -20;
  int upper = 100;
  int step = 20;

  c = lower;
  printf("%10s\t%10s\n", "celsius", "fahrenheit");
  while(c <= upper) {
    f = (9.0 / 5.0) * (c + 32.0);
    printf("%10.0f\t%10.1f\n", c, f);
    c += step;
  }
}

/* 1.6 */
/* 1.7 */
/* ./knr < knr.c -> char is not EOF */
/* ./knr < /dev/null -> char is EOF */
void knr_getchar_is() {
  int v = (getchar() != EOF);
  printf("getchar() != EOF: %i\n", v);
  printf("EOF value: %i\n", EOF);
}

/* 1.8 */
/* ./knr < knr.c -> some number */
void knr_count_blank() {
  int blanks = 0;
  int c;
  while((c = getchar()) != EOF) {
    if(c == '\n' || c == ' ' || c == '\t') blanks++;
  }

  printf("blanks in input: %i", blanks);
}


/* 1.9 */
void knr_compact_blank() {
  int cur;
  int prev = EOF; // never matches the beginning of a file.

  while((cur = getchar()) != EOF) {
    if(cur == ' ' || cur == '\n' || cur == '\t') {
      if(prev != cur) {
        printf("%c", cur);
        prev = cur;
      }
    } else {
      prev = -1;
      printf("%c", cur);
    }
  }
}


/* 1.10 */
void knr_visible_blank() {
  int c, echo;
  while((c = getchar()) != EOF) {
    switch(c) {
    case '\t':
      printf("\\t");
      break;
    case '\b':
      printf("\\b");
      break;
    default:
      printf("%c", c);
    }
  }
}

/* 1.11 */
/* Discovering bugs in the wordcount program is likely going to happen by
 *  palying with in input char set, like UTF-8 chars. Another error source could
 *  be multiple word seperators in a row of various types
 *
 * Testing could be done by either providing various input files and running
 * them through the program on make test or likely better by swithing the method
 * to accepting a stream of bytes and then testing directly with various inputs.
 */
void knr_reading_from_stream() {
  char s[] = "this is a string";

  int c;
  FILE *ss = fmemopen(s, strlen(s), "r");

  while((c = fgetc(ss)) != EOF) {
    printf("read: %c\n", c);
  }
}

/* 1.12 */
void knr_one_word_per_line() {
  int c;
  int in_word = 1;
  while((c = getchar()) != EOF) {
    if(isblank(c) && in_word) {
      in_word = 0;
      putchar('\n');
    } else if (!isblank(c) && c != '\n' && isalpha(c)) {
      in_word = 1;
      putchar(c);
    }
  }
}

/* 1.13 - Print histogram of words in the input */
