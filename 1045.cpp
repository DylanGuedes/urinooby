#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  double arr[3];
  double aa, bb, cc;

  cin >> arr[0];
  cin >> arr[1];
  cin >> arr[2];

  sort(arr, arr + 3, std::greater<int>());

  aa = arr[0] * arr[0];
  bb = arr[1] * arr[1];
  cc = arr[2] * arr[2];

  if (arr[0] >= (arr[1] + arr[2])) {
    cout << "NAO FORMA TRIANGULO" << endl;
  } else {
    if (aa == (bb+cc)) {
      cout << "TRIANGULO RETANGULO" << endl;
    }

    if (aa > (bb + cc)) {
      cout << "TRIANGULO OBTUSANGULO" << endl;
    }

    if (aa < (bb + cc)) {
      cout << "TRIANGULO ACUTANGULO" << endl;
    }

    if ((arr[0] == arr[1]) && (arr[1] == arr[2])) {
      cout << "TRIANGULO EQUILATERO" << endl;
    } else if ((arr[0] == arr[1]) || (arr[1] == arr[2]) || (arr[2] == arr[1])) {
      cout << "TRIANGULO ISOSCELES" << endl;
    }
  }


  return 0;
}
