#include <iostream>
#include <cstring>
#include <queue>
#include <list>

using namespace std;

#define ii pair<int, int>

int friends[1005][1010];
bool impossible;
int poly[1005];

bool can_be_at(int idx, list<int> t)
{
  for (auto it : t) {
    if (friends[idx][it] == 0) {
      return false;
    }
  }
  return true;
}

void solve(int n)
{
  list<int> t1, t2;
  for (int i=0; i < n; ++i) {
    if (can_be_at(i, t1)) {
      if (can_be_at(i, t2)) {
        if (i != 0) {
          if (poly[i] == -1) {
            t2.push_back(i);
          } else if (poly[i] == 0) {
            // pode ficar no tank 1 e no tank 2
            // tenta no 2
            poly[i] = 1;
            t1.push_back(i);
          }
        } else {
          t1.push_back(i);
        }
      } else {
        t1.push_back(i);
      }
    } else if (can_be_at(i, t2)) {
      t2.push_back(i);
    } else {
      int w;
      for (w=0; w < n; ++w) {
        if (poly[w] == 1) {
          t1.clear();
          t2.clear();
          t1.push_back(0);
          i = 0;
          poly[w] = -1;
          break;
        }
      }
      if (w == n) {
        impossible = true;
        return;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i=0; i < n; ++i) {
    for (int j=0; j < n; ++j) {
      cin >> friends[i][j];
    }
  }

  memset(poly, 0, sizeof poly);

  impossible = false;
  solve(n);

  if (impossible)
    cout << "Fail!" << endl;
  else
    cout << "Bazinga!" << endl;
  return 0;
}
