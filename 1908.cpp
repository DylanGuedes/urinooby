#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[1010];
int adjs[10001][10005];
int visiteds[10100];

void connect(int a, int b)
{
  adjs[a][b] = 1;
  adjs[b][a] = 1;
}

int bfs(int idx, int n, int counter)
{
  cout << "idx: " << idx << endl;
  cout << "n: " << n << endl;
  if (idx == n) return counter;

  visiteds[idx] = 1;

  for (int i=0; i < n; ++i) {
    if (adjs[idx][i] == 1 && visiteds[i] == 0) {
      return bfs(i, n, counter+1);
    }
  }

}

int main()
{
  int n, k, aux_i;
  int otherI;
  memset(arr, 0, sizeof arr);
  memset(adjs, 0, sizeof adjs);
  memset(visiteds, 0, sizeof visiteds);

  cin >> n >> k;
  for (int i=0; i < k; ++i) {
    cin >> aux_i;
    memset(arr, 0, sizeof arr);

    for (int j=0; j < aux_i; ++j) {
      cin >> otherI;
      // cout << "otherI: " << otherI << endl;
      arr[j] = otherI-1;
    }
    // cout << "fim" << endl;

    cout << "k: " << k << endl;
    for (int z=0; z < aux_i; ++z) {
      for (int j=z+1; j < aux_i; ++j) {
        connect(arr[z], arr[j]);
      }
    }



    cout << "matrizes:" << endl;
    for (int i=0; i < n; ++i) {
      for (int j=0; j < n; ++j) {
        cout << adjs[i][j] << " ";
      }
      cout << "\n";
    }


  }


  cout << "matrizes:" << endl;
  for (int i=0; i < n; ++i) {
    for (int j=0; j < n; ++j) {
      cout << adjs[i][j] << " ";
    }
    cout << "\n";
  }

  cout << bfs(0, n-1, 0) << endl;

  return 0;
}

