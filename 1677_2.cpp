#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int disc[5050];
int lowtime[5050];
set<int> scc;
vector<int> graph[5050];
int visited[5050];
stack<int> mys;
int myval;

void tarjan(int idx, int val)
{
    lowtime[idx] = val;
    disc[idx] = val;
    visited[idx] = 1;
    mys.push(idx);
    myval++;
    for (auto it : graph[idx]) {
        if (visited[it] == 1) {
            lowtime[idx] = min(lowtime[idx], lowtime[it]);
        } else {
            tarjan(it, val+1);
            lowtime[idx] = min(lowtime[idx], lowtime[it]);
        }
    }

    if (disc[idx] == lowtime[idx]) {
        printf("disc[%d] == lowtime[%d]\n", idx, idx);
        while (not mys.empty()) {
            int node = mys.top(); mys.pop();
            if (node == idx) {
                scc.insert(node);
                break;
            }
        }
    } else {
        printf("disc[%d] != lowtime[%d]\n", idx, idx);
    }
}

int main()
{
    int n, m, origin, destiny;
    while (cin >> n) {
        if (n == 0)
            return 0;
        cin >> m;

        scc.clear();

        for (int i=0; i < n+1; ++i) {
            graph[i].clear();
        }


        for (int i=0; i < m; ++i) {
            cin >> origin >> destiny;
            graph[origin].push_back(destiny);
        }

        while (not mys.empty()) {
            mys.pop();
        }

        // printf("começa tarjan\n\n\n");

        memset(visited, 0, sizeof visited);
        myval = 0;
        for (int i=1; i <= n; ++i) {
            if (visited[i] == 0) {
                tarjan(i, 0);
                memset(visited, 0, sizeof visited);
            }
        }

        // printf("finaliza tarjan");
        for (auto it=scc.begin(); it != scc.end(); ++it) {
            if (it != scc.begin()) printf(" ");
            printf("%d", *it);
        }
        cout << endl;
    }

    return 0;
}
