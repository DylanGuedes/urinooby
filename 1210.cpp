#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[2020][2020];
#define FOR(i, j, k)for(int i=j;i<k;++i)

int n, p, m;
int v[2020];
int c[2020];

int solve(int idx, int tempo)
{
    if (idx == n+1)
        return 0;

    if (dp[idx][tempo] != -1)
        return dp[idx][tempo];

    dp[idx][tempo] = solve(idx+1, 0) - v[tempo] + p;
    if (tempo != m) {
        dp[idx][tempo] = min(dp[idx][tempo], solve(idx+1, tempo+1) + c[tempo]);
    }

    return dp[idx][tempo];
}

// int compute_min_cost(void) {
//     for(int j = n; j > 0; --j) {
//         dp[j][m] = dp[j + 1][1] + p + cost[0] - value[m];
//         son[j][m] = ii(j + 1, 1);
//         for(int k = m - 1; k > 0; --k) {
//             int maintenance = dp[j + 1][k + 1] + cost[k];
//             int sale = dp[j + 1][1] + p + cost[0] - value[k];
//             if(maintenance >= sale) {
//                 son[j][k] = ii(j + 1, 1);
//             } else {
//                 son[j][k] = ii(j + 1, k + 1);
//             }
//
//             dp[j][k] = min(maintenance, sale);
//         }
//     }
//
//     return dp[1][i];
// }

int main()
{
    int ini;
    while (cin >> n >> ini >> m >> p) {
        FOR(i, 0, m) {
            scanf("%d", &c[i]);
        }

        FOR(i, 0, m) {
            scanf("%d", &v[i]);
        }

        memset(dp, -1, sizeof dp);

        // solve(0, ini);
        // FOR(i, 0, m) {
        //     dp[n][i] = min(c[i], p-v[i]);
        // }

        // for (int i=n; i>=0; i--) {
        //     FOR(j, 0, m) {
        //         dp[i][j] = min(p-v[j]+dp[i+1][0], c[j]+dp[i+1][j+1]);
        //     }
        // }

        printf("%d\n", solve(1, ini));
        printf("DP:\n");
        FOR(i, 0, n+1) {
            FOR(j, 0, m+1) {
                printf("[%d][%d] = %d\t", i, j, dp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
