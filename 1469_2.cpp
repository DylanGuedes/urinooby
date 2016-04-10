#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define ii pair<int, int>
vector< vector<int> > grid;
int age[520];
int n;
int visited[520];
int menor;
int global_index;

void troca(int source, int destiny)
{
  vector<int> aux = grid[source];
  grid[source] = grid[destiny];
  grid[destiny] = aux;

  for (int i=0; i < n; ++i) {
    // if (i != source && i != destiny) {
      for (auto &nodes : grid[i]) {
        if (nodes == source) {
          nodes = destiny;
        } else if (nodes == destiny) {
          nodes = source;
        }
      }
    // }
  }
}

void bfs(int source)
{
  if (grid[source].size() == 0) {
    cout << "*" << endl;
  } else {
    int menor = 0xFFFF;

    queue< int > myq;
    myq.push(grid[source].front());

    while (not myq.empty()) {
      int q1 = myq.front();
      visited[q1] = 1;
      if (menor > age[q1]) {
        cout << age[q1] << " eh menor que " << menor << endl;
        menor = age[q1];
      } else {
        cout << age[q1] << " nao eh menor." << endl;
      }
      myq.pop();
      for (auto it : grid[q1]) {
        if (visited[it] == 0) {
          myq.push(it);
          // cout << "menor entre " << menor << " e " << age[it] << endl;
        } else {
          cout << it << " ja foi visitado" << endl;
        }
      }
    }
    cout << menor << endl;
  }
}

void print_states()
{
  for (auto it : grid) {
    for (auto node : it ) {
      cout << node << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void dfs(int idx)
{
  // cout << "idx:" << idx<<", age:" << age[idx] << endl;
  visited[idx] = 1;
  for (auto it : grid[idx]) {
    if (visited[it] == 0) {
      dfs(it);
    }
  }

  if (global_index == idx) {
  } else {
    menor = min(menor, age[idx]);
  }
}

int main()
{
  int l, m;
  char charbuf;
  int source, destiny;

  while(cin >> n >> m >> l) {
    grid.clear();
    grid.resize(n);

    for (int i=0; i < n; ++i) {
      cin >> age[i];
    }

    for (int w=0; w < m; ++w) {
      cin >> source;
      cin >> destiny;
      grid[destiny-1].push_back(source-1);
    }

    // cout << "GRID:" << endl;
    // print_states();

    for (int w=0; w < l ;++w) {
      cin >> charbuf;
      if (charbuf == 'T') {
        cin >> source;
        cin >> destiny;
        // cout << "TROCA " << source-1 << " com " << destiny-1 << endl;
        troca(source-1, destiny-1);
        // cout << "ESTADOS:" << endl;
        // print_states();

      } else if (charbuf == 'P') {
        memset(visited, 0, sizeof visited);
        cin >> source;
        // cout << "P " << source-1 << endl;
        // bfs(source-1);
        if (grid[source-1].size() > 0) {
          menor = 0xFFFF;
          global_index = source-1;
          dfs(source-1);
          cout << menor << endl;
        } else {
          cout << "*" << endl;
        }
      }
    }
  }
  return 0;
}
