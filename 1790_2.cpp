#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> graph[62];
int visited[62];
#define ii pair<int, int>
vector<ii> arts;

void bfs(int n)
{
    queue<int> myq;
    myq.push(0);

    while (not myq.empty()) {
        int aux = myq.front();
        myq.pop();
        visited[aux] = 1;
        for (auto it : graph[aux]) {
            if (it != -1) {
                if (visited[it] == 0) {
                    myq.push(it);
                }
            }
        }
    }
}

void connect(int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool has(int a, int b)
{
    for (auto it : arts) {
        if (it.first == a && it.second == b || it.first == b && it.second == a)
            return true;
    }
    return false;
}

int main()
{
    int c, p;
    int origin, destiny;

    while (cin >> c >> p) {
        for (int i=0; i < c; ++i) {
            graph[i].clear();
        }

        for (int i=0; i < p; ++i) {
            cin >> origin >> destiny;
            connect(origin-1, destiny-1);
        }

        arts.clear();

        for (int i=0; i < c; ++i) {
            for (auto &it : graph[i]) {
                memset(visited, 0, sizeof visited);
                int aux = it;
                // cout << "retirando de " << i << " para "<< it << endl;
                it = -1;
                bfs(c);
                it = aux;
                for (int j=0; j < c; ++j) {
                    if (visited[j] == 0) {
                        // cout << j << " nao foi visitado" << endl;
                        if (not has(i, it))
                            arts.push_back(ii(i, it));
                        break;
                    }
                }
            }
        }
        cout << arts.size() << endl;
    }

    return 0;
}
