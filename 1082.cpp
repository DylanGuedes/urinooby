#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int grid[27][27];
int skip[27];
int V, E;

void connect(int c1, int c2)
{
  // cout << "stack" << endl;
  grid[c1][c2] = 1;
  grid[c2][c1] = 1;

  for (int i=0; i < V; ++i) {
    if (grid[c1][i] == 1 && grid[c2][i] == 0) {
      grid[c2][i] = 1;
      connect(c2, i);
    }

    if (grid[c2][i] == 1 && grid[c1][i] == 0) {
      grid[c1][i] = 1;
      connect(c1, i);
    }
  }
}

int main()
{
  int N;
  char c1, c2;

  cin >> N;
  for (int ww=0; ww < N; ++ww) {
    memset(grid, 0, sizeof grid);
    memset(skip, 0, sizeof skip);
    cin >> V >> E;
    for (int i=0; i < E; ++i) {
      cin >> c1;
      cin >> c2;
      c1 -= 97;
      c2 -= 97;

      // printf("conectando %d com %d\n", c1, c2);
      connect((int)c1, (int)c2);
    }

    // cout << "final grid:\n";
    // for (int i=0; i < V; ++i) {
    //   for (int j=0;j < V;++j) {
    //     cout << grid[i][j] << " ";
    //   }
    //   cout << "\n";
    // }

    cout << "Case #" << ww+1 << ":" << endl;
    int counter = 0;
    for (int i=0; i < V; ++i) {

      if (skip[i] == 0) {
        if (i) {
          cout << "\n";
        }
        counter += 1;
        printf("%c,", i+97);
        for (int j=0; j < V; ++j) {
          if (grid[i][j] == 1 && i != j) {
            printf("%c,", j+97);
            skip[j] = 1;
          }
        }
      }
    }

    cout << "\n";
    cout << counter << " connected components" << endl;
    cout << "\n";


  }
  return 0;
}
