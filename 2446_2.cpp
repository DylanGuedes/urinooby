#include <bits/stdc++.h>

using namespace std;

double const eps=1e-8;
using ll = long long;
using ii = pair<int, int>;
#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " = " << x << endl

int n, m, foo, aux;
string str;
#define MAX 1100
#define N 100010
int arr[MAX];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        rep(i, 0, m) {
                cin >> arr[i];
        }
        sort(arr, arr+m);
        rep(i, 0, m) {
                if (i==0) {
                        rep(j, 1, n+1) {
                                if (j==arr[0]) {
                                        dp[0][j]=1;
                                } else {
                                        dp[0][j]=0;
                                }
                        }
                } else {
                        rep(j, 1, n+1) {
                                if (j<arr[i]) {
                                        dp[1][j]=dp[0][j];
                                } else {
                                        dp[1][j] = max(dp[0][j-arr[i]], dp[0][j]);
                                }
                        }
                        swap(dp[1], dp[0]);
                }
        }

        if (dp[1][n]) {
                cout <<"S\n";
        } else {
                cout << "N\n";
        }
        return 0;
}
