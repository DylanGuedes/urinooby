#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

string grid[510];
int visiteds[510][510];

pair<int, int> get_first_non_zero(int n, int m)
{
  for (int i=0; i < n; ++i) {
    for (int j=0; j < m; ++j) {
      if (grid[i][j] == '.') {
        return pair<int, int>(i, j);
      }
    }
  }
}

struct position {
  int x;
  int y;
};

pair<int, int> bfs2(pair<int, int> origin, int n, int m)
{
  queue< pair<position, int> > myq;

  position actual_position { origin.first, origin.second };
  myq.push(pair<position, int>(actual_position, 0));
  pair<int, int> best_position;

  while (not myq.empty()) {
    int x = myq.front().first.x;
    int y = myq.front().first.y;
    int actual_length = myq.front().second;
    best_position.first = x;
    best_position.second = y;

    myq.pop();

    vector<pair<int, int> > myv;
    myv.push_back(pair<int, int>(x+1, y));
    myv.push_back(pair<int, int>(x-1, y));
    myv.push_back(pair<int, int>(x, y+1));
    myv.push_back(pair<int, int>(x, y-1));

    // cout << "loop" << endl;

    int mylength = myv.size();

    for (int i=0; i < mylength; ++i) {
      // cout << "antes do if" << endl;
      // cout << "myv[i]: " << myv[i].first << " " << myv[i].second << endl;
      if (myv[i].first >= 0 && myv[i].second >= 0 && myv[i].first < n && myv[i].second < m && visiteds[myv[i].first][myv[i].second] == 0) {
        if (grid[myv[i].first][myv[i].second] == '.') {
        // cout << "dando push em " << myv[i].first << " " << myv[i].second << endl;
          visiteds[myv[i].first][myv[i].second] = 1;
          actual_position.x = myv[i].first;
          actual_position.y = myv[i].second;
          myq.push(pair<position, int>(actual_position, actual_length+1));
        }
      }
    }
  }

  return best_position;
}

int bfs(pair<int, int> origin, int n, int m)
{
  queue< pair<position, int> > myq;

  position actual_position { origin.first, origin.second };
  myq.push(pair<position, int>(actual_position, 0));
  int max_distance = 0;

  while (not myq.empty()) {
    int x = myq.front().first.x;
    int y = myq.front().first.y;
    int actual_length = myq.front().second;
    // cout << "x: " << x << ", y: " << y << ", length: " << actual_length << endl;

    myq.pop();

    vector<pair<int, int> > myv;
    myv.push_back(pair<int, int>(x+1, y));
    myv.push_back(pair<int, int>(x-1, y));
    myv.push_back(pair<int, int>(x, y+1));
    myv.push_back(pair<int, int>(x, y-1));

    int mylength = myv.size();

    for (int i=0; i < mylength; ++i) {
      if (myv[i].first >= 0 && myv[i].second >= 0 && myv[i].first < n && myv[i].second < m && visiteds[ myv[i].first][myv[i].second] == 0) {
        if (grid[myv[i].first][myv[i].second] == '.') {
          visiteds[myv[i].first][myv[i].second] = 1;
          actual_position.x = myv[i].first;
          actual_position.y = myv[i].second;
          myq.push(pair<position, int>(actual_position, actual_length+1));
          max_distance = max(max_distance, actual_length+1);
        }
      }
    }
  }

  return max_distance;
}

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) return 0;
    memset(visiteds, 0, sizeof visiteds);

    for (int i=0; i < n; ++i) {
      cin >> grid[i];
    }

    pair<int, int> first_non_zero = get_first_non_zero(n, m);

    pair<int, int> sol1 = bfs2(first_non_zero, n, m);
    memset(visiteds, 0, sizeof visiteds);
    // cout << "SOL1:" << endl;
    // cout << sol1.first << " " << sol1.second << endl;
    int sol2 = bfs(sol1, n, m);
    cout << sol2 << endl;
  }
  return 0;
}
