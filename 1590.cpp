#include <iostream>

using namespace std;

int arr[50];
int n;

int solve(int remaining, int idx, int sol)
{
    // cout << "remaining: " << remaining << ", idx: " << idx << ", sol: " << sol << endl;
    if (idx > n) return -1;
    if (remaining == 0) return sol;

    return max( solve(remaining-1, idx+1, (sol & arr[idx])), solve(remaining, idx+1, sol));
}

int main()
{
    int t;
    int k;

    cin >> t;
    for (int w=0; w < t; ++w) {
        cin >> n >> k;
        for (int i=0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << solve(k, 0, -1) << endl;
    }
    return 0;
}
