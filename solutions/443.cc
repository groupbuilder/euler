#include <stdio.h>
#include <string.h>

#include "numbers/prime.h"

Prime pr(100000001);
int64_t N = 1000000000000000LL;
//int64_t N = 1000000LL;

int64_t MinFactor(int64_t x) {
  for (int i = 0; pr.P[i] <= x / pr.P[i]; i++) {
    if (x % pr.P[i] == 0) {
      return pr.P[i];
    }
  }
  return x;
}

int main() {
  int64_t n = 4;
  int64_t gn = 13;
  int64_t pn, pgn;
  while (n < N) {
    pn = n;
    pgn = gn;
    int64_t g = Gcd(n + 1, gn);
    if (g > 1) {
      gn += g;
      n++;
    } else {
      int64_t m = MinFactor(gn - n - 1);
      int64_t x = m - (n + 1) % m;
      gn += Gcd(n + 1 + x, gn + x) + x;
      n += x + 1;
    }
    printf("G(%lld) = %lld\n", n, gn);
  }
  printf("ans = %lld\n", pgn + (N - pn));
  return 0;
}
