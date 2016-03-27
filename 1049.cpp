#include <iostream>

using namespace std;

int main()
{
  string s1;

  cin >> s1;
  if (s1 == "vertebrado") {
    cin >> s1;
    if (s1 == "ave") {
      cin >> s1;
      if (s1 == "carnivoro") {
        cout << "aguia" << endl;
      } else {
        cout << "pomba" << endl;
      }
    } else {
      // mamifero
      //

      cin >> s1;
      if (s1 == "onivoro") {
        cout << "homem" << endl;
      } else {
        cout << "vaca" << endl;
      }
    }
  } else {
    // invertebrado
    cin >> s1;
    if (s1 == "inseto") {
      cin >> s1;
      if (s1 == "hematofago") {
        cout << "pulga" << endl;
      } else {
        cout << "lagarta" << endl;
      }
    } else {
      // anelideo
      cin >> s1;
      if (s1 == "hematofago") {
        cout << "sanguessuga" << endl;
      } else {
        cout << "minhoca" << endl;
      }
    }
  }

  return 0;
}
