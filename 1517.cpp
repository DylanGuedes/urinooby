#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define ii pair<int, int>

int x[1005];
int y[1005];
int t[1005];
int dp[1005][22][22];

int main()
{
    int n, m, k, x_pos, y_pos;
    while (cin >> n >> m >> k) {
        if (not(n|m|k))
            return 0;

        FOR(i, 0, k) {
            scanf("%d", &x[i]);
            scanf("%d", &y[i]);
            scanf("%d", &t[i]);
            x[i] -= 1;
            y[i] -= 1;
        }

        scanf("%d", &x_pos);
        scanf("%d", &y_pos);
        memset(dp, 0, sizeof dp);

        // as maças estao em tempo crescente
        // caso base eh que no ultimo tempo (que no caso é t[k-1])
        // a resposta é 1 se ha uma maçã em x, y com tempo t[i],
        // ou 0 se nao tiver maçã lá
        for (int i=k-1; i>=0; i--) {
            if (t[i] != t[k-1]) {
                break;
            } else {
                dp[t[i]][x[i]][y[i]] = 1;
            }
        }

        for (int idx=(t[k-1]-1); idx>=0; idx--) {
            FOR(linha, 0, n) {
                FOR(coluna, 0, m) {
                    vector<ii> myv { make_pair(linha+1, coluna), make_pair(linha+1, coluna-1), make_pair(linha+1, coluna+1),
                        make_pair(linha-1, coluna), make_pair(linha-1, coluna+1), make_pair(linha-1, coluna-1),
                        make_pair(linha, coluna), make_pair(linha, coluna+1), make_pair(linha, coluna-1) };

                    int sol = 0;
                    for (auto pos : myv) {
                        if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m)
                            continue;
                        sol = max(sol, dp[idx+1][pos.first][pos.second]);
                    }

                    for (int maca=k-1; maca >= 0; maca--) {
                        if (x[maca] == linha && y[maca] == coluna && t[maca] == idx) {
                            sol += 1;
                            break;
                        }
                        if (t[maca] < idx)
                            break;
                    }
                    dp[idx][linha][coluna] = sol;
                }
            }
        }

        printf("%d\n", dp[0][x_pos-1][y_pos-1]);
    }
    return 0;
}
