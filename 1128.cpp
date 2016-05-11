#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool impossible;
int visited[2010];
int father[2010];
int lowtime[2010];
int times[2010];
vector<int> graph[2010];
int scc;

void tarjan(int idx, int val)
{
    visited[idx] = 1;
    lowtime[idx] = val;
    times[idx] = val;

    for (auto it : graph[idx]) {
        if (visited[it] == 0) {
            tarjan(it, val+1);
            lowtime[idx] = min(lowtime[idx], lowtime[it]);
        } else {
            lowtime[idx] = min(lowtime[idx], lowtime[it]);
        }
    }

    if (lowtime[idx] == times[idx])
        ++scc;
}

int main()
{
    int n, m, origin, destiny, connection_type;

    while (cin >> n >> m) {
        if (not (n | m))
            return 0;

        for (int i=0; i < n+1; ++i) {
            graph[i].clear();
            father[i] = i;
        }

        for (int i=0; i < m; ++i) {
            cin >> origin >> destiny >> connection_type;
            if (connection_type == 1)
                graph[origin-1].push_back(destiny-1);
            else {
                graph[origin-1].push_back(destiny-1);
                graph[destiny-1].push_back(origin-1);
            }
        }

        memset(visited, 0, sizeof visited);
        impossible = true;
        scc = 0;

        for (int i=0; i < n; ++i) {
            if (visited[i] == 0)
                tarjan(i, 0);
        }

        if (scc == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
