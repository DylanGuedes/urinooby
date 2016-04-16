#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int enemies[10010];
int refugees[10010];
set<int> adj[10010];
int inco[10010];
int n, m, s, source, destiny;
bool impossible;

void kahn()
{
    queue<int> Q;
    // vector<int> myv;

    for (int i=0; i < n; ++i) {
        if (inco[i] == 0) {
            Q.push(i);
            // myv.push_back(i);
        }
    }
    //
    // cout << "q inicial:" << endl;
    // for (auto it : myv) {
    //     cout << it << " ";
    // }
    // cout << endl;


    while (not Q.empty()) {
        int u = Q.front(); Q.pop();

        if (enemies[u] >= s) {
            impossible = true;
            break;
        }

        s += refugees[u];

        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            inco[*it] -= 1;

            if (inco[*it] == 0) {
                Q.push(*it);
            }

            adj[u].erase(*it);
        }
    }

    // cout << "LISTA:"  << endl;
    // for (auto it : L) {
    //     cout << it << " ";
    // }
    // cout << endl;

    for (int i=0; i < n; ++i) {
        if (not adj[i].empty()) {
            impossible = true;
        }
    }
}


int main()
{
    while (cin >> n >> m >> s) {
        if (not (n | m | s)) {
            return 0;
        }

        impossible = false;

        for (int i=0; i < n; ++i) {
            adj[i].clear();
        }

        for (int i=0; i < n; ++i) {
            cin >> enemies[i];
        }

        for (int i=0; i < n; ++i) {
            cin >> refugees[i];
        }

        memset(inco, 0, sizeof inco);

        for (int i=0; i < m; ++i) {
            cin >> source;
            cin >> destiny;

            source--;
            destiny--;

            adj[source].insert(destiny);
            // cout << "push de " << source << " para " << destiny << endl;
            inco[destiny]++;
        }

        kahn();
    // cout << "Lista:" << endl;
    // for (auto it : L) {
    //     cout << it << " ";
    // }
    // cout << endl;



        if (impossible)
            cout << "impossivel" << endl;
        else
            cout << "possivel" << endl;

    }
    return 0;
}
