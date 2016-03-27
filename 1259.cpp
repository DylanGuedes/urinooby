#include <iostream>
#include <algorithm>

using namespace std;

bool myfunc(int n1, int n2)
{
  // true = faz nada
  // false = troca ordem
  if (((n1 & 1) == 0) && ((n2 & 1) == 1)) {
    // n1 é par, n2 é impar
    return true;
  } else if (((n2 & 1) == 0) && ((n1 & 1) == 1)) {
    // n2 é par, n1 é impar
    return false;
  } else {
    // ambos sao pares ou impar
    if ((n1 & 1) == 0) {
      // ambos sao pares
      return n1 < n2;
    } else {
// ambos sao impares
      return n2 < n1;
    }
  }
}

int main()
{
  int n;
  int aux_i;
  vector<int> myv;

  cin >> n;
  for (int i=0; i < n; ++i) {
    cin >> aux_i;
    myv.push_back(aux_i);
    // cout << "to aqui" << endl;
  }

  sort(myv.begin(), myv.end(), myfunc);
  for (auto it : myv) {
    cout << it << endl;
  }
  return 0;
}
