#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define FOR(i, j, k) for(int i=j;i<k;++i)

#define ii pair<int, int>
vector< pair<int, ii> > graph[110];
#define iii pair<int, ii>

void dijkstra(int origin, int destiny, int cost)
{
    vector<int> dist(110, 0xffffff);
    vector<int> tmp(110, 0xffffff);
    dist[origin] = 0;
    tmp[origin] = 0;
    priority_queue< iii, vector<iii >, less<iii > > mypq;
    mypq.push(make_pair(0, ii(0, origin)));
    while (not mypq.empty()) {
        int idx = mypq.top().second.second;
        int idx_dist = mypq.top().second.first;
        int idx_time = mypq.top().first;
        mypq.pop();
        for (auto it : graph[idx]) {
            int aggr_time = idx_time + it.first;
            if (aggr_time > cost)
                continue;
            if (dist[it.second.second] > idx_dist + it.second.first) {
                dist[it.second.second] = idx_dist + it.second.first;
                tmp[it.second.second] = it.first + idx_time;
                mypq.push(make_pair(tmp[it.second.second], ii(dist[it.second.second], it.second.second)));
            } else if (dist[it.second.second] == (idx_dist + it.second.first)) {
                tmp[it.second.second] = min(tmp[it.second.second], it.first + idx_time);
                mypq.push(make_pair(tmp[it.second.second], ii(dist[it.second.second], it.second.second)));
            }
        }
    }

    if (dist[destiny] != 0xffffff) {
        printf("Possivel - %d km, %d min\n", dist[destiny], tmp[destiny]);
    } else {
        printf("Impossivel\n");
    }
}

int main()
{
    int n, m, origin, destiny, distance, cost;
    int counter = 0;
    int k;
    while (cin >> n >> m) {
        if (not (n | m))
            return 0;

        FOR(i, 0, n+3) {
            graph[i].clear();
        }

        printf("Instancia %d\n", counter+1);

        FOR(i, 0, m) {
            scanf("%d%d%d%d", &origin, &destiny, &distance, &cost);
            // cin >> origin >> destiny >> distance >> cost;
            graph[origin].push_back(make_pair(cost, ii(distance, destiny)));
        }

        scanf("%d", &k);
        // cin >> k;
        FOR(i, 0, k) {
            scanf("%d%d%d", &origin, &destiny, &cost);
            // cin >> origin >> destiny >> cost;
            dijkstra(origin, destiny, cost);
        }
        printf("\n");
        counter++;
    }
    return 0;
}
