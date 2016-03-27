#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  double n;
  double perc;
  double new_salary;
  double diff;
  double new_perc;
  int perc2;

  cin >> n;

  if (n <= 400.00) {
    perc = 1.15;
    perc2 = 15;
  } else if (n >= 400.01 && n <= 800.00) {
    perc = 1.12;
    perc2 = 12;
  } else if (n >= 800.01 && n <= 1200.00) {
    perc = 1.10;
    perc2 = 10;
  } else if (n >= 1200.01 && n <= 2000.00) {
    perc = 1.07;
    perc2 = 7;
  } else if (n > 2000.00) {
    perc = 1.04;
    perc2 = 4;
  }

  new_salary = n * perc;
  diff = new_salary - n;

  printf("Novo salario: %.2f\n", new_salary);
  printf("Reajuste ganho: %.2f\n", diff);
  printf("Em percentual: %d %\n", perc2);

  return 0;
}
