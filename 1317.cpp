#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int friendship[21][21];
string names[21];
int visiteds[21];
int friendship_count[21];
vector< vector<string> > msgs;
int spam_count[21];

void get_friendship_count(int n)
{
  for (int i=0; i < n; ++i) {
    for (int j=0; j < n; ++j) {
      if (i != j && friendship[i][j] == 1) {
        friendship_count[i] += 1;
      }
    }
  }
}

void bfs(int idx, int n)
{
  visiteds[idx] = 1;
  queue<int> myq;
  myq.push(idx);

  while (not myq.empty()) {
    int aux = myq.front(); myq.pop();
    for (int i=0; i < n; ++i) {
      if (friendship[aux][i] == 1 && visiteds[i] == 0) {
        visiteds[i] = 1;
        myq.push(i);
      }
    }
  }
}

void update_count(int n)
{
  for (int i=0; i < n; ++i) {
    if (visiteds[i]) {
      spam_count[i] += friendship_count[i];
    }
  }
}

int main()
{
  int n;
  int aux_i;
  int otherI;
  int source;
  int total_msgs;
  int t1, t2;
  string a1, a2, a3;

  while (cin >> n) {
    if (n == 0) break;
    total_msgs = 0;
    msgs.clear(); // limpo caso de teste
    memset(friendship, 0, sizeof friendship); // reseto ligaçoes
    for (int w=0; w < n; ++w) {
      cin >> aux_i;
      while (aux_i != 0) {
        friendship[w][aux_i-1] = 1;
        cin >> aux_i;
      }
    }

    memset(friendship_count, 0, sizeof friendship_count);
    get_friendship_count(n);

    cin >> source;

    while (source != 0) {
      source -= 1;
      // cout << "source: " << source << endl;
      memset(visiteds, 0, sizeof visiteds);
      memset(spam_count, 0, sizeof spam_count);
      cin >> t1;
      cin >> t2;
      cin >> a1;
      cin >> a2;
      cin >> a3;

      bfs(source, n);
      update_count(n);

      for (int i=0; i < n; ++i) {
        vector<string> aux_v;
        msgs.push_back(aux_v);
        if (spam_count[i] < t1) {
          msgs[i].push_back(a1);
        } else if (spam_count[i] >= t1 && spam_count[i] < t2) {
          msgs[i].push_back(a2);
        } else {
          msgs[i].push_back(a3);
        }
      }

      total_msgs += 1;
      cin >> source;
    }

    for (int i=0; i < n; ++i) {
      cin >> names[i];
    }

    // solve
    for (int i=0; i < n; ++i) {
      cout << names[i] << ": ";
      for (int j=0; j < total_msgs; ++j) {
        cout << msgs[i][j];
        cout << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
