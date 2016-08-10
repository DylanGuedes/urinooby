#include <iostream>
#include <vector>
#include <cstring>

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define ii pair<int, int>

using namespace std;

bool visited[6][6];
int grid[6][6];

void dfs(int x, int y)
{
    visited[y][x] = true;
    vector<ii> myv {make_pair(x, y+1), make_pair(x+1, y), make_pair(x-1, y), make_pair(x, y-1) };
    for (auto it : myv) {
        if (it.first >= 0 && it.second >= 0 && it.first < 5 && it.second < 5) {
            if (grid[it.second][it.first] == 0) {
                if (visited[it.second][it.first] == false)
                    dfs(it.first, it.second);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        FOR(i, 0, 5) {
            FOR(j, 0, 5) {
                scanf("%d", &grid[i][j]);
            }
        }

        memset(visited, false, sizeof visited);

        dfs(0, 0);
        if (visited[4][4] == true)
            printf("COPS\n");
        else
            printf("ROBBERS\n");
    }
    return 0;
}
