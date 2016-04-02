#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int friendships[21][21];
int scores[21];
int msg_sheet[21];
string names[21];

struct Msg {
  string a1;
  string a2;
  string a3;
  int t1;
  int t2;
};

int main()
{
  int n;
  int aux_i;
  int a_t1, a_t2;
  string msg1, msg2, msg3;
  vector<Msg> msgarr;
  int spam_counter = 0;

  while (cin >> n) {
    if (n == 0) break;

    msgarr.clear();
    spam_counter = 0;
    memset(friendships, 0, sizeof friendships);
    memset(scores, 0, sizeof scores);
    memset(msg_sheet, 0, sizeof msg_sheet);

    for (int i=0; i < n; ++i) {
      friendships[i][i] = 1;
      while(cin  >> aux_i) {
        if (aux_i == 0) {
          break;
        } else {
          friendships[i][aux_i-1] = 1;
          msg_sheet[i] += 1;
        }
      }
    }

    while (cin >> aux_i) {
      if (aux_i == 0) break;
      Msg newmsg;
      cin >> a_t1;
      cin >> a_t2;

      cin >> msg1;
      cin >> msg2;
      cin >> msg3;

      newmsg.a1 = msg1;
      newmsg.a2 = msg2;
      newmsg.a3 = msg3;
      newmsg.t1 = a_t1;
      newmsg.t2 = a_t2;

      msgarr.push_back(newmsg);
      spam_counter ++;
    }

    for (int i=0; i < n; ++i) {
      cin >> names[i];
    }

    for (int i=0; i < n; ++i) {
      cout << names[i] << ":";
      for (int j=0; j < spam_counter; ++j) {
        // cout << "score: " << scores[i] << " t1: " << msgarr[j]->t1 << " t2: " << msgarr[j]->t2 << endl;
        cout << " ";
        if (msg_sheet[i] < msgarr[j].t1) {
          cout << msgarr[j].a1;
        } else if ((msg_sheet[i] >= msgarr[j].t1) && (msg_sheet[i] < msgarr[j].t2)) {
          cout << msgarr[j].a2;
        } else {
          cout << msgarr[j].a3;
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
