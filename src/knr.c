#include "knr.h"
#include <stdio.h>

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
/* ./knr < knr.c -> char is not EOF */
/* ./knr < /dev/null -> char is EOF */
void knr_getchar_is() {
  int v = (getchar() != EOF);
  printf("getchar() != EOF: %i\n", v);
  printf("EOF value: %i\n", EOF);
}

/* 1.7 */
void knr_count_blank() {
  int blanks = 0;
  int c;
  while((c = getchar()) != EOF) {
    if(c == '\n' || c == ' ' || c == '\t') blanks++;
  }

  printf("blanks in input: %i", blanks);
}
