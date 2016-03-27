#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  double n;
  double diff = 0;

  cin >> n;

  if (n <= 2000.00) {
    cout << "Isento" << endl;
  } else {
    if (n <= 3000.00) {
      n -= 2000.00;
      diff = (0.08 * n);
    } else if (n <= 4500.00) {
      diff = (0.08) * 1000.00;
      n -= 3000.00;
      diff += (0.18 * n);
    } else {
      diff = (0.08) * 1000.00;
      diff += (0.18 * 1500.00);
      n -= 4500.00;
      diff += (0.28 * n);
      // maior que 4500
    }

    printf("R$ %.2f\n", diff);
  }
  return 0;
}
