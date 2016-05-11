#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge
{
    int x;
    int y;
    int z;
};

int ranks[550];
int father[550];
edge arr[550];
pair<double, double> positions[550];

int union_find(int x)
{
    if (father[x] == x)
        return x;
    else
        return union_find(father[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);

    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = rootx;
    } else {
        ranks[rooty]++;
        father[rootx] = rooty;
    }
}

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int main()
{
    int n, m;
    double origin_x, origin_y;

    while (cin >> n) {
        cin >> m;
        for (int w=0; w < m; ++w) {
            cin >> origin_x;
            cin >> origin_y;
            positions[w] = pair(dd(origin_x, origin_y));
        }
    }
    return 0;
}
