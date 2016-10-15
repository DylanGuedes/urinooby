#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

int m, n;
int arr[100005];
int dp[100005];
int sol[100005];

int solve2(int idx)
{
        if (idx >= m)
                return 0;

        if (dp[idx] != -1)
                return dp[idx];

        return dp[idx] = max(sol[idx]+solve2(idx+2), solve2(idx+1));
}

int solve(int idx)
{
        if (idx >= n)
                return 0;

        if (dp[idx] != -1)
                return dp[idx];

        return dp[idx] = max(arr[idx]+solve(idx+2), solve(idx+1));
}

int main()
{
        ios::sync_with_stdio(false);
        while (cin >> m >> n) {
                if (not(m|n))
                        return 0;
                repi(i, 0, m) {
                        memset(dp, -1, sizeof dp);
                        repi(j, 0, n) {
                                cin >> arr[j];
                        }

                        sol[i] = solve(0);
                }

                memset(dp, -1, sizeof dp);
                cout << solve2(0) << "\n";
        }
        return 0;
}
