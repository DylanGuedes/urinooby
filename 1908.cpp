#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solve(map<int, vector<int> > mmap)
{
  
}

int main()
{
  map<int, vector<int> > campis;
  int n, k;
  int total_campis;
  int nAux;

  cin >> n;
  cin >> k;

  for (int i=0; i < n; ++i) {
    vector<int> v;
    campis.insert(pair<int, vector<int> >(i+1, v));
  }


  for (int i=0; i < k; ++i) {
    cin >> total_campis;
    vector<int> v;
    for (int j=0; j < total_campis; ++j) {
      cin >> nAux;
      v.push_back(nAux);
    }

    cout << "vector inspect:" << endl;
    for (auto it : v) {
      cout << it << endl;
    }

    for (int j=0; j < total_campis; ++j) {
      for (int j1 = 0; j1 < total_campis; ++j1) {

        if (j1 != j) {
          auto it = campis.find(v[j]);
          if (it != campis.end()) {
            if (find(it->second.begin(), it->second.end(), v[j1]) == it->second.end()) {
              it->second.push_back(v[j1]);
              cout << it->first << " dando push em " << v[j1] << endl;
            }
          }
        }
      }
    }
  }

  cout << "connections: " << endl;
  for (auto it : campis) {
    cout << it.first << " : ";
    sort(it.second.begin(), it.second.end());
    for (auto it2 : it.second) {
      cout << it2 << " ";
    }
    cout << endl;
  }


  return 0;
}
