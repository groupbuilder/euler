#include <stdio.h>

#include "prime.h"

int main() {
  Prime np(1000000);
  for (int i = 0; i < np.Count(); i++) {
    printf("%d ", np.P[i]);
  }
  printf("\n");
  printf("997 is %d\n", np.IsPrime(997));
  printf("1000 is %d\n", np.IsPrime(1000));
  printf("500500507 is %d\n", np.IsPrime(500500507));
  return 0;
}
