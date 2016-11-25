#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back

int parent[105];
vector<int> graph[105];
int residual[105][105];
int original_flow[105][105];
int visited[105];
int n, m;

int bfs(int s, int t)
{
        queue<int> myq;
        myq.push(s);
        memset(visited, 0, sizeof visited);
        visited[s]=1;
        while (not myq.empty()) {
                int idx = myq.front(); myq.pop();
                for (auto i : graph[idx]) {
                        if (!visited[i] && residual[idx][i]) {
                                visited[i]=1;
                                myq.push(i);
                                parent[i]=idx;
                        }
                }
        }
        return visited[t];
}

int karp(int s, int t)
{
        int maxflow=0;
        while (bfs(s, t)) {
                int residual_cost=1<<30;
                for (int idx=t; idx!=s; idx=parent[idx]) {
                        residual_cost=min(residual_cost, residual[parent[idx]][idx]);
                }
                maxflow+=residual_cost;
                for (int idx=t; idx!=s; idx=parent[idx]) {
                        residual[idx][parent[idx]]=residual_cost;
                        residual[parent[idx]][idx]=max(0, residual[parent[idx]][idx]-residual_cost);
                }
        }
        return maxflow;
}

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while (t--) {
                int origin, destination, weight;
                cin >> n >> m;
                rep(i, 0, n)
                        graph[i].clear();
                memset(original_flow, 0, sizeof original_flow);
                rep(i, 0, m) {
                        cin >> origin >> destination >> weight;
                        origin-=1;destination-=1;
                        graph[origin].pb(destination);
                        graph[destination].pb(origin);
                        original_flow[origin][destination]=original_flow[destination][origin]=weight;
                }

                int lowest=1<<30;
                rep(i, 1, n) {
                        memcpy(residual, original_flow, sizeof residual);
                        lowest=min(lowest, karp(i, 0));
                }
                cout << lowest << "\n";
        }
        return 0;
}
