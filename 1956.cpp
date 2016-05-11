#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge
{
    int x;
    int y;
    int z;
};

edge arr[10050];
int father[10050];
int ranks[10050];

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

    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = father[rootx];
    } else {
        ranks[rooty]++;
        father[rootx] = father[rooty];
    }
}

int main()
{
    int n;
    int destiny, weight;
    int num;
    cin >> n;
    int counter = 0;

    for (int w=0; w < n-1; ++w) {
        cin >> num;
        for (int i=0; i < num; ++i) {
            cin >> destiny;
            cin >> weight;
            arr[counter].x = w;
            arr[counter].y = destiny-1;
            arr[counter].z = weight;
            ++counter;
        }
    }

    memset(ranks, 0, sizeof ranks);
    for (int i=0; i < n+1; ++i) {
        father[i] = i;
    }

    sort(arr, arr+counter+1, myfunc);

    long long int total = 0;
    for (int i=0; i < counter; ++i) {
        if (union_find(arr[i].x) != union_find(arr[i].y)) {
            make_union(arr[i].x, arr[i].y);
            total += arr[i].z;
        }
    }

    set<int> myset;
    for (int i=0; i < n; ++i) {
       myset.insert(union_find(i)); 
    }

    cout << myset.size() << " " << total << endl;
    return 0;
}
