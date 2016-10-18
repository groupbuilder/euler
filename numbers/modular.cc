#include "modular.h"

int Modular::AxBmP(int a, int b, int p) {
  return 1LL * a * b % p;
}

int Modular::AeBmP(int a, int b, int p) {
  int m = 1;
  int x = a;
  while (b) {
    if (b & 1) {
      m = 1LL * m * x % p;
    }
    b >>= 1;
    x = 1LL * x * x % p;
  }
  return m;
}
