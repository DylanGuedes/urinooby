#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int color[110];
#define ii pair<int, int>
bool friends[110][110];
bool impossible;

void connect(int n1, int n2)
{
  friends[n1][n2] = true;
  friends[n2][n1] = true;
}

void solve(int n)
{
  for (int i=0; i < n; ++i) {
    if (color[i] == 0) {
      queue<ii> myq;
      myq.push(ii(i, 1));

      while (not myq.empty()) {
        int a1 = myq.front().first;
        int a2 = myq.front().second;
        myq.pop();

        color[a1] = a2;

        for (int j=0; j < n; ++j) {
          if (friends[a1][j] == true) {
            if (color[j] == 0) {
              if (color[a1] == 1) {
                color[j] = 2;
                myq.push(ii(j, 2));
              } else if (color[a1] == 2) {
                color[j] = 1;
                myq.push(ii(j, 1));
              }
            } else if (color[a1] == color[j]) {
              impossible = true;
              return;
            }
          }
        }
      }
    }
  }

}

int main()
{
  int n;
  int id;
  string mystring;

  while (cin >> n) {
    if (n == 0) return 0;

    memset(color, 0, sizeof color);
    memset(friends, false, sizeof friends);

    for (int i=0; i < n; ++i) {
      cin >> id;
      getline(cin, mystring);
      getline(cin, mystring);

      istringstream iss (mystring);
      int aux;
      while (iss >> aux) {
        connect(id-1, aux-1);
      }
    }

    impossible = false;
    solve(n);
    if (impossible) {
      cout << "NAO" << endl;
    } else {
      cout << "SIM" << endl;
    }

  }
  return 0;
}
