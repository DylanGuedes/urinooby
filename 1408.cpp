#include <iostream>
#include <cstring>

using namespace std;

bool disponivel[100000];

int solve(int idx)
{
    int ans = solve(idx+1);
    if (disponivel[idx] == false) {
        ans = min(ans, solve(idx+1) + 1);
    }
}

int main()
{
    int aux;
    int n, l;
    while (cin >> n >> l) {
        if (not (n|l)) return 0;
        memset(disponivel, false, sizeof disponivel);
        FOR(i, 0, l) {
            cin >> aux;
            disponivel[aux-1] = true;
        }

    }
    return 0;
}
