#include <iostream>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int gree[120];
int r, k;
short dp[110][110];
bool possible;

short solve(int idx, int remaining)
{
    if (remaining == 0) {
        possible = true;
        return 1;
    }

    if (idx == r+1)
        return 0;

    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];

    dp[idx][remaining] = solve(idx+1, remaining);
    if (remaining >= gree[idx]) {
        dp[idx][remaining] = max(dp[idx][remaining], solve(idx+1, remaining - gree[idx]));
    }

    return dp[idx][remaining];
}

int main()
{
    int origin, destination;
    while (cin >> r >> k) {
        memset(gree, 0, sizeof gree);
        FOR(i, 0, k) {
            cin >> origin >> destination;
            gree[origin]+=1;
            gree[destination]+=1;
        }

        possible = false;
        memset(dp, -1, sizeof dp);
        solve(1, k);
        if (possible)
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}
