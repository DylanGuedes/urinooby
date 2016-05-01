#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    string mys;
    set<char> myset;
    int total = 0;
    int best_ans = 0;
    int m;
    char myc;

    while (cin >> m) {
        if (m == 0) return 0;
        best_ans = 0;

        getline(cin, mys);
        getline(cin, mys);

        int mysize = mys.size();
        for (int i=0; i < mysize; ++i) {
            total = 0;
            myset.clear();

            for (int j=i; j < (mysize-m); ++j) {
                // cout << "insert em " << mys[j] << endl;
                if (myset.size() < m) {
                    myset.insert(mys[j]);
                } else {
                    if (myset.find(mys[j]) == myset.end())
                        break;
                }
                total += 1;
            }

            best_ans = max(total, best_ans);
        }
        printf("%d\n", best_ans);
    }
    return 0;
}
