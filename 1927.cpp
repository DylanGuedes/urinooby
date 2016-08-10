#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int dp[1005][21][21];
int x[2005];
int y[2005];
int t[2005];

#define ii pair<int, int>

int main()
{
    int n;
    cin >> n;
    int maxtempo = -0xffffff;
    FOR(i, 0, n) {
        scanf("%d", &y[i]);
        scanf("%d", &x[i]);
        scanf("%d", &t[i]);
        maxtempo = max(maxtempo, t[i]);
    }

    memset(dp, 0, sizeof dp);
    for(int idx=n-1; idx>=0; idx--) {
        if (t[idx] == maxtempo)
            dp[t[idx]][x[idx]][y[idx]] = 1;
    }

    // printf("DP:\n");
    // FOR(i, 0, t[n-1]+1) {
    //     FOR(j, 0, 21) {
    //         FOR(k, 0, 21) {
    //             printf("[%d][%d][%d] = %d\t", i, j, k, dp[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }
    for(int idx=maxtempo-1; idx>=0; idx--) {
        FOR(i, 0, 21) {
            FOR(j, 0, 21) {
                vector<ii> myv { make_pair(i+1, j), make_pair(i-1, j), make_pair(i, j-1), make_pair(i, j+1), make_pair(i, j) };
                for (auto it : myv) {
                    if (it.first >= 0 && it.first <= 20 && it.second >= 0 && it.second <= 20) {
                        dp[idx][i][j] = max(dp[idx][i][j], dp[idx+1][it.first][it.second]);
                    }
                }

                for(int maca=n-1; maca>=0; maca--) {
                    if (t[maca] == idx && x[maca] == i && y[maca] == j) {
                        dp[idx][i][j] += 1;
                    }
                }
            }
        }
    }

    // FOR(i, 0, t[n-1]+1) {
    //     FOR(j, 0, 21) {
    //         FOR(k, 0, 21) {
    //             printf("[%d][%d][%d] = %d\t", i, j, k, dp[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }

    printf("%d\n", dp[0][6][6]);
    return 0;
}
