#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define ii pair<int, int>

int friends[10020][10020];
int visited[10020];
int n;
int k;
int l;

void connect(int a, int b)
{
  friends[a][b] = 1;
  friends[b][a] = 1;
  //
  // for (int i=0; i < n; ++i) {
  //   if (a != i && a != b && i != b) {
  //     if (friends[a][i] == 1 && friends[b][i] == 0) {
  //       // cout << a << " eh amigo de " << i << " , mas " << b << " nao" << endl;
  //       connect(b, i);
  //     }
  //
  //     if (friends[b][i] == 1 && friends[a][i] == 0) {
  //       // cout << b << " eh amigo de " << i << " , mas " << a << " nao" << endl;
  //       connect(a, i);
  //     }
  //   }
  // }
}

int bfs(int source, int destiny)
{
  queue<ii> myq;
  visited[0] = 1;

  myq.push(pair<int, int>(source, 0));
  while (not myq.empty()) {
    int v1 = myq.front().first;
    int v2 = myq.front().second;
    myq.pop();
    visited[v1] = 1;

    if (v1 == destiny) {
      return v2;
    }

    for (int i=0; i < n; ++i) {
      if (v1 != i) {
        if (friends[v1][i] == 1 && visited[i] == 0) {
          myq.push(pair<int, int>(i, v2+1));
        }
      }
    }
  }

  return -1;
}

int main()
{
  int aux;
  memset(visited, 0, sizeof visited);
  memset(friends, 0, sizeof friends);
  cin >> n >> k;

  for (int w=0; w < k ;++w) {
    cin >> l;
    vector<int> myv;
    for (int i=0; i < l; ++i) {
      cin >> aux;
      myv.push_back(aux-1);
    }

    int mylength = myv.size();
    for (int z=0; z < mylength; ++z) {
      for (int z2=0; z2 < mylength; ++z2) {
        if (z != z2) {
          // cout << "connect " << myv[z] << " com " << myv[z2] << endl;
          connect(myv[z], myv[z2]);
        }
      }
    }
  }
  //
  // cout << "GRID:" << endl;
  // for (int i=0; i < n ;++i) {
  //   for (int j=0; j < n; ++j) {
  //     cout << friends[i][j];
  //   }
  //   cout << "\n";
  // }
  int ans = bfs(0, n-1);
  if (ans != -1)
    cout << ans << endl;

  return 0;
}
