#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define ii pair<int, int>
char arr[510][550];
int visited[510][510];
int dist[510][510];

int main()
{
    int n, m;
    pair<int, int> origin;
    pair<int, int> destiny;
    memset(visited, 0, sizeof visited);
    cin >> n >> m;
    for (int i=0; i < n; ++i) {
        for (int j=0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
                visited[i][j] = 1;
            if (arr[i][j] == 'H') {
                origin = ii(i, j);
            } else if (arr[i][j] == 'E') {
                destiny = ii(i, j);
            }
        }
    }

    for (int i=0; i < n+1; ++i) {
        for (int j=0; j < m+1; ++j) {
            dist[i][j] = 0xffffff;
        }
    }

    visited[origin.first][origin.second] = 1;
    dist[origin.first][origin.second] = 0;
    queue<ii> myq;
    myq.push(origin);
    while (not myq.empty()) {
        ii pos = myq.front();
        myq.pop();

        vector<ii> myv { ii(pos.first+1, pos.second), ii(pos.first-1, pos.second), ii(pos.first, pos.second+1), ii(pos.first, pos.second-1) };
        for (auto it : myv) {
            if (it.first >= 0 && it.second >= 0 && it.first < n && it.second < m) {
                if (arr[it.first][it.second] != 'H') {
                    if (visited[it.first][it.second] == 0) {
                        if (arr[it.first][it.second] != '.' && arr[it.first][it.second] != 'E') {
                            if (dist[it.first][it.second] > dist[pos.first][pos.second] + (arr[it.first][it.second]-48)) {
                                dist[it.first][it.second] = dist[pos.first][pos.second] + arr[it.first][it.second]-48;
                                myq.push(it);
                            } 
                        } else {
                            if (dist[it.first][it.second] > dist[pos.first][pos.second]) {
                                dist[it.first][it.second] = dist[pos.first][pos.second];
                                myq.push(it);
                            }
                        }
                    }
                }
            }
        }

    }

    if (dist[destiny.first][destiny.second] == 0xffffff) {
        cout << "ARTSKJID" << endl;
    } else {
        cout << dist[destiny.first][destiny.second] << endl;
    }
    return 0;
}
