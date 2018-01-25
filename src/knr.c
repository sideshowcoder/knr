#include "knr.h"

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
#define MAX_LEN 32

void knr_word_length_histogram() {
  int counts[MAX_LEN] = { 0 };
  int len = 0;
  int input_max_len = 0;
  int c;

  // aggregate word lengths
  while((c = getchar()) != EOF) {
    if((isblank(c) || c == '\n' || ispunct(c)) && len > 0) {
       // only print histogram to for word lengths there are examples for in the input
      if(len > input_max_len) input_max_len = len;

      counts[len - 1]++;
      len = 0;
    } else if (!isblank(c) && c != '\n' && isalpha(c)) {
      if(len < (MAX_LEN - 1)) { // only increment if shorter than max
        len++;
      }
    }
  }

  // print histogram vertical
  /*
   * for(int i = 0; i < input_max_len; i++) {
   *   printf(" %*d: %*s\n", 2, i + 1, counts[i] + 1, "=");
   * }
   */

  // print histogram horizontal
  for(int i = input_max_len; i > -1; i--) {
    for(int j = 0; j < input_max_len; j++) {
      if(counts[j] > i) {
        printf(" x ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }

  for(int i = 0; i < input_max_len; i++) {
    printf("%*i ", 2, i+1);
  }
}

/* 1.14 print histogram of the frequency of characters in words */
#define ALPHABET_SIZE 27

void knr_char_freq() {
  int c;
  int freqs[ALPHABET_SIZE] = { 0 };

  while((c = getchar()) != EOF) {
    int _c = tolower(c);
    if('a' <= _c && _c <= 'z') {
      freqs[_c - 'a']++;
    }
  }

  int max_freq = 0;
  for(int i = 0; i <= ALPHABET_SIZE; i++) {
    if(max_freq < freqs[i]) max_freq = freqs[i];
  }

  for(int i = max_freq; i > -1; i--) {
    for(int j = 0; j < ALPHABET_SIZE; j++) {
      if(freqs[j] > i) {
        printf(" x ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }

  for(int i = 'a'; i <= 'z'; i++) {
    printf("%*c ", 2, i);
  }
}


/* 1.15 convert F to C */
float knr_f_to_c(float f) {
  return (5.0 / 9.0) * (f - 32);
}

/* 1.15 convert C to F */
float knr_c_to_f(float c) {
  return ((9.0 / 5.0) * c) + 32.0;
}

/*
 * 1.16 print the length of the longest line in the input and a as much of the
 * text as possible (for argument and sanity sake lets use 80 as the max
 * printable line length.
 */
int knr_readline(char dest[], int maxlen) {
  int len, c;
  int copied = 0;

  for(len = 0; (c = getchar()) != EOF && c != '\n'; len++) {
    if(len < (maxlen - 1)) {
      dest[len] = c;
      copied++;
    }
  }
  // copy the \n if possible
  if(c == '\n' && len < (maxlen - 1)) {
    dest[copied++] = c;
    len++;
  }

  dest[copied] = '\0';
  return len;
}


void knr_print_longest_line(int maxlen) {
  char line[maxlen], maxline[maxlen];
  int max = 0;
  int clen = 0;

  while((clen = knr_readline(line, maxlen)) > 0) {
    if(clen > max) {
      max = clen;
      strncpy(maxline, line, maxlen);
    }
  }

  if(max > 0) {
    printf("length: %i\n", max);
    printf("line: %s\n", maxline);
  }
}

/* 1.17 print input lines longer than 80 chars */
#define LINE_MAX 1000

void knr_print_long_lines() {
  char line[LINE_MAX];
  int len = 0;

  while((len = knr_readline(line, LINE_MAX)) > 0) {
    if(len > 79) printf("%s", line);
  }
}

/* 1.18 clean trailing whitespace */

/* macro for min avoiding the risk of double evaluation */
#define min(a,b) \
  ({ __typeof__ (a) _a = (a); \
     __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

void knr_remove_trailing_whitespace() {
  char line[LINE_MAX];
  int len = 0;

  while((len = knr_readline(line, LINE_MAX)) > 0) {
    int i = min(len, LINE_MAX - 2); // keep room for newline and null char
    char c;
    char tline[LINE_MAX];

    while(i > 0 && (isblank(line[i]) || line[i] == '\n' || line[i] == '\0'))
      i--;

    // copy line without the trailing whitespace
    strncpy(tline, line, i + 1); // copy up until beginning of whitespace
    tline[i+1] = '\n'; // terminate the line
    tline[i+2] = '\0'; // terminate the str

    if(i > 0) printf("%s", tline);
  }
}

/* 1.19 reverse input line by line */
char* knr_reverse(char s[]) {
  char *r = (char *)malloc(strlen(s) * sizeof(char));

  int j = 0;
  for(int i = strlen(s) - 1; i >= 0; i--, j++)
    r[j] = s[i];
  r[j] = '\0'; // terminate string
  return r;
}

void knr_reverse_line_by_line() {
  char line[LINE_MAX];
  int len = 0;

  while((len = knr_readline(line, LINE_MAX)) > 0)
    printf("%s", knr_reverse(line));
}

/* 1.20 detab input, replace tabs in the input with space proper number of
   spaces to reach the next tab stop, for fixed size tabstops */
#define TAB_SIZE 4
const static char TAB[TAB_SIZE] = { ' ' };

/* prints the blanks to col returns the number of chars printed */
static int blanks_to_col(int off) {
  int to_col =  TAB_SIZE - (off % TAB_SIZE);
  printf("%*s", to_col, TAB);
  return to_col;
}

void knr_detab() {
  int c;
  int off = 0;
  while((c = getchar()) != EOF) {
    switch(c) {
    case '\n':
      putchar(c);
      off = 0;
      break;
    case '\t':
      off += blanks_to_col(off);
      break;
    default:
      off++;
      putchar(c);
    }
  }
}


/* 1.21 entab replace strings of blanks with the min number of tabs to reach
   same spacing */

// todo deal with mixed tab and space
// todo deal with utf-8
void knr_entab(FILE *in, FILE *out) {
  int c;
  int off = 0;
  int to_col;
  int cons_s;
  while((c = getc(in)) != EOF) {
    switch(c) {
    case '\n':
      putc(c, out);
      off = 0;
      break;
    case ' ':
      // spaces until we have a tab
      to_col = TAB_SIZE - (off % TAB_SIZE);
      if (to_col == 0) to_col = TAB_SIZE;

      cons_s = 0; // conseq spaces found so far

      do {
        if(c == '\n' || c == EOF) {
          fprintf(out, "%*s", cons_s, TAB);
          // deal with in the outer loop
          ungetc(c, in);
          break;
        } else if(c == ' ') {
          cons_s++;
        } else {
          // could not fill up a tab, so print the spaces
          off += cons_s;

          fprintf(out, "%*s", cons_s, TAB);
          putc(c, out);
          break;
        }

        if(cons_s == to_col) {
          off = 0;
          putc('\t', out);
          break;
        }
      } while((c = getc(in)));
      break;
    default:
      off++;
      putc(c, out);
    }
  }
}
