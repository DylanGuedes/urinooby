#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct A
{
  string name;
  double price;
  int priority;
};

bool myfunc(A a1, A a2)
{
  if (a1.priority > a2.priority) {
    return true;
  } else if (a1.priority < a2.priority) {
    return false;
  } else {
    if (a1.price == a2.price) {
      return a1.name < a2.name;
    } else {
      return a1.price < a2.price;
    }
  }
}


int main()
{
  string nome;
  int n;
  string tmp_name;
  double tmp_price;
  int tmp_priority;
  int counter = 0;

  vector<A> myv;
  A a;

  while (cin >> nome) {
    myv.clear();
    cin >> n;

    for (int i=0; i < n; ++i) {
      getline(cin, tmp_name);
      getline(cin, tmp_name);
      cin >> tmp_price;
      cin >> tmp_priority;

      a.name = tmp_name;
      a.price = tmp_price;
      a.priority = tmp_priority;

      myv.push_back(a);
    }


    sort(myv.begin(), myv.end(), myfunc);

    cout << "Lista de " << nome << endl;
    for (auto it : myv) {
      printf("%s - R$%.2f\n", it.name.c_str(), it.price);
    }

    printf("\n");
  }
  return 0;
}
