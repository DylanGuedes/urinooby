#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int qa, qm;
int qc;
map<string, double> guns;
map<string, int> monsters;
pair<string, int> armas[10];
pair<string, int> monstro[10];
int dp[8][10001][5005];

int solve(int idx, int remaining, int hp)
{
    if (hp <= 0)
        return 1;
    if (idx == qa)
        return 0;
    if (remaining < 0)
        return 0;
    if (dp[idx][remaining][hp] != -1)
        return dp[idx][remaining][hp];
    int ans = solve(idx+1, remaining, hp);
    if (remaining>=armas[idx].second) {
        ans = max(ans, solve(idx+1, remaining - armas[idx].second, hp-guns[armas[idx].first]*armas[idx].second));
    }
    return dp[idx][remaining][hp] = ans;
}

int main()
{
    guns.emplace("HANDGUN", 2.0);
    guns.emplace("RED9", 3.5);
    guns.emplace("BLACKTAIL", 3.5);
    guns.emplace("MATILDA", 2);
    guns.emplace("HANDCANNON", 60);
    guns.emplace("STRIKER", 12);
    guns.emplace("TMP", 1.2);
    guns.emplace("RIFLE", 12.0);

    monsters.emplace("GANADOS", 50);
    monsters.emplace("COBRAS", 40);
    monsters.emplace("ZEALOT", 75);
    monsters.emplace("COLMILLOS", 60);
    monsters.emplace("GARRADOR", 125);
    monsters.emplace("LASPLAGAS", 100);
    monsters.emplace("GATLINGMAN", 150);
    monsters.emplace("REGENERATOR", 250);
    monsters.emplace("ELGIGANTE", 500);
    monsters.emplace("DR.SALVADOR", 350);

    while (scanf("%d", &qa) != EOF) {
        int total = 0;
        FOR(i, 0, qa) {
            cin >> armas[i].first;
            scanf("%d", &armas[i].second);
        }
        memset(dp, -1, sizeof dp);
        scanf("%d", &qm);
        FOR(i, 0, qm) {
            cin >> monstro[i].first;
            scanf("%d", &monstro[i].second);
            total+=monsters[ monstro[i].first ]*monstro[i].second;
        }
        scanf("%d", &qc);
        printf("%d\n", solve(0, qc, total));
    }
    return 0;
}
