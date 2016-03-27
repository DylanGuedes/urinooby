#include <iostream>
#include <map>

using namespace std;

int main()
{
  int num;
  map<int, string> mmap;

  mmap.insert(pair<int, string>(61, "Brasilia"));
  mmap.insert(pair<int, string>(71, "Salvador"));
  mmap.insert(pair<int, string>(11, "Sao Paulo"));
  mmap.insert(pair<int, string>(21, "Rio de Janeiro"));
  mmap.insert(pair<int, string>(32, "Juiz de Fora"));
  mmap.insert(pair<int, string>(19, "Campinas"));
  mmap.insert(pair<int, string>(27, "Vitoria"));
  mmap.insert(pair<int, string>(31, "Belo Horizonte"));

  cin >> num;
  auto it = mmap.find(num);
  if (it == mmap.end()) {
    cout << "DDD nao cadastrado" << endl;
  } else {
    cout << it->second << endl;
  }
  return 0;
}
