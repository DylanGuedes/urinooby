#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define ii pair<long long int, long long int>
vector<ii> graph[100000];
vector<long long int> dist;
int n;

void dijkstra(int origin)
{
    dist.assign(n+3, 50009099009);
    dist[origin] = 0;

    priority_queue<long long int, vector<ii>, greater<ii> > mypq;
    mypq.push(make_pair(0, origin));
    while (not mypq.empty()) {
        int idx = mypq.top().second;
        long long int val = mypq.top().first;

        mypq.pop();

        for (auto it : graph[idx]) {
            if (dist[it.second] > val+it.first) {
                dist[it.second] = val+it.first;
                mypq.push(make_pair(dist[it.second], it.second));
            }
        }

    }

}

int main()
{
    long long int destination, origin, weight, q;
    while (cin >> n) {
        if (n == 0)
            return 0;

        dist.clear();
        FOR(i, 0, n+3) {
            graph[i].clear();
        }

        FOR(i, 1, n) {
            cin >> destination;
            cin >> weight;
            graph[i].push_back(make_pair(weight, destination));
            graph[destination].push_back(make_pair(weight, i));
        }

        cin >> q;
        vector<ii> questions;
        FOR(i, 0, q) {
            cin >> origin;
            cin >> destination;
            questions.push_back(make_pair(origin, destination));
        }

        for (auto it=questions.begin(); it != questions.end(); ++it) {
            if (it != questions.begin())
                printf(" ");
            dijkstra((*it).first);
            printf("%lld", dist[(*it).second]);
        }
        printf("\n");
    }
    return 0;
}
