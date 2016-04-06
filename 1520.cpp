#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  vector<int> myv;

  int query;
  int auxX, auxY;

  while (cin >> n) {
    myv.clear();
    for (int i=0; i < n; ++i) {
      cin >> auxX;
      cin >> auxY;

      for (int j=auxX; j <= auxY; ++j) {
        myv.push_back(j);
      }
    }

    sort(myv.begin(), myv.end());
    // cout << "myv: " << endl;
    // for (auto it : myv) {
    //   cout << it << " ";
    // }
    // cout << endl;

    int start = -1;
    int end = -1;

    cin >> query;
    int auxLength = myv.size();
    for (int i=0; i < auxLength; ++i) {
      if (myv[i] == query) {
        start = i;
        end = start-1;
        for (int j=i; j < auxLength; ++j) {
          if (myv[j] == query) {
            end++;
          } else {
            break;
          }
        }
        break;
      }
    }

    if (end == -1) {
      end = start;
    }

    if (start == -1) {
      cout << query << " not found" << endl;
    } else {
      cout << query << " found from " << start << " to " << end << endl;
    }
  }

  return 0;
}
