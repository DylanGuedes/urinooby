#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int o, d, k;
set<int> forbidden;
vector<int> solutions;
int arr[100005];
int solucao;

void solve(int idx, int total)
{
  queue< pair<int, int> > myq;

  arr[idx] = 1;
  myq.push(pair<int, int>(idx, 1));

  while (not myq.empty()) {
    int aux = myq.front().first;
    int total = myq.front().second;
    myq.pop();

    if (aux == d) {
      solucao = aux;
      return;
    }

    vector<int> v{aux*2, aux*3, aux+1,aux-1};
    if ((aux & 1) == 0 && aux != 0) {
      v.push_back(aux/2);
    }

    int length = v.size();
    for (int i=0; i < length; ++i) {
      auto it = forbidden.find(v[i]);
      if (it == forbidden.end() && v[i] < 100000 && v[i] > 0 && arr[v[i]] == 0) {
        arr[v[i]] = 1;
        myq.push(pair<int, int>(v[i], total+1));
      }
    }
  }
  solucao = -1;
}

int main()
{
  int myauxi;
  while(1) {
    cin >> o >> d >> k;
    memset(arr, 0, sizeof arr);
    if (o == 0 && d == 0 && k == 0) return 0;

    solutions.clear();
    forbidden.clear();
    for (int i=0; i < k ; ++i) {
      cin >> myauxi;
      forbidden.insert(myauxi);
    }

    solve(o, 0);
    cout << solucao << endl;

  }
  return 0;
}
