#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <set>
#include <cstring>

using namespace std;

using ii = pair<int, int>;
string grid[105];
bool visited[105][105][130];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    ii origin, destination;
    int ptr = 0;
    memset(visited, false, sizeof visited);
    bitset<8> init_state;
    queue< pair<int, pair<ii, bitset<8> > > > myq;

    while (cin >> grid[ptr]) ptr++;

    int rows = ptr, columns = grid[0].size();

    FOR(i, 0, rows) {
        FOR(j, 0, columns) {
            if (grid[i][j] == '@')
                origin = ii(j, i);
            else if (grid[i][j] == '*')
                destination = ii(j, i);
        }
    }

    myq.push(make_pair(0, make_pair(origin, init_state)));
    visited[origin.second][origin.first][0] = 1;

    int ans = 0;
    set<char> doors {'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    set<char> keys {'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    while (not myq.empty()) {
        auto node = myq.front(); myq.pop();
        int val = node.first;
        ii pos = node.second.first;
        bitset<8> state = node.second.second;
        char ele = grid[pos.second][pos.first];

        if (pos == destination) {
            ans = val;
            break;
        }

        vector<ii> myv { ii(pos.first, pos.second+1), ii(pos.first+1, pos.second), ii(pos.first, pos.second-1), ii(pos.first-1, pos.second) };

        for (auto it : myv) {
            if (it.first >= 0 && it.second >= 0 && it.first < columns && it.second < rows) {
                char it_ele = grid[it.second][it.first];
                if (it_ele == '#')
                    continue;

                if (visited[it.second][it.first][state.to_ulong()]) {
                    continue;
                }

                if (doors.count(it_ele) > 0) {
                    if (not state[it_ele-65])
                        continue;
                }

                visited[it.second][it.first][state.to_ulong()]=1;
                if (keys.count(it_ele) > 0) {
                    if (state[it_ele-97])
                        myq.push(make_pair(val+1, make_pair(it, state)));
                    else {
                        state.set(it_ele-97);
                        myq.push(make_pair(val+1, make_pair(it, state)));
                        state[it_ele-97] = 0;
                    }
                } else
                    myq.push(make_pair(val+1, make_pair(it, state)));
            }
        }
    }

    if (ans == 0)
        printf("--\n");
    else
        cout << ans << "\n";

    return 0;
}
