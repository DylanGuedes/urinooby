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

int father[50110];
int ranks[50110];
edge arr[50110];

int union_find(int x)
{
    if (father[x] == x)
        return x;
    else
        return union_find(father[x]);
}

void make_union(int n1, int n2)
{
    int rootx = union_find(n1);
    int rooty = union_find(n2);
    if (ranks[n1] >= ranks[n2]) {
        father[rooty] = father[rootx];
        ranks[rootx]++;
    } else {
        father[rootx] = father[rooty];
        ranks[rooty]++;
    }
}

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int main(int argc, char *argv[])
{
    int n, m;
    while (cin >> n >> m) {
        if (not(n | m))
            return 0;

        for (int i=0; i < m; ++i) {
            cin >> arr[i].x >> arr[i].y >> arr[i].z;
        }

        sort(arr, arr+m, myfunc);
        memset(ranks, 0, sizeof ranks);
        for (int i=0; i < m+1; ++i) {
            father[i] = i;
        }

        int total = 0;

        for (int i=0; i < m; ++i) {
            if (union_find(arr[i].x) != union_find(arr[i].y)) {
                make_union(arr[i].x, arr[i].y);
                total += arr[i].z;
            }

        }
        cout << total << endl;
    }
    return 0;
}
