#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
  map<string, int> occr;
  int n;
  string name;

  cin >> n;
  getline(cin, name);
  getline(cin, name);

  for (int i=0; i < n; ++i) {
    occr.clear();
    if (i != 0) cout << "\n";
    int length = 0;
    while(getline(cin, name)) {
      if (name == "") {
        break;
      }

      auto it = occr.find(name);
      if (it == occr.end()) {
        occr.insert(pair<string, int>(name, 1));
      } else {
        it->second += 1;
      }
      length += 1;
    }

    // cout << "length: " << length << endl;
    for (auto it : occr) {
      // cout << "second: " << it.second << endl;
      // cout << "length: " << length << endl;
      double result = it.second * 100.0;
      double result2 = length;
      double result3 = result / result2;
      printf("%s %.4f\n", it.first.c_str(), result3);
    }
  }

  return 0;
}
