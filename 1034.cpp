#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long int> coins;
vector<long long int> solutions;

int coin_change(long long int m, long long int current, long long int total_cubes, long long int coin_idx)
{
  queue<pair<int, long long int> > myq;

  myq.push(pair<int, long long int>(1, coins.back()));

  while (not queue.empty()) {
    int aux = myq.front(); myq.pop();
    if (aux.second == m) {
      solutions.push_back(aux.first);
    }

    // nao pego o ultimo cubo
    queue.push(pair<int, int>(0, 0));

    int length =  coins.size();
    for (int i=0; i < length; ++i) {
      // pego o cubo i e o inicial
      if (coins[i]+aux.second < m) {
        queue.push(pair<int, int>(aux.first+1, coins[i]+aux.second));
      }
    }
  }
}

int main()
{
  int t;
  long long int n, m;
  long long int aux_i;

  cin >> t;
  for (int w=0; w < t; ++w) {
    coins.clear();
    cin >> n >> m;
    for (int i=0; i < n; ++i) {
      cin >> aux_i;
      coins.push_back(aux_i);
    }

    sort(coins.begin(), coins.end());

    cout << "size: " << coins.size() << endl;
    cout << coin_change(m,0, 0, coins.size()-1) << endl;
  }
  return 0;
}
