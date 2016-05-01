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

edge arr[250];
int ranks[250];
int father[250];

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
    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = father[rootx];
    } else {
        ranks[rooty]++;
        father[rootx] = father[rooty];
    }
}

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int main()
{
    int r, c;
    cin >> r >> c;
    for (int i=0; i < c; ++i) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    for (int i=0; i < c+1; ++i) {
        father[i] = i;
    }
    memset(ranks, 0, sizeof ranks);
    sort(arr, arr+c, myfunc);
    long long int total = 0;
    for (int i=0; i < c; ++i) {
        if (union_find(arr[i].x) != union_find(arr[i].y)) {
            make_union(arr[i].x, arr[i].y);
            total += arr[i].z;
        }
    }
    cout << total << endl;
    return 0;
}

