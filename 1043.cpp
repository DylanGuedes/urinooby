#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
  double a, b, c;
  double perimetro;

  cin >> a;
  cin >> b;
  cin >> c;

  if ((abs(b-c) < a) && (a < (b+c)) && (abs(a-c) < b) && (b < (a+c)) && (abs(a-b) < c) && (c < (a+b))) {
// formam
    printf("Perimetro = %.1f\n", (a + b + c));
  } else {
    perimetro = c * (a + b);
    printf("Area = %.1f\n", perimetro/2);
  }

  return 0;
}
