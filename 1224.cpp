#include <iostream>
#include <cstring>

using namespace std;

int val[10020];
int dp[10000][10000][2];

#define FOR(i, j, k)for(int i=j;i<k;++i)

// int solve(int idx)
// {
//     memset(dp, -1, sizeof dp);
//
//     FOR(i, 0, n-2) {
//         int melhor = max(v[i], v[i+2]);
//         int pior = min(v[i], v[i+2]);
//         int meio = v[i+1];
//         dp[idx] = max(pior+meio, melhor+min(pior, meio));
//     }
//
//
// }

int solve(int left, int right, short alberto)
{
    if (left == right) {
        return val[left];
    }

    if (dp[left][right][alberto] != -1)
        return dp[left][right][alberto];

    if (alberto) {
        return dp[left][right][alberto] = max(solve(left+1, right, 0)+val[left], solve(left, right-1, 0)+val[right]);
    } else {
        return dp[left][right][alberto] = min(solve(left+1, right, 1)+val[left], solve(left, right-1, 1)+val[right]);
    }
}

int main()
{
    int n;
    while (cin >> n) {
        FOR(i, 0, n) {
            scanf("%d", &val[i]);
        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(0, n-1, 1));
    }
    return 0;
}
