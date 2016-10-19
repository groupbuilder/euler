#include <algorithm>
#include <stdio.h>

#include "numbers/prime.h"

using namespace std;

const int N = 100000000;
//const int N = 100;
Prime pr(N + 1);

int s[N + 1];

int Count(int n, int p) {
  int res = 0;
  while (n) {
    res += n / p;
    n /= p;
  }
  return res;
}

int main() {
  int64_t ans = 0;
  for (int i = 2; i <= N; i++) {
    if (pr.IsPrime(i)) {
      s[i] = i;
    } else {
      for (int j = 0; pr.P[j] * pr.P[j] <= i; j++) {
        if (i % pr.P[j] == 0) {
          int c = i / pr.P[j];
          int r = pr.P[j];
          int k = 1;
          while (c % pr.P[j] == 0) {
            c /= pr.P[j];
            r *= pr.P[j];
            k++;
          }
          if (c == 1) {
            if (Count(s[i / pr.P[j]], pr.P[j]) >= k) {
              s[i] = s[i / pr.P[j]];
            } else {
              s[i] = s[i / pr.P[j]] + pr.P[j];
            }
          } else {
            s[i] = max(s[r], s[i / r]);
          }
          break;
        }
      }
    }
    ans += s[i];
  }
  printf("ans = %lld\n", ans);
  return 0;
}
