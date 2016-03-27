#include <iostream>

using namespace std;

int main()
{
  int sTime, eTime;
  int result = 0;
  cin >> sTime >> eTime;

  if (eTime <= sTime) {
    eTime += 24;
  }

  result = eTime - sTime;
  cout << "O JOGO DUROU " << result << " HORA(S)" << endl;

  return 0;
}

