#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define ii pair<int, int>
int visiteds[100010];
vector<int> forbidden;

int bfs(int o, int d)
{
  queue<ii> myq;
  myq.push(pair<int, int>(o, 0));

  while (not myq.empty()) {
    int x = myq.front().first;
    int y = myq.front().second;

    myq.pop();

    if (x == d) {
      return y;
    }

    vector<int> myv {x+1, x-1, x*2, x*3};

    if ((x & 1) == 0 && x != 0) {
      myv.push_back(x/2);
    }

    int mylength = myv.size();
    for (int i=0; i < mylength; ++i) {
      if (myv[i] <= 100000 && myv[i] >= 1) {
        if (visiteds[myv[i]] == 0) {
          if (find(forbidden.begin(), forbidden.end(), myv[i]) == forbidden.end()) {
            myq.push(pair<int, int>(myv[i], y+1));
            visiteds[myv[i]] = 1;
          }
        }
      }
    }
  }

  return -1;
}

int main()
{
  int o, d, k;
  int myaux;
  while (cin >> o >> d >> k) {
    if (o == 0 && d == 0 && k == 0) return 0;
    forbidden.clear();
    memset(visiteds, 0, sizeof visiteds);
    for (int i=0; i < k; ++i) {
      cin >> myaux;
      forbidden.push_back(myaux);
    }
    cout << bfs(o, d) << endl;
  }
  return 0;
}
