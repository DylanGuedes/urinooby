#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int visited[10010];
vector<int> friends[10010];
int n;
int dist[10010];

void connect(int a1, int a2)
{
    friends[a1].push_back(a2);
    friends[a2].push_back(a1);
}

int bfs(int start, int destiny)
{
    queue< int > myq;
    myq.push(start);
    dist[start] = 0;

    visited[start] = 1;

    while (not myq.empty()) {
        int aux = myq.front();
        myq.pop();
        if (dist[destiny] != -1) {
            return dist[destiny];
        }

        for (auto it : friends[aux]) {
            if (dist[it] == -1) {
                dist[it] = dist[aux] + 1;
                myq.push(it);
            }
        }
    }
}
//
// void print_grid(int n)
// {
//   for (int i=0; i < n; ++i) {
//     if (not friends[i].empty()) {
//       for (auto it : friends[i]) {
//         cout << it << " ";
//       }
//       cout << "\n";
//     } else {
//       cout << "/0" << endl;
//     }
//   }
//   cout << "\n";
// }
//
int main()
{
    int k;
    int auxI;
    int l;

    memset(dist, -1, sizeof dist);

    memset(visited, 0, sizeof visited);

    printf("%d%d", &n, &k);
    vector<int> myv;

    for (int i=0; i < k; ++i) {
        scanf("%d", &l);
        myv.clear();

        for (int w=0; w < l; ++w) {
            scanf("%d", &auxI);
            myv.push_back(auxI-1);
        }

        for (int w=0; w < l; ++w) {
            for (int w2=w; w2 < l; ++w2) {
                if (w != w2) {
                    friends[myv[w]].push_back(myv[w2]);
                    friends[myv[w2]].push_back(myv[w]);
                }
            }
        }
    }

    dist[0] = 0;

    int ans = 0;
    ans = bfs(0, n-1);
    // cout << "0 até " << n-1 << endl;
    cout << ans << endl;
    return 0;
}
