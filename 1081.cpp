#include <iostream>
#include <cstring>

using namespace std;

int grid[21][21];
int visiteds[21];
int friendship_count[21];

void dfs(int idx, int n, int future_source, int count)
{
  for (int i=0; i < n; ++i) {
    if (grid[idx][i] == 1 && visiteds[i] == 0) {
      visiteds[i] = 1;
      visiteds[idx] = 1;
      for(int j=0; j < count; ++j) {
        printf("  ");
      }
      printf("%d-%d pathR(G,%d)\n", idx, i, i);
      dfs(i, n, idx, count+1);
    } else if (grid[idx][i] == 1 && visiteds[i] == 1) {
      for(int j=0; j < count; ++j) {
        printf("  ");
      }
      printf("%d-%d\n", idx, i);
    }
  }
}

void get_friendship_count(int E)
{
  for(int i=0; i < E; ++i) {
    for (int j=0; j < E; ++j) {
      if(grid[i][j] == 1 && i != j) {
        friendship_count[i] += 1;
      }
    }
  }

}

int main()
{
  int n;
  int V, E;
  int source, destiny;

  cin >> n;
  for (int zz=0; zz < n; ++zz) {
    memset(grid, 0, sizeof grid);
    memset(visiteds, 0, sizeof visiteds);
    memset(friendship_count, 0, sizeof friendship_count);
    cin >> V >> E;
    for (int i=0; i < E; ++i) {
      cin >> source;
      cin >> destiny;

      grid[source][destiny] = 1;
    }

    get_friendship_count(E);

    // cout << "V:" << V << endl;
    // cout << "mygrid:" << endl;
    // for (int i=0; i < V; ++i) {
    //   for (int w=0; w < V; ++w) {
    //     cout << grid[i][w] << " ";
    //   }
    //   cout << endl;
    // }

    cout << "Caso "<<zz+1<<":" << endl;
    bool myflag = false;

    for (int i=0; i < V; ++i) {
      if (visiteds[i] == 0) {
        myflag = false;
        dfs(i, V, 0, 1);
        if (friendship_count[i] > 0) {
          if (i+1 != V) {
            cout << "\n";
            myflag = true;
          }
        }
      }
    }
    if (myflag == false)
      cout << "\n";
  }
  return 0;
}
