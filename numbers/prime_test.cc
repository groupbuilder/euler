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
  printf("Gcd(12, 8) is %d\n", Gcd(12, 8));
  printf("Gcd(15, 16) is %d\n", Gcd(15, 16));
  return 0;
}
