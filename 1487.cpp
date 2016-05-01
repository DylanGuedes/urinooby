#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define ii pair<int, int>
vector<ii> myv;
int n;

bool myfunc(ii a1, ii a2)
{
  return a1.first < a2.first;
}

int bfs(int t)
{
  queue<ii> myq;
  myq.push(make_pair(t, 0));
  int greatest = 0;

  while (not myq.empty()) {
    int v1 = myq.front().first;
    int v2 = myq.front().second;

    // cout << "v1: " << v1 << ", v2:" << v2 << endl;

    myq.pop();

    greatest = max(greatest, v2);

    if (v1 <= 0) {
      // cout << "Continue aqui" << endl;
      continue;
    }

    for (int i=0; i < n; ++i) {
      if ((v1 - myv[i].first) >= 0) {
        myq.push(make_pair(v1 - myv[i].first, v2+myv[i].second));
      }
    }
  }

  return greatest;
}

int main()
{
  int t;
  int v1, v2;
  int counter = 0;

  while(cin >> n >> t) {
    if (not (n | t)) return 0;
    if (counter != 0) cout << "\n";
    cout << "Instancia " << counter+1 << endl;
    myv.clear();
    for (int i=0; i < n; ++i) {
      cin >> v1 >> v2;
      myv.push_back(ii(v1, v2));
    }

    cout << bfs(t) << endl;
    ++counter;
  }
  return 0;
}
