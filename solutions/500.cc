#include <math.h>
#include <functional>
#include <queue>
#include <vector>

#include "numbers/prime.h"
#include "numbers/modular.h"

int N = 500500507;
int* P;

using namespace std;

int main() {
  Prime pn(10000000);
  P = new int[pn.Count()];
  for (int i = 0; i < pn.Count(); i++) {
    P[i] = pn.P[i];
  }
  auto cmp = [](pair<int, int> left, pair<int, int> right) {
    //printf("left = (%d, %lld), right = (%d, %lld)\n", left.first, left.second, right.first, right.second);
    if (left.second == 1 && right.second == 1) {
      return left.first > right.first;
    } else if (left.second == 1) {
      //printf("l = %lf, r = %lf\n", log(P[left.first]), (1LL << (right.second - 1)) * log(P[right.first]));
      return log(P[left.first]) > (1LL << (right.second - 1)) * log(P[right.first]);
    } else if (right.second == 1) {
      return (1LL << (left.second - 1)) * log(P[left.first]) > log(P[right.first]);
    } else {
      return (1LL << (left.second - 1)) * log(P[left.first]) > (1LL << (right.second - 1)) * log(P[right.first]);
    }
  };
  std::priority_queue<int, std::vector<pair<int, int>>, decltype(cmp)> Q(cmp);
  int count = 0;
  Q.push(make_pair(0, 1));
  while (count < 500500) {
  //while (count < 4) {
    auto top = Q.top();
    Q.pop();
    if (top.second == 1) {
      Q.push(make_pair(top.first + 1, 1));
    }
    Q.push(make_pair(top.first, top.second + 1));
    count++;
  }
  int ans = 1;
  while (!Q.empty()) {
    auto top = Q.top();
    Q.pop();
    ans = 1LL * ans * Modular::AeBmP(P[top.first], (1 << (top.second - 1)) - 1, N) % N;
  }
  printf("ans = %d\n", ans);
  return 0;
}
