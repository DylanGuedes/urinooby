#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

using ii = pair<int, int>;
using iii = pair<int, ii>;
int n;
int parent[110];
int ranks[110];
vector<ii> graph[110];

struct edge {
        int x, y, z;
};

vector<edge> edges;

int union_find(int x)
{
        if (x == parent[x])
                return x;
        else
                return union_find(parent[x]);
}

void make_union(int x, int y)
{
        int rootx = union_find(x);
        int rooty = union_find(y);
        if (ranks[rootx] >= ranks[rooty]) {
                ranks[rootx]++;
                parent[rooty] = rootx;
        } else {
                ranks[rooty]++;
                parent[rootx] = rooty;
        }
}

int bfs(int origin, int destination)
{
        queue<ii> myq;
        myq.emplace(0, origin);
        int visited[110];
        memset(visited, 0, sizeof visited);
        while (not myq.empty()) {
                int idx = myq.front().second;
                int w = myq.front().first;
                visited[idx] =1 ;
                cout << "idx: " << idx << ", w: " << w << "\n";

                if (idx == destination)
                        return w;
                myq.pop();
                for (auto it : graph[idx]) {
                        if (not visited[it.second]) {
                                visited[it.second] = 1;
                                myq.emplace(max(w, it.first), it.second);
                        }
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int m;
        int counter = 0;
        while (cin >> n >> m) {
                int origin, destination, weight;
                if(not(n|m))
                        return 0;

                edges.clear();

                edge e;
                repi(i, 0, m) {
                        cin >> e.x >> e.y >> e.z;
                        e.x -= 1;
                        e.y -= 1;
                        edges.push_back(e);
                }

                memset(ranks, 0, sizeof ranks);
                repi(i, 0, n)
                        parent[i] = i;

                repi(i, 0, n+2)
                        graph[i].clear();

                int edges_size = edges.size();

                repi(i, 0, edges_size) {
                        if (union_find(edges[i].x) != union_find(edges[i].y)) {
                                make_union(edges[i].x, edges[i].y);
                                int x= edges[i].x;
                                int y= edges[i].y;
                                int wei = edges[i].z;
                                graph[x].emplace_back(wei, y);
                                graph[y].emplace_back(wei, x);
                        }
                }

                int k;
                cin >> k;
                cout << "Instancia "<<counter+1<<"\n";
                repi(i, 0, k) {
                        cin >> origin >> destination;
                        cout << bfs(origin-1, destination-1) << "\n";
                }
                cout << "\n";
                counter++;
        }
        return 0;
}
