#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


struct edge
{
    int x;
    int y;
    int z;
};

edge arr[200050];
int father[200050];
int ranks[200050];

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

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
    if (rootx == rooty)
        return;

    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = rootx;
    } else {
        ranks[rooty]++;
        father[rootx] = rooty;
    }
}


int main()
{
    int n, m;
    while (cin >> n >> m) {
        if (n == m && m == 0)
            return 0;

        int total = 0;
        for (int i=0; i < m; ++i) {
            cin >> arr[i].x >> arr[i].y >> arr[i].z;
            total += arr[i].z;
        }
        int sum = 0;

        for (int i=0; i < n; ++i) {
            father[i] = i;
        }
        memset(ranks, 0, sizeof ranks);

        sort(arr, arr+m, myfunc);
        for (int i=0; i < m; ++i) {
            if (union_find(arr[i].x) != union_find(arr[i].y)) {
                make_union(arr[i].x, arr[i].y);
                sum += arr[i].z;
            }
        }
        cout << total-sum << endl;
    }

    return 0;
}

