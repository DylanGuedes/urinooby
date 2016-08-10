#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define ii pair<int, int>
#define iii pair<int, ii >

vector<int> mys[3];
int dp[110][110][110];

short solve(int q0, int q1, int q2)
{
    if (q0==mys[0].size() && q1==mys[1].size() && q2==mys[2].size())
        return 1;

    if (q0>mys[0].size() || q1>mys[1].size() || q2>mys[2].size())
        return 0;
    // printf("q0: %d, q1: %d, q2: %d\n",q0, q1, q2);

    if (dp[q0][q1][q2] != -1)
        return dp[q0][q1][q2];

    short ans = 0;
    int item0=mys[0][q0], item1=mys[1][q1], item2=mys[2][q2];
    vector<iii> myv {iii(1,ii(0,0)),iii(0,ii(1,0)),iii(0,ii(0,1)),iii(1,ii(1,0)),iii(1,ii(0,1)),iii(0,ii(1,1)),iii(1,ii(1,1)) };
    for (auto it : myv) {
        int idx = 0;
        if (it.first) {
            idx+=item0;
        }
        if (it.second.first) {
            idx+=item1;
        }
        if (it.second.second) {
            idx+=item2;
        }
        if (idx%3==0) {
            // printf("idx %d eh multiplo!!!\n", idx);
            ans=max(ans, solve(q0+it.first, q1+it.second.first, q2+it.second.second));
        }
            // printf("idx %d nao multiplo..\n", idx);
    }

    return dp[q0][q1][q2] = ans;
}

int main()
{
    int n, a, b, c;
    while (scanf("%d", &n) != EOF) {
        if (not n)
            return 0;
        mys[0].clear();
        mys[1].clear();
        mys[2].clear();
        memset(dp, -1, sizeof dp);
        FOR(i, 0, n) {
            scanf("%d", &a);
            scanf("%d", &b);
            scanf("%d", &c);
            mys[0].push_back(a);
            mys[1].push_back(b);
            mys[2].push_back(c);
        }

        printf("%d\n", solve(0,0,0));
    }

    return 0;
}
