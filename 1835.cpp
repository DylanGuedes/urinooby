#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int arr[100][100];
int visiteds[100];
int n;

void connect(int x, int y)
{
  arr[x][y] = 1;
  arr[y][x] = 1;
}

void bfs(int j)
{
  queue<int> myq;
  myq.push(j);
  while (not myq.empty()) {
    visiteds[myq.front()] = true;
    for (int i=0; i < n; ++i) {
      if (arr[myq.front()][i] == 1 && visiteds[i] == false) {
        myq.push(i);
      }
    }

    myq.pop();
  }
}

int main()
{
  int t;
  int counter = 0;
  int m;
  int x, y;

  cin >> t;

  for (int i=0; i < t; ++i) {
    counter = 0;

    cin >> n >> m;

    memset(arr, 0, sizeof arr);
    memset(visiteds, 0, sizeof visiteds);

    for (int j=0; j < m; ++j) {
      cin >> x >> y;
      connect(x-1, y-1);
    }

    for (int j=0; j < n; ++j) {
      connect(j, j);
    }

    visiteds[0] = 1;
    bfs(0);

    for (int j=1; j < n; ++j) {
      if (visiteds[j] == false) {
        // cout << j << " nao visitado" << endl;
        counter++;
        visiteds[j] = true;
        bfs(j);
      }
    }

    if (counter == 0) {
      cout << "Caso #" << i+1 << ": a promessa foi cumprida" << endl;
    } else {
      cout << "Caso #" << i+1 << ": ainda falta(m) " << counter << " estrada(s)" << endl;
    }

  }
  return 0;
}
