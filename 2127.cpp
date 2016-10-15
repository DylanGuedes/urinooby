#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int parent[1010];
int ranks[1010];

struct edge {
        int x;
        int y;
        int z;
};

vector<edge> edges;
int n, m;

bool myfunc(edge e1, edge e2)
{
        return e1.z < e2.z;
}

int union_find(int x)
{
        if (x == parent[x])
                return x;
        else
                return parent[x] = union_find(parent[x]);
}

void make_union(int x, int y)
{
        int rootx = union_find(x);
        int rooty = union_find(y);
        if (ranks[rootx] >= ranks[rooty]) {
                ranks[rootx]+=1;
                parent[rooty] = rootx;
        } else {
                ranks[rooty]+=1;
                parent[rootx] = rooty;
        }
}

int main()
{
        int counter = 0;
        while (scanf("%d%d", &n, &m) != EOF) {
                edges.clear();
                edge e;
                FOR(i, 0, m) {
                        scanf("%d%d%d", &e.x, &e.y, &e.z);
                        edges.push_back(e);
                }
                sort(edges.begin(), edges.end(), myfunc);
                memset(ranks, 0, sizeof ranks);
                FOR(i, 0, n+2)
                        parent[i] = i;
                int edges_size = edges.size();
                long long int total = 0;
                int unions_done = 0;
                FOR(i, 0, edges_size) {
                        if (union_find(edges[i].x) != union_find(edges[i].y)) {
                                make_union(edges[i].x, edges[i].y);
                                total += edges[i].z;
                                unions_done++;
                                if (unions_done >= n-1)
                                        break;
                        }
                }
                printf("Instancia %d\n", counter+1);
                printf("%lld\n", total);
                printf("\n");
                counter++;
        }
        return 0;
}
