#include <bits/stdc++.h>

using namespace std;

int arr[10020];
int dp[10020];
int s[10020][10020];

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j)for(int i=j;i>=0;i--)

int main()
{
        ios::sync_with_stdio(false);
        int n;
        while (cin >> n) {
                repi(i, 0, n)
                        cin >> dp[i];

                repi(i, 0, n) {
                        repd(j, n-1) {
                                dp[i][j] = max(dp[i], d[j]);
                        }
                }
                cout << s[0][n-1] << "\n";
        }
        return 0;
}
