#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

vector<int> graph[10020];
bool visited[10020];
bool impossible;
set<int> mys;

void dfs(int idx)
{
    if (mys.count(idx) > 0) {
        impossible = true;
        return;
    }

    visited[idx] = true;
    for (auto it : graph[idx]) {
        if (visited[it] == false) {
            dfs(it);
        } else {
            impossible = true;
            return;
        }
    }
    mys.insert(idx);
}

int main()
{
    int t, n, m, a, b;
    scanf("%d", &t);
    FOR(z, 0, t) {
        impossible = false;
        scanf("%d", &n);
        scanf("%d", &m);
        mys.clear();
        FOR(i, 0, n+2) {
            graph[i].clear();
        }

        FOR(i, 0, m) {
            scanf("%d", &a);
            scanf("%d", &b);
            graph[a].push_back(b);
        }

        memset(visited, false, sizeof visited);
        FOR(i, 1, m+1) {
            if (impossible) {
                break;
            }
            if (visited[i] == false) {
                dfs(i);
            }
        }

        if (impossible)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
    return 0;
}
