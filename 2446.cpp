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
bool appear[N];

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        memset(appear, 0, sizeof appear);
        appear[0]=1;
        rep(i, 0, m) {
                cin >> arr[i];
                appear[arr[i]]=1;
        }
        rep(i, 0, m) {
                for (int j=n; j>=arr[i]; j--) {
                        appear[j] |= (appear[j-arr[i]]);
                }
        }
        if (appear[n]) {
                cout << "S\n";
        } else {
                cout << "N\n";
        }

        return 0;
}
