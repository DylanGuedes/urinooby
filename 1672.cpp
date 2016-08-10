#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int solve(long long int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    if (num&1) {
        return 2*solve(num/2)+1;
    } else {
        return 2*solve(num/2)-1;
    }
}

int main()
{
    int inicio, zeros;
    char letra;
    while (cin >> inicio >> letra >> zeros) {
        long long int res = inicio*pow(10, zeros);
        if (not res)
            return 0;
        cout << solve(res) << endl;
    }
    return 0;
}
