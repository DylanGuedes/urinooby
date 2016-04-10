#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define ii pair<int, int>

int visited[10020];
int n;
int k;
int l;
vector<int> friends[10020];

void connect(int a, int b)
{
  friends[a].push_back(b);
  friends[b].push_back(a);
}

int bfs(int source, int destiny)
{
  queue<ii> myq;
  visited[source] = 1;

  myq.push(ii(source, 0));
  int v1 = myq.front().first;

  while (not myq.empty()) {
    myq.front().first;
    int v2 = myq.front().second;
    v1 = myq.front().first;
    myq.pop();

    if (v1 == destiny) {
      return v2;
    }

    for (auto it : friends[v1]) {
      if (visited[it] == 0) {
        myq.push(ii(it, v2+1));
        visited[v1] = 1;
      }
    }
  }

  return v1;
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
      myv.push_back(aux);
    }

    int mylength = myv.size();
    for (int z=0; z < mylength; ++z) {
      for (int z2=z; z2 < mylength; ++z2) {
        connect(myv[z], myv[z2]);
      }
    }
  }

  cout << bfs(1, n) << endl;

  return 0;
}
