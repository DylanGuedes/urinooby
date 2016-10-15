#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

vector<string> graph[40];
short dp[31][6][6][6][6][6][6];

int n, m;
vector<string> myidx {"XXL", "XL", "L", "M", "S", "XS"};
short solve(int idx, int values[6])
{
        // printf("idx: %d, values: {", idx);
        // FOR(i, 0, 6) {
        //         printf(" %d ", values[i]);
        // }
        // printf("}\n");

        if (idx == m)
                return 1;

        if (dp[idx][values[0]][values[1]][values[2]][values[3]][values[4]][values[5]] != -1) {
                return dp[idx][values[0]][values[1]][values[2]][values[3]][values[4]][values[5]];
        }

        short sol = 0;
        for (auto it : graph[idx]) {
                FOR(i, 0, 6) {
                        if (it == myidx[i]) {
                                if (values[i] <= 0) {
                                        continue;
                                } else {
                                        values[i]-=1;
                                        sol = max(sol, solve(idx+1, values));
                                        values[i]+=1;
                                }
                        }
                }
        }

        return dp[idx][values[0]][values[1]][values[2]][values[3]][values[4]][values[5]] = sol;
}

int main()
{
        int t;
        string mys1, mys2;
        scanf("%d", &t);
        FOR(z, 0, t) {
                scanf("%d%d", &n, &m);

                FOR(i, 0, n+2)
                        graph[i].clear();

                FOR(i, 0, m) {
                        cin >> mys1 >> mys2;
                        graph[i].push_back(mys1);
                        graph[i].push_back(mys2);
                }

                memset(dp, -1, sizeof dp);
                int cam = n/6;
                int values[] = {cam, cam, cam, cam, cam, cam};
                short sol = solve(0, values);

                if (sol)
                        printf("YES\n");
                else
                        printf("NO\n");
        }
        return 0;
}
