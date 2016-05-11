#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int visited[5050];
vector<int> graph[5050];

void bfs(int idx)
{
    queue<int> myq;
    myq.push(idx);
    while (not myq.empty()) {
        idx = myq.front(); myq.pop();
        visited[idx] = 1;
        for (auto it : graph[idx]) {
            if (visited[it] == 0) {
                myq.push(it);
            }
        }
    }
}

int main()
{
    int n, m;
    int origin, destiny;
    while (cin >> n) {
        if (n == 0)
            return 0;
        cin >> m;

        for (int i=0; i < n+1; ++i) {
            graph[i].clear();
        }

        for (int i=0; i < m; ++i) {
            cin >> origin >> destiny;
            graph[origin].push_back(destiny);
        }

        set<int> mybase;
        for (int i=1; i <= n; ++i) {
            mybase.insert(i);
        }

        for (int i=1; i <= n; ++i) {
            memset(visited, 0, sizeof visited);
            // cout << "i: " << i << endl;
            bfs(i);
            for (int j=1; j <= n; ++j) {
                if (i != j) {
                    if (visited[j] == 0) {
                        mybase.erase(j);
                    }
                }
            }
        }

        for (auto it = mybase.begin(); it != mybase.end(); ++it) {
            if (it != mybase.begin()) printf(" ");
            printf("%d", *it);
        }
        cout << endl;
    }
    return 0;
}
