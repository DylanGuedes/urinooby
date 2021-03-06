#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int visited[10010];
int friends[10010][10010];
int n;

void connect(int a1, int a2)
{
  friends[a1][a2] = 1;
  friends[a2][a1] = 1;

  for (int i=0; i < n; ++i) {
    if (friends[a1][i] == 1 && friends[a2][i] == 0) {
      connect(a2, i);
    }

    if (friends[a2][i] == 1 && friends[a1][i] == 0) {
      connect(a1, i);
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

    for (int i=0; i < n; ++i) {
      if (friends[v1][i] == 1 && visited[i] == 0) {
        myq.push(pair<int, int>(i, v2+1));
      }
    }
  }
}
//
void print_grid(int n)
{
  for (int i=0; i < n; ++i) {
    for (int j=0; j < n; ++j) {
      cout << friends[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

int main()
{
  int k;
  int auxI;
  int l;

  memset(visited, 0, sizeof visited);
  memset(friends, 0, sizeof friends);

  cin >> n >> k;
  vector<int> myv;

  for (int i=0; i < k; ++i) {
    cin >> l;
    myv.clear();

    for (int w=0; w < l; ++w) {
      cin >> auxI;
      myv.push_back(auxI-1);
    }

    for (int w=0; w < myv.size(); ++w) {
      for (int w2=w; w2 < myv.size(); ++w2) {
        if (w != w2) {
          connect(myv[w], myv[w2]);
        }
      }
    }
  }

  // print_grid(n);

  int ans = 0;
  ans = bfs(0, n-1);
  // cout << "0 até " << n-1 << endl;
  cout << ans << endl;
  return 0;
}
