#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int coins[26];
int dp[1000000];

#define FOR(i, j, k)for (int i=j;i<k;++i)

int main()
{
    int t;
    long long int n, m;
    long long int aux_i;

    cin >> t;
    for (int w=0; w < t; ++w) {
        scanf("%lld", &n);
        scanf("%lld", &m);

        for (int i=0; i < n; ++i) {
            scanf("%lld", &aux_i);
            coins[i] = aux_i;
        }

        FOR(i, 0, m+5)
            dp[i] = 1<<30;
        dp[0] = 0;
        FOR(i, 0, n) {
            int coin = coins[i];
            FOR(j, coin, m+1) {
                dp[j] = min(dp[j], dp[j-coin]+1);
            }
        }

        printf("%d\n", dp[m]);
    }
    return 0;
}
