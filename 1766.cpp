#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Rena {
  public:
    string nome;
    int peso;
    int idade;
    double altura;
};

bool myfunc(Rena r1, Rena r2)
{
  if (r1.peso < r2.peso) {
    return false;
  } else if (r1.peso > r2.peso) {
    return true;
  } else {
    if (r1.idade > r2.idade) {
      return false;
    } else if (r1.idade < r2.idade) {
      return true;
    } else {
      if (r1.altura > r2.altura) {
        return false;
      } else if (r1.altura < r2.altura) {
        return true;
      } else {
        return r1.nome < r2.nome;
      }
    }
  }
}

int main()
{
  vector<Rena> myv;
  int t, n, m;
  int counter = 1;
  cin >> t;
  for (int i=0; i < t; ++i) {
    myv.clear();
    cin >> n >> m;
    for (int j=0; j < n; ++j) {
      Rena rena;
      cin >> rena.nome;
      cin >> rena.peso;
      cin >> rena.idade;
      cin >> rena.altura;
      myv.push_back(rena);
    }

    sort(myv.begin(), myv.end(), myfunc);

    cout << "CENARIO {" << counter<< "}" << endl;
    for(int j=0; j < m; ++j) {
      cout << j+1 << " - " << myv[j].nome << endl;
    }
    counter++;
  }
  return 0;
}
