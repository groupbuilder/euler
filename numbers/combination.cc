#include "combination.h"

Combination::Combination(int m) {
  m_ = m;
  C = new uint64_t*[m + 1];
  for (int i = 1; i <= m; i++) {
    C[i] = new uint64_t[i + 1];
  }
  for (int i = 1; i <= m; i++) {
    C[i][0] = C[i][i] = 1;
  }
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  F = new uint64_t[m + 1];
  F[0] = F[1] = 1;
  for (int i = 2; i <= m; i++) {
    F[i] = F[i - 1] * i;
  }
}

Combination::~Combination() {
  for (int i = 1; i <= m_; i++) {
    if (C[i]) {
      delete[] C[i];
    }
  }
  if (C) {
    delete[] C;
  }
}

uint64_t Combination::Cmn(int i, int j) {
  if (i < j) {
    return 0;
  }
  if (i == j || j == 0) {
    return 1;
  }
  return C[i][j];
}

uint64_t Combination::Frac(int n) {
  return F[n];
}
