#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll GCDsimp (ll num, ll den) {
        if (den > 0)
                return GCDsimp (den, num % den);
        return num;
}

int main() {
        ios::sync_with_stdio(false);
        ll num, den;
        stack<ll> mys;
        while (cin >> num >> den) {
                ll sol = GCDsimp (num,den);

                if  ( sol > 5)
                        cout << "Noel\n" ;
                else
                        cout << "Gnomos\n";
                mys.push(sol);
        }
        while (not mys.empty()) {
                cout << mys.top() << " ";
                mys.pop();
        }
        cout << "\n";
        return 0;
}
