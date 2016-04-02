#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myfunc(string s1, string s2)
{
  if (s1.size() != s2.size()) {
    return s1.size() > s2.size();
  } else {
    return false;
  }
}

int main()
{
  int n;
  string nome;
  char mybuf;
  vector<string> myarr;
  int counter;

  cin >> n;
  mybuf = getchar();
  for (int i=0; i < n; ++i) {
    myarr.clear();
    counter = 0;

    while (mybuf = getchar()) {
      // cout << "mybuf aqui: " << mybuf << endl;
      if (mybuf == '\n') {
        // cout << "aqui" << endl;
        if (nome != " ") {
          // myarr.push_back(nome);
        }
        break;
      } else if (mybuf == ' ') {
        ++counter;
        // cout << "aqui tbm" << endl;
        if (myarr.size() > 0) {
          myarr.back().push_back(' ');
        }

        myarr.push_back(nome);

        // cout << "arr nese momento:" << endl;
        nome.clear();
      } else {
        if (mybuf != '\n' && mybuf != ' ') {
          // cout << "dando push em " << mybuf << endl;
          nome.push_back(mybuf);
        }
      }
    }

    sort(myarr.begin(), myarr.end(), myfunc);

    for (int i=0; i < counter; ++i) {
      if (i != 0) {
        cout << " ";
      }

      cout << myarr[i];
    }

    if (i != n) {
      cout << "\n";
    }
  }

  return 0;
}
