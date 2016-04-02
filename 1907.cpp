#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int visiteds[1030][1050];
int m, n;

void bfs(int x, int y)
{
  if ((x < (n-1)) && (visiteds[x+1][y] == 0)) {
    visiteds[x+1][y] = 1;
    bfs(x+1, y);
  }

  if ((y < (m-1)) && (visiteds[x][y+1] == 0)) {
    visiteds[x][y+1] = 1;
    bfs(x, y+1);
  }

  if ((y > 0) && (visiteds[x][y-1] == 0)) {
    visiteds[x][y-1] = 1;
    bfs(x, y-1);
  }

  if (x > 0 && (visiteds[x-1][y] == 0)) {
    visiteds[x-1][y] = 1;
    bfs(x-1, y);
  }
}

int main()
{
  char mybuf;
  int counter = 0;
  memset(visiteds, 0, sizeof visiteds);
  cin >> n >> m;
  for (int i=0; i < n; ++i) {
    for (int j=0; j < m; ++j) {
      cin >> mybuf;
      if (mybuf == 'o') {
        visiteds[i][j] = 1;
      }
    }
  }

  for (int i=0; i < n; ++i) {
    for (int j=0; j < m; ++j) {
      if (visiteds[i][j] != 1) {
        visiteds[i][j] = 1;
        counter++;
        bfs(i, j);
      }
    }
  }

  cout << counter << endl;
  return 0;
}
