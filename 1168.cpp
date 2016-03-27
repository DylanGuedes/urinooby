#include <iostream>

using namespace std;

int main()
{
  int n;
  string s1;
  int total = 0;

  cin >> n;
  for (int i=0 ; i < n; ++i) {
    total = 0;
    cin >> s1;
    for (auto it : s1) {
      if (it == '1') {
        total += 2;
      } else if (it == '2') {
        total += 5;
      } else if (it == '3') {
        total += 5;
      } else if (it == '4') {
        total += 4;
      } else if (it == '5') {
        total += 5;
      } else if (it == '6') {
        total += 6;
      } else if (it == '7') {
        total += 3;
      } else if (it == '8') {
        total += 7;
      } else if (it == '9') {
        total += 6;
      } else if (it == '0') {
        total += 6;
      }
    }

    cout << total << " leds" << endl;
  }
  return 0;
}
