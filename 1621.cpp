#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string grid[501];
int visiteds[501][501];

int bfs(int x, int y, int height, int width, int total)
{
  cout << "x: " << x << ", y: " << y << ", total: " << total << endl;

  pair<int, pair<int, int> > result[4];

  if (x+1 < width && grid[x+1][y] == '.' && visiteds[x+1][y] == 0) {
    visiteds[x+1][y] = 1;
    result[0] = bfs(x+1, y, height, width, total+1);
    result[0].second.first = x+1;
    result[0].second.second = y;
  } else {
    result[0].first = -1;
    positions[0].second.first = x+1;
    positions[0].second.second = y;
  }

  if (x-1 >= 0 &&  grid[x-1][y] == '.' && visiteds[x-1][y] == 0) {
    visiteds[x-1][y] = 1;
    result[1] = bfs(x-1, y, height, width, total+1);
    result[1].second.first = x-1;
    result[1].second.second = y;
  } else {
    result[1].first = -1;
    positions[1].second.first = x-1;
    positions[1].second.second = y;
  }

  if (y+1 < height &&  grid[x][y+1] == '.' && visiteds[x][y+1] == 0) {
    visiteds[x][y+1] = 1;
    result[2] = bfs(x, y+1, height, width, total+1);
    positions[2].first = x;
    positions[2].second = y+1;
  } else {
    result[2] =  -1;
    positions[2].first = x;
    positions[2].second = y+1;
  }

  if (y-1 >= 0 &&  grid[x][y-1] == '.' && visiteds[x][y-1] == 0) {
    visiteds[x][y-1] = 1;
    result[3] = bfs(x, y-1, height, width, total+1);
    positions[3].first = x;
    positions[3].second = y-1;
  } else {
    result[3] = -1;
    positions[3].first = x;
    positions[3].second = y-1;
  }

  sort(result, result+4, std::greater<int>());
  // cout << "RESULTS:" << endl;
  // for (int i=0; i < 4; ++i) {
  //   cout << "result[i]: " << result[i] << endl;
  // }

  if (result[0] == -1) return total;

  return result[0];
}

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) return 0;
    memset(visiteds, 0, sizeof visiteds);

    for (int i=0; i < n; ++i) {
      cin >> grid[i];
    }

    int sol1 = bfs(0, 0, n, m, 0);
    cout << bfs(0, 0, n, m, 0) << endl;
  }
  return 0;
}
