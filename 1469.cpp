#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int age[510];
int grid[510][510];
int visited[510];
int n;
int pos[510];
map<int, int> mymap;

void connect(int a, int b)
{
  grid[b][a] = 1;
  grid[a][b] = 0;

  for (int i=0; i < n; ++i) {
    if (grid[a][i] == 1) {
      connect(i, b);
    }
  }
}

void troca(int source, int destiny)
{
  int aux;

  aux = pos[source];
  pos[source] = pos[destiny];
  pos[destiny] = aux;
}

int other_bfs(int source)
{
  bool flag = false;
  int result = 0xFFF;
  for (int i=0; i < n; ++i) {
    if (i != source) {
      if (grid[source][i] == 1) {
        // cout << "grid[" << source << "][" << i << "] == 1" << endl;
        flag = true;
        result = min(result, age[mymap[i]]);
      }
    }
  }

  if (flag == true) {
    return result;
  } else {
    return -1;
  }
}

int bfs(int source)
{
  queue< pair<int, int> > myq;
  myq.push(pair<int, int>(source, age[source]));

  int v2;

  while (not myq.empty()) {
    int v1 = myq.front().first;
    v2 = myq.front().second;

    myq.pop();

    visited[v1] = 1;

    for (int i=0; i < n; ++i) {
      if (grid[v1][i] == 1 && visited[i] == 0) {
        myq.push(pair<int, int>(i, min(v2, age[i])));
      }
    }
  }

  return v2;
}

int main()
{
  int m, l;
  int source, destiny;
  char ope;

  while(cin >> n >> m >> l) {
    memset(visited, 0, sizeof visited);
    memset(grid, 0, sizeof grid);

    for (int i=0; i < n; ++i) {
      pos[i] = i;
      mymap.insert(pair<int, int>(i, i));
    }

    for (int i=0; i < n; ++i) {
      cin >> age[i];
    }

    for (int i=0; i < m; ++i) {
      cin >> source;
      cin >> destiny;
      connect(source-1, destiny-1);
    }

    // cout << "MYGRID:" << endl;
    // for (int i=0; i <n; ++i) {
    //   for (int j=0; j <n ;++j) {
    //     cout << grid[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    //
    for (int i=0; i < l; ++i) {
      cin >> ope;
      if (ope == 'T') {
        cin >> source;
        cin >> destiny;

        cout << "T(" << source-1 << ", " << destiny-1 << ")" << endl;
        int aux = mymap[source-1];
        mymap[source-1] = mymap[destiny-1];
        mymap[destiny-1] = aux;

        auto it1 = find(pos, pos+n, source-1);
        for (int j=0; j < n; ++j) {
          if (pos[i] == source-1) {

          }
        }

        aux = pos[source-1];
        pos[source-1] = pos[destiny-1];
        pos[destiny-1] = aux;

        // aux = age[source-1];
        // age[source-1] = age[destiny-1];
        // age[destiny-1] = aux;
        // troca(source-1, destiny-1);
      } else if (ope == 'P') {
        cin >> source;
        cout << "bfs(" << mymap[source-1] << ")" << endl;
        int result = other_bfs(mymap[source-1]);
        if (result == -1) {
          cout << "*" << endl;
        } else {
          cout << result << endl;
        }
      }
      cout << "MYMAP:" << endl;
      for (auto it : mymap) {
        cout << it.first << "(" << age[it.first] << ") => " << it.second << "(" << age[it.second] << ")" << endl;
      }

    }

  }
  return 0;
}
