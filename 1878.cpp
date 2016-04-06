#include <iostream>
#include <cstring>

using namespace std;

int coef[4];

void solve(int n, int m)
{
  if (m == 1) {
    cout << "Lucky Denis!" << endl;
    return;
  }

  if (n == 1) {
    // soh um torneio
    cout << "Lucky Denis!" << endl;
  } else if (n == 2) {
    // dois torneios
    for (int i=1; i <= 10; ++i) {
      for (int j=1; j <= 10; ++j) {
        for (int k=1; k <= 10; ++k) {
          for (int l=1; l <= 10; ++l) {
            if (i != k && j != l) {
              long long int sol1 = coef[0]*i + coef[1]*j;
              long long int sol2 = coef[0]*k + coef[1]*l;

              if (sol1 == sol2) {
                cout << "Try again later, Denis..." << endl;
                return;
              }
            }
          }
        }
      }
    }
    cout << "Lucky Denis!" << endl;
  } else if (n == 3) {
    for (int i=1; i <= 10; ++i) {
      for (int j=1; j <= 10; ++j) {
        for (int k=1; k <= 10; ++k) {
          for (int l=1; l <= 10; ++l) {
            for (int theta=1; theta <=10; ++theta) {
              for (int alpha=1; alpha <= 10; ++alpha) {
                if (i != l && j != theta && k != alpha) {
                  long long int sol1 = coef[0]*i + coef[1] *j + coef[2] * k;
                  long long int sol2 = coef[0]*l + coef[1] * theta + coef[2] * alpha;
                  if (sol1 == sol2) {
                    cout << "Try again later, Denis..." << endl;
                    return;
                  }
                }
              }
            }
          }
        }
      }
    }
    cout << "Lucky Denis!" << endl;
  }
}

int main()
{
  int n, m;
  while (cin >> n >> m) {
    memset(coef, 0, sizeof coef);
    for (int i=0; i < n; ++i) {
      cin >> coef[i];
    }

    solve(n, m);
  }
  return 0;
}
