#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> coins;
int dp[1000000];

#define FOR(i, j, k)for (int i=j;i<k;++i)

int troco(int idx)
{
    if (idx == 0)
        return 0;
    if (idx < 0)
        return 0xffffff;
    if (dp[idx] != -1)
        return dp[idx];

    dp[idx] = 0xffffff;
    for (auto it : coins) {
        dp[idx] = min(dp[idx], troco(idx-it));
    }

    dp[idx] += 1;
    return dp[idx];
}

int main()
{
  int t;
  long long int n, m;
  long long int aux_i;

  cin >> t;
  for (int w=0; w < t; ++w) {
    coins.clear();
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i=0; i < n; ++i) {
        scanf("%d", &aux_i);
      coins.push_back(aux_i);
    }

    // sort(coins.begin(), coins.end());
    memset(dp, -1, sizeof dp);

    dp[0] = 0;
    FOR(i, 1, m+1) {
        dp[i] = 0xffffff;
        for (auto it : coins) {
            if (i-it >= 0) {
                dp[i] = min(dp[i], dp[i-it]);
            }
        }

        dp[i] += 1;
    }
    printf("%d\n", dp[m]);

    // printf("%d\n", troco(m));
  }
  return 0;
}
