#include <iostream>
#include <map>

using namespace std;

#define psi pair<string, int>
map <psi > mymap;


int main()
{
    int t;
    int g;
    string name;

    while (cin >> t) {
        if (t == 0) return 0;
        mymap.clear();

        int results[22][22];

        for (int w=0 ;w < t; ++w) {
            cin >> name;
            mymap.insert(psi(name, w));
        }

        cin >> g;

        memset(results, -1, sizeof results);

        for (int i=0; i < g; ++i) {
            cin >> t1;
            cin >> t2;
            cin >> gols1;
            cin >> gols2;
            results[mymap[t1]][mymap[t2]] = gols1;
            results[mymap[t2]][myma[t1]] = gols2;
        }

        for (int i=0; i < w; ++i) {
            solve_for_best(i);
            best[i] = solve_for_best(i);
        }
    }

    return 0;
}
