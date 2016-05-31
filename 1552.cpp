#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge
{
    int x;
    int y;
    double z;
};

#define ii pair<double, int>
#define dd pair<double, double>

int ranks[550];
int father[550];
vector<edge> arr;
pair<double, double> positions[550];
vector<ii> graph[550];

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

    cin >> m;
    while (m--) {
        memset(positions, 0, sizeof positions);
        cin >> n;
        arr.clear();

        for (int i=0; i < n; ++i) {
            graph[i].clear();
        }
        
        for (int w=0; w < n; ++w) {
            cin >> origin_x;
            cin >> origin_y;
            positions[w] = dd(origin_x, origin_y);
        }

        for (int i=0; i < n; ++i) {
            for (int j=i+1; j < n; ++j) {
                double euclid_x = positions[j].first - positions[i].first;
                double euclid_y = positions[j].second - positions[i].second;
                euclid_x = euclid_x * euclid_x;
                euclid_y = euclid_y * euclid_y;
                double result_euclid = (double)sqrt(euclid_x + euclid_y);
                arr.push_back( edge {i, j, result_euclid});
            }
        }

        sort(arr.begin(), arr.end(), myfunc);
        for (int i=0; i < n+1; ++i) {
            father[i] = i;
        }

        double total = 0;
        int mysize = arr.size();
        for (int i=0; i < mysize; ++i) {
            if (union_find(arr[i].x) != union_find(arr[i].y)) {
                make_union(arr[i].x, arr[i].y);
                total += arr[i].z;
            }
        }
        printf("%.2f\n", total/100);

    }
    return 0;
}
