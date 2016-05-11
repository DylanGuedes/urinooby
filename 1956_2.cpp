#include <iostream>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

#define ii pair<int, int>
priority_queue< pair<int, ii>, vector< pair<int, ii> >, greater< pair<int, ii> > > mypq;
int father[10050];
int ranks[10050];

void connect(int x, int y, int weight)
{
    mypq.push(make_pair(weight, ii(x, y)));
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
        father[rooty] = rootx;
        ranks[rootx]++;
    } else {
        father[rootx] = rooty;
        ranks[rooty]++;
    }
}

int main()
{
    int n;
    int m;
    int destiny, weight;
    cin >> n;
    for (int i=1; i < n; ++i) {
        cin >> m; 
        for (int w=0; w < m; ++w) {
            cin >> destiny;
            cin >> weight;
            connect(i, destiny, weight);
        }
    }

    memset(ranks, 0, sizeof ranks);
    for (int i=0; i < n+2; ++i) {
        father[i] = i;
    }

    long long int total = 0;
    while (not mypq.empty()) {
        int myweight = mypq.top().first;
        ii pos = mypq.top().second;
        mypq.pop();

        if (union_find(pos.first) != union_find(pos.second)) {
            make_union(pos.first, pos.second);
            total += myweight;
        }
    }

    set<int> myset;
    for (int i=1; i <= n; ++i) {
        myset.insert(union_find(i));
    }

    cout << myset.size() << " " << total << endl;
    return 0;
}
