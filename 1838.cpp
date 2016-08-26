#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
using ii = pair<int, int>;
ii pesq[1005];
int dp[1005][3800];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int solve(int idx, int tmp)
{
    if (idx == n)
        return 0;
    if (tmp == 3600)
        return 0;
    if (dp[idx][tmp] != -1)
        return dp[idx][tmp];

    int ans = solve(idx+1, tmp);

    if (tmp<=pesq[idx].first) {
        ans = max(ans, solve(idx+1, pesq[idx].second)+pesq[idx].second - pesq[idx].first);
    }
    return dp[idx][tmp] = ans;
}

bool myfunc(ii a, ii b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    int inicio, fim;
    scanf("%d", &n);
    FOR(i, 0, n) {
        scanf("%d%d", &pesq[i].first, &pesq[i].second);
    }
    memset(dp, -1, sizeof dp);
    sort(pesq, pesq+n, myfunc);
    printf("%d\n", solve(0, 0));
    return 0;
}
