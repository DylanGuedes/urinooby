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
    int maxtempo = -1<<30;
    FOR(i, 0, n) {
        scanf("%d", &y[i]);
        scanf("%d", &x[i]);
        scanf("%d", &t[i]);
        maxtempo = max(maxtempo, t[i]);
    }

    memset(dp, 0, sizeof dp);

    FOR(i, 0, n) {
        if (t[i]!=maxtempo)
            continue;
        dp[t[i]][y[i]][x[i]] += 1;
    }

    for (int i=maxtempo-1;i>=0;i--) {
        FOR(k, 0, 21) {
            FOR(l, 0, 21) {
                vector<ii> myv { ii(k+1, l), ii(k, l+1), ii(k-1, l), ii(k, l-1), ii(k, l) };
                for (auto it : myv) {
                    if (it.first < 0 || it.second < 0 || it.first > 20 || it.second > 20)
                        continue;
                    dp[i][k][l] = max(dp[i][k][l], dp[i+1][it.second][it.first]);
                }
                for (int j=0;j<n;++j) {
                    if (t[j]==i && x[j]==l && y[j]==k) {
                        dp[i][k][l]+=1;
                    }
                }
            }
        }
    }

    printf("%d\n", dp[0][6][6]);
    return 0;
}
