#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

vector<int> graph[10005];
int instack[10005];
int visited[10005];
#define pb(i) push_back(i);

bool dfs(int idx)
{
        if (not *(visited+idx)) {
                *(visited+idx) = 1;
                *(instack+idx) = 1;
                bool ans = 0;
                for (auto it : *(graph+idx)) {
                        if (*(instack+it))
                                return true;
                        else {
                                ans = max(ans, dfs(it));
                        }
                }

                *(instack+idx) = false;
                return ans;
        }

        return false;
}

int main()
{
        ios::sync_with_stdio(false);
        int t, n, m, a, b;
        cin >> t;

        while(t--) {
                cin >> n >> m;
                FOR(i, 0, n+5)
                        (graph+i)->clear();

                FOR(i, 0, m) {
                        cin >> a >> b;
                        (graph+a-1)->pb(b-1);
                }

                memset(visited, false, sizeof visited);
                memset(instack, false, sizeof instack);

                bool ans = 0;
                FOR(i, 0, n) {
                        if (not *(visited+i)) {
                                ans = max(dfs(i), ans);
                        }
                }
                if (ans)
                        cout << "SIM\n";
                else
                        cout << "NAO\n";
        }

        return 0;
}
