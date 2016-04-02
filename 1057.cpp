#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int arr[11][11];

class Guy
{
  public:
    int x, y;
};

Guy A;
Guy B;
Guy C;

void bfs(int xA, int yA, int xB, int yB, int xC, int yC)
{
  if ( algo && arr[yA][xA] == 0) {
    arr[yA][xA] = 1;
    bfs(xA+1, yA, xB+1, yB, xC+1, yC);
  }

  if ( algo && arr[xB][yB] == 0) {
    bfs(xA, yA+1, xB, yB+1, xC, yC+1);
  }

  if ( algo && arr[xB][yB] == 0) {
    bfs(xA, yA-1, xB, yB-1, xC, yC-1);
  }

  if ( algo && arr[xB][yB] == 0) {
    bfs(xA-1, yA, xB-1, yB, xC-1, yC);
  }
}

int main()
{
  int t;
  char tmp_buf;
  cin >> t;

  for (int w=0; w < t; ++w) {
    cin >> n;
    memset(arr, 0, sizeof arr);
    for (int i=0; i < n; ++i) {
      for (int j=0; j < n; ++j) {
        cin >> tmp_buf;
        if (tmp_buf == 'A') {
          A.x = j;
          A.y = i;
          arr[i][j] = 1;
        } else if (tmp_buf == 'B') {
          B.x = j;
          B.y = i;
          arr[i][j] = 1;
        } else if (tmp_buf == 'C') {
          C.x = j;
          C.y = i;
          arr[i][j] = 1;
        } else if (tmp_buf == '#') {
          arr[i][j] = 1;
        } else if (tmp_buf == '.') {
          arr[i][j] = 0;
        } else if (tmp_buf == 'X') {
          arr[i][j] = 2;
        }
      }
    }

    bfs(A.x, A.y, B.x, B.y, C.x, C.y);
  }
  return 0;
}
