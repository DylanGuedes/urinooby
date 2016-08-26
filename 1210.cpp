#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[2020][2020];
#define FOR(i, j, k)for(int i=j;i<k;++i)

int n, p, m;
int v[2020];
int c[2020];

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

        memset(dp, 0, sizeof dp);

        for(int i=n;i>=0;i--) {
            FOR(j, 1, m+1) {
                dp[i][j] = dp[i+1][1]-v[j-1]+p+c[0];
                if (j == m)
                    continue;
                dp[i][j] = min(dp[i][j], dp[i+1][j+1]+c[j]);
            }
        }

        cout << dp[1][ini] << "\n";
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
