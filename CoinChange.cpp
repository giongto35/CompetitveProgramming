/* Coin Change */

// O(NV) DP solution

#include <cstdio>
#include <cstring>
using namespace std;

int N = 5, V, coinValue[5] = {1, 5, 10, 25, 50}, memo[6][7500];
// N and coinValue are fixed for this problem, max V is 7489

int main() {
  memset(memo, 0, sizeof memo); // we only need to initialize this once
  memo[0][0] = 1;
    for (int i = 0 ; i < N; i++ )
    for (int j = 0 ; j <= 7489; j++ )
        {
            if (i >= 1) memo[i][j] += memo[i-1][j];
            if (j >= coinValue[i]) memo[i][j] += memo[i][j - coinValue[i]];
        }
  while (scanf("%d", &V) != EOF)
    {
        printf("%d",memo[N-1][V]);
    }
  return 0;
}
