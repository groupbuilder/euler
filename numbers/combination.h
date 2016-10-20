#include <stdint.h>

class Combination {
public:
  Combination(int m);
  ~Combination();
  uint64_t Cmn(int i, int j);
  uint64_t Frac(int n);
  uint64_t** C;
  uint64_t* F;
  int m_;
};
