#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int visited[10010];
vector<int> friends[10010];
int n;

bool friend_of(int a, int b)
{
  if (find(friends[a].begin(), friends[a].end(), b) != friends[a].end()) {
    return true;
  } else {
    return false;
  }
}

void connect(int a1, int a2)
{
  friends[a1].push_back(a2);
  friends[a2].push_back(a1);

  for (auto it : friends[a1]) {
    if (friend_of(a2, it) == false) {
      connect(a2, it);
    }
  }

  for (auto it : friends[a2]) {
    if (friend_of(a1, it) == false) {
      connect(a1, it);
    }
  }
}

int bfs(int start, int destiny)
{
  queue< pair<int, int> > myq;
  myq.push(pair<int, int>(start, 0));

  visited[start] = 1;

  while (not myq.empty()) {
    int v1 = myq.front().first;
    int v2 = myq.front().second;
    // cout << "v2: " << v2 << endl;

    myq.pop();

    visited[v1] = 1;

    if (v1 == destiny) {
      // cout << "v1 == destiny" << endl;
      return v2;
    }

    for (auto it : friends[v1]) {
      if (visited[it] == 0) {
        myq.push(pair<int, int>(it, v2+1));
      }
    }
  }
}
//
// void print_grid(int n)
// {
//   for (int i=0; i < n; ++i) {
//     if (not friends[i].empty()) {
//       for (auto it : friends[i]) {
//         cout << it << " ";
//       }
//       cout << "\n";
//     } else {
//       cout << "/0" << endl;
//     }
//   }
//   cout << "\n";
// }
//
int main()
{
  int k;
  int auxI;
  int l;

  memset(visited, 0, sizeof visited);
  // memset(friends, 0, sizeof friends);

  cin >> n >> k;
  vector<int> myv;

  for (int i=0; i < k; ++i) {
    cin >> l;
    myv.clear();

    for (int w=0; w < l; ++w) {
      cin >> auxI;
      // cout << "myv push_back(" << auxI-1 << ")" << endl;
      myv.push_back(auxI-1);
    }
    // cout << "myv:" << endl;
    // for (auto it : myv) {
    //   cout << it << " ";
    // }
    // cout << "\n";
    // //
    // cout << "myv.size:" << myv.size() << endl;

    for (int w=0; w < myv.size(); ++w) {
      for (int w2=w; w2 < myv.size(); ++w2) {
        if (w != w2) {
          // cout << w << " != " << w2 << endl;
          // cout << "find(friends[" << myv[w] << "].begin()" << endl;
          // cout << "friends[" << myv[w] << "].push_back(" << myv[w2] <<")" << endl;
          connect(myv[w], myv[w2]);
        }
      }
    }
  }

  int ans = 0;
  ans = bfs(0, n-1);
  // cout << "0 até " << n-1 << endl;
  cout << ans << endl;
  return 0;
}
