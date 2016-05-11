#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

#define ii pair<int, int>

string arr[105];
vector<int> state[105][105];

#define KEY_A 0x000001
#define KEY_B 0x000002
#define KEY_C 0x000004
#define KEY_D 0x000008
#define KEY_E 0x000010
#define KEY_F 0x000020
#define KEY_G 0x000040

bool node_has(pair<int, int> pos, int node_state) {
    bool has = false;
    for (auto it : state[pos.first][pos.second]) {
        if (it == node_state) {
            has = true;
            break;
        }
    }
    return has;
}

int main()
{
    string mystring;
    int idx = 0;
    ii origin;
    ii destiny;

    while (getline(cin, mystring)) {
        arr[idx] = mystring;
        ++idx;
    }

    int rows = idx;
    int columns = arr[0].size();

    for (int i=0; i < rows; ++i) {
        for (int j=0; j < columns; ++j) {
            state[i][j].clear();
            if (arr[i][j] == '@') {
                origin = ii(i, j);
            } else if (arr[i][j] == '*') {
                destiny = ii(i, j);
            }
        }
    }

    int init_state = 0x000000;;
    queue< pair<int, pair<ii, int> > > myq;
    myq.push(make_pair(0, make_pair(origin, init_state)));
    state[origin.first][origin.second].push_back(init_state);

    int ans = 0;

    while (not myq.empty()) {
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < columns; ++j) {
                printf(" %d ", state[i][j].size());
            }
            cout << endl;
        }
        auto node = myq.front(); myq.pop();
        int node_dist = node.first;
        ii pos = node.second.first;
        int mystate = node.second.second;
        // printf("pos[%d][%d], state[%d] => %d\n", pos.first, pos.second, mystate, node_dist);

        if (arr[pos.first][pos.second] >= 97 && arr[pos.first][pos.second] < 104) {
            cout << "no array" << endl;
            int res = pow(2, arr[pos.first][pos.second] - 97);
            mystate = mystate | res;
        }

        if (arr[pos.first][pos.second] == '*') {
            cout << "resposta" << endl;
            ans = node_dist; break; 
        }

        vector<ii> myv { ii(pos.first, pos.second+1), ii(pos.first+1, pos.second), ii(pos.first, pos.second-1), ii(pos.first-1, pos.second) };
        for (auto it : myv) {
            printf("[%d][%d]\n", it.first, it.second);
            if (it.first >= 0 && it.second >= 0 && it.first < columns && it.second < rows) {
                if (arr[it.first][it.second] != '#') {
                    if (arr[it.first][it.second] >= 65 && arr[it.first][it.second] < 72) {
                        if (pow(2, arr[it.first][it.second]-65) and mystate) {
                            printf("chave %c: contida no estado %d\n", arr[it.first][it.second], mystate);
                            if (not node_has(it, mystate)) {
                                state[it.first][it.second].push_back(mystate);
                                myq.push(make_pair(node_dist+1, make_pair(it, mystate)));
                            }
                        }
                    } else {
                        if (not node_has(it, mystate)) {
                            state[it.first][it.second].push_back(mystate);
                            myq.push(make_pair(node_dist+1, make_pair(it, mystate)));
                        }
                    }
                }
            } 
        }
    }

    cout << ans << endl;


    return 0;
}
