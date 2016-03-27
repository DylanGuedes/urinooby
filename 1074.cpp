#include <iostream>

using namespace std;

int main()
{
  int n;
  long long int aux;

  cin >> n;
  for (int i=0; i < n; ++i) {
    cin >> aux;
    if (aux == 0) {
      cout << "NULL" << endl;
    } else {
      if ((aux & 1) == 1) {
        cout << "ODD ";
      } else {
        cout << "EVEN ";
      }

      if (aux > 0) {
        cout << "POSITIVE" << endl;
      } else {
        cout << "NEGATIVE" << endl;
      }
    }

  }
  return 0;
}
