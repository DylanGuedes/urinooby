#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
  int n;
  int aux_i;
  map<string, double> mymap;
  string aux_s;
  double aux_d;
  double total = 0;
  cin >> n;
  for (int w=0; w < n; ++w) {
    mymap.clear();
    total = 0;
    int m;
    int p;
    cin >> m;
    for (int i=0; i < m; ++i) {
      cin >> aux_s;
      cin >> aux_d;

      mymap.insert(pair<string, double>(aux_s, aux_d));
    }

    // cout << "mapa:" << endl;
    // for (auto it : mymap) {
    //   cout << it.first << " => " << it.second << endl;
    // }
    // cout << "fim do mapa" << endl;

    cin >> p;
    // cout << "p: " << p << endl;
    for (int i=0; i < p; ++i) {
      cin >> aux_s;
      cin >> aux_i;

      for(int j=0; j < aux_i; ++j) {
        total += mymap[aux_s];
        // cout << "total: " << total << endl;
      }
    }

    printf("R$ %.2f\n", total);
  }
  return 0;
}
