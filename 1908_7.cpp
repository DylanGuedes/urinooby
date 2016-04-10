#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int visited[10010];
vector<int> friends[10010];
int n;

bool friend_of(int a1, int a2)
{
  if (find(friends[a1].begin(), friends[a1].end(), a2) == friends[a1].end()) {
    return true;
  } else {
    return false;
  }
}

void connect(int a1, int a2)
{
  cout << "loop de connect" << endl;
  friends[a1].push_back(a2);
  friends[a2].push_back(a1);

  for (int i=0; i < n; ++i) {
    if (friend_of(a1, i) &&  !(friend_of(a2, i))) {
      connect(a2, i);
    }

    if (friend_of(a2, i) && !(friend_of(a1, i))) {
      connect(a1, i);
    }
  }
}

long long int bfs(int start, int destiny)
{
  queue< pair<int, long long int> > myq;
  myq.push(pair<int, long long int>(start, 0));

  visited[start] = 1;

  while (not myq.empty()) {
    int v1 = myq.front().first;
    long long int v2 = myq.front().second;
    // cout << "v2: " << v2 << endl;

    myq.pop();

    visited[v1] = 1;

    if (v1 == destiny) {
      // cout << "v1 == destiny" << endl;
      return v2;
    }

    for (auto it : friends[v1]) {
      if (visited[it] == 0) {
        // cout << "push em "<<  it << endl;
        myq.push(pair<int, long long int>(it, v2+1));
        // visited[it] = 1;
      }
    }
  }
}

void print_grid(int n)
{
  for (int i=0; i < n; ++i) {
    if (not friends[i].empty()) {
      for (auto it : friends[i]) {
        cout << it << " ";
      }
      cout << "\n";
    } else {
      cout << "/0" << endl;
    }
  }
  cout << "\n";
}

int main()
{
  int k;
  int auxI;
  int l;

  memset(visited, 0, sizeof visited);

  cin >> n >> k;
  vector<int> myv;


  for (int i=0; i < k; ++i) {
    cin >> l;
    myv.clear();

    for (int w=0; w < l; ++w) {
      cin >> auxI;
      // cout << "myv push_back(" << auxI-1 << ")" << endl;
      myv.push_back(auxI-1);
    }
    cout << "myv:" << endl;
    for (auto it : myv) {
      cout << it << " ";
    }
    cout << "\n";
    //
    cout << "myv.size:" << myv.size() << endl;
//
    for (int w=0; w < myv.size(); ++w) {
      for (int w2=w; w2 < myv.size(); ++w2) {
        if (w != w2) {
          // cout << w << " != " << w2 << endl;
          // cout << "find(friends[" << myv[w] << "].begin()" << endl;
          // cout << "friends[" << myv[w] << "].push_back(" << myv[w2] <<")" << endl;
          connect(myv[w], myv[w2]);
            // friends[myv[w]].push_back(myv[w2]);
            // friends[myv[w2]].push_back(myv[w]);
        }
      }
    }
  }
  long long int ans = 0;
  ans = bfs(0, n-1);
  // cout << "0 até " << n-1 << endl;
  cout << ans << endl;
  return 0;
}
