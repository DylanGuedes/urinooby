#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define ii pair<int, int>
vector<ii> graph[550];
int friends[550][550];

void dijkstra(int origin, int destiny, int n)
{
    priority_queue<ii, vector<ii>, greater<ii> > mypq; 
    mypq.push(ii(origin, 0));

    vector<int> dist(n+1, 0xffffff);
    dist[origin] = 0;

    while (not mypq.empty()) {
        ii front = mypq.top(); mypq.pop();
        int distance = front.second, idx = front.first;
        for (auto node : graph[idx]) {
            if (friends[idx][node.first] == 1 && friends[node.first][idx] == 1) {
                if (dist[node.first] > dist[idx]) {
                    dist[node.first] = dist[idx];
                    mypq.push(ii(node.first, dist[node.first]));
                }
            } else {
                if (dist[node.first] > dist[idx] + node.second) {
                    dist[node.first] = dist[idx] + node.second;
                    mypq.push(ii(node.first, dist[node.first]));
                }
            }
        }
    }
    //
    // cout << "dist:"<<endl;
    // for (int i=0; i < n; ++i) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;

    if (dist[destiny] >= 0xffffff) {
        cout << "Nao e possivel entregar a carta" << endl;
    } else {
        cout << dist[destiny]<< endl;
    }

}

int main()
{
    int n, e;
    int origin, destiny, weight;
    int queries;
    int counter = 0;

    while (cin >> n >> e) {
        if (not (n | e))
            return 0;

        if (counter)
            cout << endl;
        memset(friends, 0, sizeof friends);

        for (int i=0; i < n+1; ++i) {
            graph[i].clear();
        }

        for (int i=0; i < e; ++i) {
            cin >> origin >> destiny >> weight;
            graph[origin-1].push_back(ii(destiny-1, weight));
            friends[origin-1][destiny-1] = 1;
        }

        cin >> queries;
        for (int i=0; i < queries; ++i) {
            cin >> origin >> destiny;
            dijkstra(origin-1, destiny-1, n);
        }
        ++counter;
    }
    return 0;
}
