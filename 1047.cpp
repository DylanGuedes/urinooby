#include <iostream>

using namespace std;

int main()
{
  int hSTime, mSTime, hETime, mETime;
  int resultM = 0;
  int finalHora = 0;

  cin >> hSTime >> mSTime >> hETime >> mETime;

  mSTime += (hSTime * 60);
  mETime += (hETime * 60);

  if (mSTime > mETime) {
    //acabou no outro dia
    mETime += (24*60);
  }

  resultM = mETime - mSTime;

  // while ((resultM % 60)) {
  //   if (resultM >= 60) {
  //     resultM /= 60;
  //     finalHora += 1;
  //   } else {
  //     break;
  //   }
  // }
  if (resultM == 0) {
    finalHora = 24;
  } else {
    while ((resultM >= 60)) {
      resultM -= 60;
      finalHora += 1;
    }
  }

  cout << "O JOGO DUROU " << finalHora << " HORA(S) E " << resultM << " MINUTO(S)" << endl;
  return 0;
}
