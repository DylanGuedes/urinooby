#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

struct edge {
        int x, y, z;
};

int parent[20];
int ranks[20];

vector<edge> edges;

int union_find(int x)
{
        if (parent[x] == x)
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

bool myfunc(edge e1, edge e2)
{
        return e1.z < e2.z;
}

bool myfunc2(edge e1, edge e2)
{
        return e1.z > e2.z;
}

using ll = long long;


int main()
{
        ios::sync_with_stdio(false);
        int t, n, m, k;
        int origin, destination, weight;
        cin >> t;
        while(t--) {
                cin >> n >> m >> k;
                FOR(i, 0, n+2)
                        edges.clear();

                edge e;

                FOR(i, 0, m) {
                        cin >> e.x >> e.y >> e.z;
                        edges.push_back(e);
                }

                sort(edges.begin(), edges.end(), myfunc);

                FOR(i, 0, n+2)
                        parent[i] = i;

                memset(ranks, 0, sizeof ranks);

                vector<edge> mst;
                int edges_size = edges.size();
                FOR(i, 0, edges_size) {
                        if (union_find(edges[i].x) != union_find(edges[i].y)) {
                                make_union(edges[i].x, edges[i].y);
                                mst.push_back(edges[i]);
                        }
                }
                int mst_size = mst.size();

                if (k < n-mst_size-1) {
                        cout << "-1\n";
                } else {
                        sort(mst.begin(), mst.end(), myfunc2);

                        ll total = 0;
                        FOR(i, 0, mst_size) {
                                if (k)
                                        k--;
                                else
                                        total += mst[i].z;
                        }
                        cout << total << "\n";
                }
        }
        return 0;
}
