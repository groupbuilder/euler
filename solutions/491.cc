#include <stdio.h>
#include <string.h>

#include "numbers/combination.h"

int C[10];
Combination kC(20);
uint64_t ans;

uint64_t Count(int n, int c[10]) {
  uint64_t f = kC.Frac(n);
  printf("f = %llu\n", f);
  for (int i = 0; i < 10; i++) {
    if (c[i] == 2) {
      f /= 2;
    }
  }
  printf("f = %llu\n", f);
  return f;
}

uint64_t Solve() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < C[i]; j++) {
      printf("%d ", i);
    }
  }
  printf("\n");

  int c2[10];
  for (int i = 0; i < 10; i++) {
    c2[i] = 2 - C[i];
  }

  uint64_t res = Count(10, C) * Count(10, c2);
  printf("res = %lld, c[0] = %d\n", res, C[0]);
  if (C[0] == 0) {
    return res;
  } else if (C[0] == 1) {
    return res / 10 * 9;
  } else {
    return res / 45 * 36;
  }
}

int S = 0;
void Choose(int start, int count, int sum) {
  if (sum == S && count == 10) {
    // find one
    ans += Solve();
    return;
  } else if (count == 10 || sum >= S) {
    return;
  }
  if (start >= 10) {
      return;
  } 
  C[start] = 0;
  Choose(start + 1, count, sum);
  if (count < 10 && sum + start <= S) {
    C[start] = 1;
    Choose(start + 1, count + 1, sum + start);
    if (count < 9 && sum + 2 * start <= S) {
      C[start] = 2;
      Choose(start + 1, count + 2, sum + 2 * start);
    }
  }
}

int main() {
  ans = 0;
  for (S = 12; S < 90; S += 11) {
    Choose(0 /* start */, 0 /* count */, 0 /* sum */);
  }
  printf("ans = %lld\n", ans);
}
