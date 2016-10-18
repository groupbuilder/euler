#include "prime.h"

Prime::Prime(int n) {
  N = n;
  T = new bool[n];
  pcnt = 0;
  int i = 2;
  for (; i * i < n; i++) {
    if (!T[i]) {
      pcnt++;
      for (int j = i * i; j < n; j += i) {
        T[j] = true;
      }
    }
  }
  for (; i < n; i++) {
    if (!T[i]) {
      pcnt++;
    }
  }
  P = new int[pcnt];
  int j = 0;
  for (i = 2; i < n; i++) {
    if (!T[i]) {
      P[j++] = i;
    }
  }
}

Prime::~Prime() {
  if (T) {
    delete[] T;
  }
  if (P) {
    delete[] P;
  }
}

bool Prime::IsPrime(long long x) {
  if (x < N) {
    return !T[x];
  } else if (x / N <= N) {
    for (int i = 0; i < pcnt; i++) {
      if (x % P[i] == 0) {
        return true;
      }
    }
    return false;
  } else {
    return false;
  }
}

int Prime::Count() {
  return pcnt;
}
