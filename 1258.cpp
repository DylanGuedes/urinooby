#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class A
{
  public:
    string color;
    char Asize;
    string name;
    int power;

    bool operator< (const A& right) const {
      if (color < right.color) {
        return true;
      } else if (color > right.color) {
        return false;
      } else {
        if (power < right.power) {
          return true;
        } else if (power > right.power) {
          return false;
        } else {
          return name < right.name;
        }
      }
    };
};

int main()
{
  int n;
  string aCor;
  char aSize;
  string nome;
  vector<A> v;
  int j = 0;

  while (cin >> n) {
    if (n == 0) return 0;
    if (j != 0) cout << "\n";

    for(int i=0; i < n; ++i) {
      // cout << "N: " << n << endl;
      cin.clear();
      getline(cin, nome);
      // std::cout << "nome: " << nome << endl;
      getline(cin, nome);
      // std::cout << "nome: " << nome << endl;
      cin >> aCor;
      cin >> aSize;
      // std::cout << "cor: " << aCor << endl;
      // std::cout << "size: " << aSize << endl;

      A tmp;
      tmp.color = aCor;
      tmp.Asize = aSize;
      tmp.name = nome;

      if (aSize == 'P') {
        tmp.power = 1;
      } else if (aSize == 'M') {
        tmp.power = 2;
      } else if (aSize == 'G') {
        tmp.power = 3;
      } else {
        cout << "BUG" << endl;
      }

      v.push_back(tmp);

    }

    sort(v.begin(), v.end());
    for (auto it : v) {
      cout << it.color << " " << it.Asize << " " << it.name << endl;
    }

    v.clear();
    ++j;
  }

  return 0;
}
