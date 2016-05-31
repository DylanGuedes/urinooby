#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int disc[5050];
int lowtime[5050];
vector< vector<int> > scc_dag;
vector<int> graph[5050];
int visited[5050];
stack<int> mys;

bool node_has(vector<int> adjs, int ele)
{
    bool has = false;
    for (auto it : adjs) {
        if (it == ele) {
            has = true;
            break;
        }
    }

    return has;
}


void dfs(int idx)
{
    visited[idx] = 1;
    for (auto it : graph[idx]) {
        if (visited[it] == 0) {
            dfs(it);
        }
    }
}

void bfs(int idx, vector<int> scc)
{
    queue<int> myq;
    myq.push(idx);
    while (not myq.empty()) {
        idx = myq.front(); myq.pop();
        visited[idx] = 1;
        for (auto it : graph[idx]) {
            if (visited[it] == 0)
                myq.push(idx);
        }
    }
}

void tarjan(int idx, int val)
{
    lowtime[idx] = val;
    disc[idx] = val;
    visited[idx] = 1;
    mys.push(idx);

    for (auto it : graph[idx]) {
        if (visited[it] == 1) {
            lowtime[idx] = min(lowtime[idx], lowtime[it]);
        } else {
            tarjan(it, val+1);
            lowtime[idx] = min(lowtime[idx], lowtime[it]);
        }
    }

    if (disc[idx] == lowtime[idx]) {
        vector<int> aux_scc;
        while (not mys.empty()) {
            int node = mys.top(); mys.pop();
            aux_scc.push_back(node);
            if (node == idx) {
                break;
            }
        }

        scc_dag.push_back(aux_scc);
    }
}

int main()
{
    int n, m, origin, destiny;
    while (cin >> n) {
        if (n == 0)
            return 0;
        scanf("%d", &m);

        for (int i=0; i < n+1; ++i) {
            graph[i].clear();
        }

        for (int i=0; i < m; ++i) {
            scanf("%d%d", &origin, &destiny);
            graph[origin].push_back(destiny);
        }

        while (not mys.empty()) {
            mys.pop();
        }

        // printf("começa tarjan\n\n\n");

        scc_dag.clear();
        memset(visited, 0, sizeof visited);
        for (int i=1; i <= n; ++i) {
            if (visited[i] == 0) {
                tarjan(i, 0);
            }
        }
        // printf("finaliza tarjan");
        vector<int> mybase;
        for (auto scc : scc_dag) {
            bool can_be = true;
            for (int i=1; i <= n; ++i) {
                memset(visited, 0, sizeof visited);
                dfs(i);
                for (auto it : scc) {
                    if (visited[it] == 0) {
                        can_be = false;
                    }
                    break;
                }
                if (not can_be)
                    break;
            }

            if (can_be) {
                for (auto it : scc) {
                    mybase.push_back(it);
                }
                break;
            }
        }
        for (auto it=mybase.begin(); it != mybase.end(); ++it) {
            if (it != mybase.begin()) printf(" ");
            printf("%d", *it);
        }
        printf("\n");
    }

    return 0;
}
