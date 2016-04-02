#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int forbidden[105];
int o, d, k;
vector<int> solutions;
int arr[100005];

void solve(int idx, int total)
{
  arr[idx] = 1;

  if (idx == d) {
    solutions.push_back(total);
    cout << "MOSTRADO EM SOLUCOES:" << endl;
    for (int i=0; i < 100000; ++i) {
      cout << arr[i] << " ";
    }
  } else {

    if (not arr[idx+1] && idx+1 < 100000) {
      solve(idx+1, total+1);
    }

    if (not arr[idx-1] && idx-1 > 0) {
      solve(idx-1, total+1);
    }

    if (not arr[idx*2] && idx*2 < 100000 && idx*2 < d*2)
      solve(idx*2, total+1);
    if (not arr[idx*3] && idx*3 < 100000 && idx*3 < d*3)
      solve(idx*3, total+1);

    if ((idx & 1) == 0 && (not arr[idx/2])) {
      solve(idx/2, total+1);
    }
  }
}

int main()
{
  while(1) {
    cin >> o >> d >> k;
    memset(arr, 0, sizeof arr);
    if (o == 0 && d == 0 && k == 0) return 0;

    solutions.clear();
    for (int i=0; i < k ; ++i) {
      cin >> forbidden[i];
    }

    solve(o, 0);
    sort(solutions.begin(), solutions.end());
    cout << solutions[0] << endl;

  }
  return 0;
}
