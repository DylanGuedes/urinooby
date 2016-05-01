#include <iostream>

using namespace std;

#define ii pair<int, int>
vector<ii> arr;
int t_max;
int n;

bool sort(ii a1, ii a2)
{
    return a1.first < a2.first;
}

int solve(int idx, int remaining, int sol, int node)
{
    if (remaining == 0) return sol;
    if (idx >= t_max) return -1;
    if (node > n) return -1;

    int sol1 = max(solve(idx+1,remaining,sol,node+1), solve(idx+1, remaining-1, sol+1, node);
}

int main()
{
    int m;
    t_max = 0;

    cin >> n >> m;

    arr.clear();
    for (int i=0; i < n; ++i) {
        cin >> t_start >> t_end;
        t_max = max(t_max, t_end);
        arr.push_back(ii(t_start, t_end));
    }

    sort(arr.begin(), arr.end(), myfunc);

    solve(0, m, 0);

    return 0;
}
