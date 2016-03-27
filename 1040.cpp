#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
  double numbers[4];
  double result = 0;
  double result1 = 0;
  double nova_nota;

  for (int i=0; i < 4; ++i) {
    cin >> numbers[i];
  }

  result = numbers[0] * 2 + numbers[1] * 3 + numbers[2] * 4 + numbers[3] * 1;
  result1 = result / 10;

  cout << std::fixed << setprecision(1);
  cout << "Media: " << fixed << setprecision(1) << result1 << endl;

  // printf("Media: %0.1lf\n", result1);
  if (result1 < 5) {
    cout << "Aluno reprovado." << endl;
  } else if (result1 >= 7.0) {
    cout << "Aluno aprovado." << endl;
  } else {
    cin >> nova_nota;
    cout << "Aluno em exame." << endl;
    cout << "Nota do exame: " << nova_nota << endl;

    result = nova_nota + result1;
    result1 = result / 2;

    if (result1 >= 5.0) {
      cout << "Aluno aprovado." << endl;
    } else {
      cout << "Aluno reprovado." << endl;
    }

    cout << "Media final: " << result1 << endl;

  }

  return 0;
}
