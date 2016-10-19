#include <stdio.h>

int D[20];
int C[10];

void Choose(int start, int count, int sum) {
  if (start == 20) {
      return;
  } 
  if (sum == 45 && count == 10) {
    // find one
    return;
  } else if (count == 10 || sum >= 45) {
    return;
  }
  Choose(start + 1, count, sum);
  if (count < 10 && sum + D[start] <= 45) {
    C[count] = D[start];
    Choose(start + 1, count + 1, sum + D[start]);
  }
}

int main() {
  for (int i = 0; i < 20; i += 2) {
    D[i] = D[i + 1] = i / 2;
  }
  Choose(0 /* start */, 0 /* count */, 0 /* sum */);
}
