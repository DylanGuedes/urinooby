#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
int dp[610][610];
int weights[610];
int values[610];

int solve(int idx, int remaining, int score)
{
  if(idx >= n) return score;
  if(dp[idx][remaining] != -1) return dp[idx][remaining];
  if(remaining == 0) return score;

  if ((remaining - weights[idx]) >= 0) {
    dp[idx][remaining] = max(solve(idx+1, remaining, score), solve(idx, remaining - weights[idx], score+values[idx]));
  } else {
    dp[idx][remaining] = solve(idx+1, remaining, score);
  }

  return dp[idx][remaining];
}

int main()
{
  int t, v1, v2, counter = 0;
  while(cin >> n >> t) {
    if (not (n | t)) return 0;
    memset(dp, -1, sizeof dp);
    if (counter != 0) cout << "\n";
    cout << "Instancia " << counter+1 << endl;

    for (int i=0; i < n; ++i) {
      cin >> v1 >> v2;
      weights[i] = v1;
      values[i] = v2;
    }

    cout << solve(0, t, 0) << endl;
    ++counter;
  }
  return 0;
}
