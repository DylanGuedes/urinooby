#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i, j, k) for(int i=j;i<k;++i)

vector<int> coins;
bool possible;
int n;
int dp[1005][100020];

int solve(int idx, int remaining)
{
    if (remaining == 0)
        return 1;

    if (idx == n)
        return 0;

    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];

    int ans = solve(idx+1, remaining);
    if (remaining - coins[idx] >= 0)
        ans = max(ans, solve(idx+1, remaining-coins[idx]));

    return dp[idx][remaining] = ans;
}

int main()
{
    int m, aux, v;
    while (scanf("%d%d", &v, &n) != EOF) {
        if (not (v|n)) return 0;

        coins.clear();
        FOR(i, 0, n) {
            scanf("%d", &aux);
            coins.push_back(aux);
        }

        memset(dp, -1, sizeof dp);

        if (solve(0, v))
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}
