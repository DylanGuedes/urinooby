#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

bool possible;
vector<int> graph[110];
int color[110];

void dfs(int idx, int col)
{
    color[idx] = col;
    for (auto it : graph[idx]) {
        if (color[it] != -1) {
            if (color[it] == color[idx]) {
                possible = false;
                return;
            }
        } else {
            dfs(it, 1-col);
        }
    }
}

int main()
{
    int n, m, origin, destination;
    int counter=0;
    while (scanf("%d%d", &n, &m) != EOF) {
        possible = true;
        FOR(i, 0, n+2)
            graph[i].clear();
        FOR(i, 0, m) {
            scanf("%d%d", &origin, &destination);
            graph[origin-1].push_back(destination-1);
            graph[destination-1].push_back(origin-1);
        }
        memset(color, -1, sizeof color);
        FOR(i, 0, n) {
            if (color[i] == -1)
                dfs(i, 1);
            else
                continue;
        }
        printf("Instancia %d\n", counter+1);
        if (possible)
            printf("sim\n");
        else
            printf("nao\n");
        printf("\n");
        counter++;
    }
    return 0;
}
