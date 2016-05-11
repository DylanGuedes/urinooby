#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int m;
int power[80];
int weight[80];
int dp[80][80];

int knapsack(int idx, int val, int remaining)
{
    if (remaining <= 0)
        return val;

    if (idx < 0)
        return val;

    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];

    // printf("knapsack(%d, %d, %d)\n", idx, val, remaining);
    int ans = -1;

    // printf("weight[%d] => %d\n", idx, weight[idx]);
    if (remaining-weight[idx] >= 0) {
        ans = max(knapsack(idx-1, val+power[idx], remaining-weight[idx]), knapsack(idx-1, val, remaining));
    } else {
        ans = knapsack(idx-1, val, remaining);
    }

    dp[idx][remaining] = ans;

    return ans;
}

int main()
{
    int t;
    int resistence, max_weight;
    cin >> t;
    while (t--) {
        cin >> m;
        for (int i=0; i < m; ++i) {
            cin >> power[i] >> weight[i];
        }

        cin >> max_weight;
        cin >> resistence;
        memset(dp, -1, sizeof dp);

        if (knapsack(m-1, 0, max_weight) >= resistence) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    
    }
    return 0;
}
