#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i, j, k) for(int i=j;i<k;++i)

vector<int> coins;
bool possible;
int n;
short dp[100010][100010];

short solve(int idx, int remaining)
{
    if (remaining == 0) {
        possible = true;
        return 1;
    }

    if (idx == n)
        return 0;

    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];


    short ans = solve(idx+1, remaining);
    if (coins[idx] <= remaining) {
        ans = max(ans, solve(idx+1, remaining-coins[idx]));
    }

    return dp[idx][remaining] = ans;
}

int main()
{
    int m, aux, v;
    while (cin >> v >> n) {
        if (not (v|n)) return 0;

        memset(dp, 0, sizeof dp);
        coins.clear();
        FOR(i, 0, n) {
            scanf("%d", &aux);
            coins.push_back(aux);
        }

        sort(coins.begin(), coins.end());

        int mysize = coins.size();

        memset(dp, 0, sizeof dp);
        FOR(i, 0, mysize) {
            dp[i][0] = 1;
        }

        FOR(i, 0, mysize) {
            dp[i][coins[i]] = 1;
        }

        for (int i=mysize-1; i>=0;i--) {
            FOR(j, 1, v+1) {
                if (dp[i][j] != 1) {
                    dp[i][j] = dp[i+1][j];
                    if (j-coins[i] >= 0) {
                        dp[i][j] |= dp[i+1][j-coins[i]];
                    }
                }
            }
        }

        if (dp[0][v]) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    return 0;
}
