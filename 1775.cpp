#include <iostream>
#include <cstring>

using namespace std;

long long int sabor[1010];
int dp[1010][1010];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int solve(int left, int right)
{
    if (left == right)
        return 1;

    if (dp[left][right] != -1)
        return dp[left][right];

    if (sabor[left] == sabor[right]) {
        if (right == left+1)
            return 1;
        else
            return dp[left][right] = solve(left+1, right-1) + 1;
    }

    return dp[left][right] = min(solve(left+1, right)+1, solve(left, right-1)+1);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    FOR(z, 0, t) {
        scanf("%d", &n);
        FOR(i, 0, n) {
            scanf("%lld", &sabor[i]);
        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(0, n-1));
    }
    return 0;
}
