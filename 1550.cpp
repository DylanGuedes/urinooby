#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define ii pair<int, int>
int visiteds[10010];

int reverse(int num)
{
  int aux = 0;
  while (num > 0) {
    aux *= 10;
    aux += (num % 10);
    num /= 10;
  }

  return aux;
}

int bfs(int a, int b)
{
  queue<ii> myq;
  myq.push(pair<int, int>(a, 0));

  while (not myq.empty()) {
    int x = myq.front().first;
    int y = myq.front().second;

    myq.pop();

    int limiarA = x+1;
    int limiarB = reverse(x);

    if (limiarA == b || limiarB == b) {
      return y+1;
    }

    if (limiarA < 10000 && visiteds[limiarA] == 0) {
      myq.push(pair<int, int>(limiarA, y+1));
      visiteds[limiarA] = 1;
    }

    if (limiarB < 10000 && visiteds[limiarB] == 0) {
      myq.push(pair<int, int>(limiarB, y+1));
      visiteds[limiarB] = 1;
    }

  }

  return -1;
}

int main()
{
  int t;
  int a, b;


  cin >> t;
  for (int i=0; i < t; ++i) {
    memset(visiteds, 0, sizeof visiteds);
    cin >> a >> b;
    cout << bfs(a, b) << endl;
  }
  return 0;
}
