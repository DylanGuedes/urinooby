#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define ii pair<int, int>
char arr[510][550];
int visited[510][510];

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

    queue< pair<ii, int> > myq;
    myq.push(make_pair(origin, 0)); 
    visited[origin.first][origin.second] = 1;

    int result = 0xffffff;

    while (not myq.empty()) {
        ii pos = myq.front().first;
        int energy = myq.front().second;
        myq.pop();

        // printf("pos[%d][%d] => %d\n", pos.first, pos.second, energy);
        
        visited[pos.first][pos.second] = 1;

        if (pos == destiny) {
            result = min(result, energy);
        }

        vector<ii> myv { ii(pos.first+1, pos.second), ii(pos.first-1, pos.second), ii(pos.first, pos.second+1), ii(pos.first, pos.second-1) };
        for (auto it : myv) {
            if (it.first >= 0 && it.second >= 0 && it.first < n && it.second < m) {
                if (arr[it.first][it.second] != 'H') {
                    if (visited[it.first][it.second] == 0) {
                        if (arr[it.first][it.second] != '.' && arr[it.first][it.second] != 'E') {
                            myq.push(make_pair(ii(it.first, it.second), energy + (arr[it.first][it.second]-48)));
                        } else {
                            myq.push(make_pair(ii(it.first, it.second), energy));
                        }
                    }
                }
            }
        }
    }

    if (result == 0xffffff) {
        cout << "ARTSKJID" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
