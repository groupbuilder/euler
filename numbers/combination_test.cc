#include <stdio.h>
#include <stdlib.h>

#include "combination.h"

int main(int argc, char* argv[]) {
  Combination c(atoi(argv[1]));
  printf("C(%s, %s) = %lld\n", argv[2], argv[3], c.Cmn(atoi(argv[2]), atoi(argv[3])));
  printf("F[%s] = %lld\n", argv[2], c.Frac(atoi(argv[2])));
  return 0;
}
