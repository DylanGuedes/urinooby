#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int source, destiny;
int val[50010];
vector<int> friends[50010];
#define ii pair<int, int>
vector<int> visiteds;
vector<int> myvec;

void connect(int a, int b)
{
  friends[a].push_back(b);
  friends[b].push_back(a);
}

int bfs(int a, int b)
{
  queue<ii> myq;

  myq.push(ii(a, 0));

  while (not myq.empty()) {
    int v1 = myq.front().first;
    int v2 = myq.front().second;

    myq.pop();
    visiteds[v1] = 1;

    if (val[v1] == b && v1 != a) {
      return v2;
    }

    for (auto it : friends[v1]) {
      if (visiteds[it] == 0) {
        myq.push(ii(it, v2+1));
      }
    }
  }

  return 0;
}

int main()
{
  int n;
  scanf("%d", &n);

  myvec.resize(n/2);

  for (int i=0; i < n; ++i) {
    scanf("%d", &val[i]);
    val[i] -= 1;
    myvec[val[i]] = i;
  }

  for(int i=0; i < n-1; ++i) {
    scanf("%d", &source);
    scanf("%d", &destiny);
    connect(source-1, destiny-1);
  }

  int total = 0;

  for (int i=0; i < (n/2); ++i) {
    visiteds.assign(n, 0);
    total += bfs(myvec[i], i);
  }

  printf("%d\n", total);
  return 0;
}
