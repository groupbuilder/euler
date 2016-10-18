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

