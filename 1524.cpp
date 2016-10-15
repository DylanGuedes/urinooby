#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int arr[1010];

int n;
int solve(int idx, int k)
{
        if (idx == n)
                return 0;
}

int main()
{
        int k;
        ios::sync_with_stdio(false);
        while (cin >> n >> k) {
                FOR(i, 0, n)
                        cin >> arr[i];
                cout << solve(0, k) << "\n";
        }
}
