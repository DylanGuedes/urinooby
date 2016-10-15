#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
int D, I, B;

struct ingrediente {
        int qtd, idx;
};
int cost[110];

int total_bolo[110];
using ll = long long;

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        while(t--) {
                cin >> D >> I >> B;
                repi(i, 0, I) {
                        cin >> cost[i];
                }

                ingrediente l;
                memset(total_bolo, 0, sizeof total_bolo);

                repi(i, 0, B) {
                        int qi;
                        cin >> qi;
                        repi(j, 0, qi) {
                                cin >> l.idx >> l.qtd;
                                total_bolo[i] += cost[l.idx]*l.qtd;
                        }
                }

                sort(total_bolo, total_bolo+B);
                cout << D/total_bolo[0] << "\n";
        }

        return 0;
}
