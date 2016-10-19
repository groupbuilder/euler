#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

/*
 * 90342 ;2 correct
 * 70794 ;0 correct
 * 39458 ;2 correct
 * 34109 ;1 correct
 * 51545 ;2 correct
 * 12531 ;1 correct
 *
 * ans = 39542
 */
/*
const int A[6] = {
  2, 0, 2, 1, 2, 1
};
const string M[6] = {
  "90342",
  "70794",
  "39458",
  "34109",
  "51545",
  "12531",
};
*/

const int A[22] = {
  2, 1, 3, 3, 3, 1, 2, 3, 1, 2, 3, 1, 1, 2, 0, 2, 2, 3, 1, 3, 3, 2
};
const string M[22] = {
"5616185650518293",
"3847439647293047",
"5855462940810587",
"9742855507068353",
"4296849643607543",
"3174248439465858",
"4513559094146117",
"7890971548908067",
"8157356344118483",
"2615250744386899",
"8690095851526254",
"6375711915077050",
"6913859173121360",
"6442889055042768",
"2321386104303845",
"2326509471271448",
"5251583379644322",
"1748270476758276",
"4895722652190306",
"3041631117224635",
"1841236454324589",
"2659862637316867",
};

int64_t p10[20];
vector<int> idx;
int n, m;

int cmp(int a, int b) {
  return A[a] > A[b];
}

void OutputS(const vector<int16_t>& S) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", (1 << j) & S[i] ? '1' : '0');
    }
    printf("\n");
  }
}

bool Valid(const vector<int16_t>& S) {
  for (int i = 0; i < m; i++) {
    if (!S[i]) {
      return false;
    }
  }
  return true;
}

bool AllWrong(const string& guess, int j, const vector<int16_t>& S) {
  //printf("guess = %s\n", guess.c_str());
  for (int i = j; i < m; i++) {
    if ((1 << (guess[i] - '0')) == S[i]) {
      return false;
    }
  }
  return true;
}

void UpdateTail(const string& guess, int j, vector<int16_t>* S) {
  for (int i = j; i < m; i++) {
    (*S)[i] &= ~(1 << (guess[i] - '0'));
  }
}

bool Compatible(int j, int gn, const vector<int16_t>& S) {
  return S[j] & (1 << gn);
}

void UpdateOne(int j, int gn, vector<int16_t>* S) {
  (*S)[j] &= (1 << gn);
}

int64_t Solve(int ix, vector<int16_t>* S);
int64_t TryPosition(int ix, int j, int c, vector<int16_t>* S) {
  //printf("TryPosition(%d, %d, %d, S), idx[ix] = %d\n", ix, j, c, idx[ix]);
  //OutputS(*S);
  if (m - j < c) {
    return -1;
  }
  if (c == 0) {
    if (AllWrong(M[idx[ix]], j, *S)) {
      UpdateTail(M[idx[ix]], j, S);
      return Solve(ix + 1, S);
    } else {
      return -1;
    }
  }
  int gn = M[idx[ix]][j] - '0';
  //printf("gn = %d\n", gn);
  if (Compatible(j, gn, *S)) {
    vector<int16_t> nS = *S;
    UpdateOne(j, gn, &nS);
    int64_t r = TryPosition(ix, j + 1, c - 1, &nS);
    if (r != -1) {
      return r;
    }
  }
  (*S)[j] &= ~(1 << gn);
  return TryPosition(ix, j + 1, c, S);
}

int64_t Solve(int ix, vector<int16_t>* S) {
  //printf("ix = %d\n", ix);
  //OutputS(*S);
  if (!Valid(*S)) {
    return -1;
  }
  if (ix == n) {
    int64_t ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 10; j++) {
        if ((*S)[i] & (1 << j)) {
          ans += p10[m - i - 1] * j;
          break;
        }
      }
    }
    //printf("ans = %lld\n", ans);
    return ans;
  }
  return TryPosition(ix, 0, A[idx[ix]], S);
}

void Verify(int64_t ans) {
  int d[16];
  for (int i = m - 1; i >= 0; i--) {
    d[i] = ans % 10;
    ans /= 10;
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      if (M[i][j] - '0' == d[j]) {
        c++;
      }
    }
    if (c != A[i]) {
      printf("%s wrong, %d vs %d\n", M[i].c_str(), c, A[i]);
    }
  }
}

int main() {
  p10[0] = 1;
  for (int i = 1; i < 20; i++) {
    p10[i] = p10[i - 1] * 10;
  }
  n = sizeof(A) / sizeof(A[0]);
  printf("n = %d\n", n);
  for (int i = 0; i < n; i++) {
    idx.push_back(i);
  }
  sort(idx.begin(), idx.end(), cmp);
  for (int i = 0; i < n; i++) {
    printf("%d ", idx[i]);
  }
  printf("\n");

  m = M[0].size();
  printf("%d\n", m);
  vector<int16_t> S;
  for (int i = 0; i < m; i++) {
    S.push_back(1023);
  }
  int64_t ans = Solve(0, &S);
  printf("ans = %lld\n", ans);
  Verify(ans);
  return 0;
}
