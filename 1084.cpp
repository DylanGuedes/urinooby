#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    int n, d;
    string num;
    int resp = 0;
    vector<int> appear{0,0,0,0,0,0,0,0,0,0};
    while (cin >> n >> d) {
        if (not(n|d))
            return 0;
        cin >> num;
        int stringsize = num.size();
        char limiar;
        FOR(i, 0, stringsize) {
            appear[num[i]-48]+=1;
        }
        int total = 0;
        FOR(i, 0, 10) {
            total+=appear[i];
            if (total>=d) {
                limiar = i+48;
                break;
            }
        }
        cout << "limiar: " << limiar << "\n";

        string analyze;
        FOR(i, 0, stringsize) {
            if (num[i]>=limiar)
                analyze.push_back(num[i]);
        }
        cout << "analyze: " << analyze<< "\n";

        int analyze_size = analyze.size();
        for (int i=0; i < analyze_size; ++i) {
            istringstream iss;
            string mystring;
            for (int j=0; j < d; j++) {
                mystring.push_back(analyze[i+j]);
            }
            iss.str(mystring);
            int val = 0;
            iss >> val;
            printf("val: %d\n", val);
            resp = max(resp, val);
        }
        printf("%d\n", resp);
    }
    return 0;
}
