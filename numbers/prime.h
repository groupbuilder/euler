#include <stdlib.h>

class Prime {
public:
  int* P;
  Prime(int n);
  ~Prime();
  int Count();
  bool IsPrime(long long x);
private:
  bool* T;
  int pcnt;
  int N;
};

int64_t Gcd(int64_t m, int64_t n);
