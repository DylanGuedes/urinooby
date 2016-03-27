#include <iostream>

using namespace std;

int fibb(int n, int *counter)
{
  *counter += 1;
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibb(n-1, counter) + fibb(n-2, counter);
}

int main()
{
  int num = 0;
  int n;
  int aux_i;
  cin >> n;
  for (int i=0; i < n; ++i) {
    cin >> aux_i;
    num = 0;
    int result = fibb(aux_i, &num);
    cout << "fib(" << aux_i << ") = " << num-1 << " calls = " << result << endl;
  }

  return 0;
}
