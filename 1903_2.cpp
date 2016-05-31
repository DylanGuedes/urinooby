#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool bolada;
vector<int> n_graph[100010];
vector<int> inv_graph[100010];
int visited[100010];
bool correct[100010];

void dfs(int idx)
{
    visited[idx] = 1;
    for (auto it : n_graph[idx]) {
        correct[it] = true;
        if (visited[it] == 0)
            dfs(it);
    }
}

void dfs2(int idx)
{
    visited[idx] = 1;
    for (auto it : inv_graph[idx]) {
        correct[it] = true;
        if (visited[it] == 0)
            dfs2(it);
    }
}

int main()
{
    int n, m, v, u;
    cin >> n >> m;
    for (int i=0; i < m; ++i) {
        cin >> u >> v;
        n_graph[u-1].push_back(v-1);
        inv_graph[v-1].push_back(u-1); 
    }

    bolada = true;

    memset(correct, false, sizeof correct);
    memset(visited, 0, sizeof visited);
    dfs(0);
    memset(visited, 0, sizeof visited);
    dfs2(0);

    for (int i=0; i < n; ++i) {
        if (correct[i] == false) {
            bolada = false; 
            break;
        }
    }

    if (bolada)
        printf("Bolada\n");
    else
        printf("Nao Bolada\n");
    return 0;
}
