#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int dp[19][300000];
int arr[19][19];
int n;

int solve(int idx, bitset<18> estado)
{
    if (estado.count() == n)
        return 0;

    if (idx > n)
        return 0xffffff;

    if (dp[idx][estado.to_ulong()] != -1)
        return dp[idx][estado.to_ulong()];

    int ans = 0xffffff;
    FOR(i, 0, n) {
        if (not estado[i]) {
            estado[i] = 1;
            ans=min(ans, solve(idx+1, estado)+arr[i][idx]);
            estado[i] = 0;
        }
    }

    return dp[idx][estado.to_ulong()]=ans;
}

int main()
{
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            return 0;
        memset(dp, -1, sizeof dp);
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                scanf("%d", &arr[i][j]);
            }
        }
        bitset<18> myset;
        printf("%d\n", solve(0, myset));
    }
    return 0;
}
