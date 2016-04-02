#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  int n, k;
  int pSize;
  int auxNum;
  vector< vector<int> > mygraph;

  cin >> n >> k;
  for (int i=0; i < 9; ++i) {
    vector<int> myv;
    mygraph.push_back(myv);
  }

  for (int i=0; i < k; ++i) {
    cin >> pSize;
    for (int j=0; j < pSize; ++j) {
      cin >> auxNum;
      mygraph[i].push_back(auxNum);
    }
  }
  return 0;
}
