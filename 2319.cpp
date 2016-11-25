#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define rep(i, j, k)for(int i=j;i<k;++i)
int arr[1010][1010];
int n;
using ii = pair<int, int>;
int solve(int x, int y)
{
        if (x>n || y>n)
                return 1;

        vector<int> myv{ ii(x+1, y), ii(x, y-1) };
        int ans=0;
        for (auto it : myv) {
                if (arr[it.second][it.first] == 0)
                        return 0;
                ans+=solve(it.first, it.second);
        }

        return dp[y][x]=ans;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n;
        rep(i, 0, n) {
                rep(j, 0, n) {
                        cin >> arr[i][j];
                }
        }

        cout << solve(1, 1) << "\n";
        return 0;
}
