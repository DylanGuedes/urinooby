#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)


int main()
{
        ios::sync_with_stdio(false);
        int n, d;
        while (cin >> n >> d) {
                if (not(n|d))
                        return 0;
                string num;
                cin >> num;

                vector<char> mys;

                for (auto it : num) {
                        if (mys.empty()) {
                                mys.push_back(it);
                                continue;
                        } else {

                                while (d && (mys.back() < it) && not mys.empty()) {
                                        mys.pop_back();
                                        d--;
                                }

                                mys.push_back(it);
                        }
                }

                while (d && not mys.empty()) {
                        mys.pop_back();
                        d--;
                }

                for (auto it : mys)
                        cout << it;
                cout << "\n";
        }
        return 0;
}
