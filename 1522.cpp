#include <iostream>
#include <queue>

using namespace std;

bool possible;

bool solve(queue<int> myq[3])
{
    if (myq[0].empty() && myq[1].empty() && myq[2].empty()) {
        possible = true;
    }

    vector< pair< vector<int>, int> > myv;
    if (not myq[0].empty()) {
        myv.push_back(make_pair( vector<int> {1}, myq[0].front()));

        if (not myq[1].empty()) {
            myv.push_back(make_pair( vector<int> {1, 2}, myq[0].front()+myq[1].front()));
            if (not myq[2].empty()) {
                myv.push_back(make_pair( vector<int> {1, 2, 3}, myq[0].front()+myq[1].front()+myq[2].front()));
                myv.push_back(make_pair( vector<int> {1, 3}, myq[0].front()+myq[2].front()));
            }
        } else if (not myq[2].empty()) {
            myv.push_back(make_pair( vector<int> {1, 3}, myq[0].front()+myq[2].front()));
        }
    } else if (not myq[1].empty()) {
        myv.push_back(make_pair( vector<int> {2}, myq[1].front()));
        if (not myq[2].empty()) {
            myv.push_back(make_pair( vector<int> {2, 3}, myq[1].front()+myq[2].front()));
        }
    } else if (not myq[2].empty()) {
        myv.push_back(make_pair( vector<int> {3}, myq[2].front()));
    }

    for (auto it : myv) {
        if ((it.second % 3) == 0) {
            queue<int> aux[3];

            for (auto node : it.first) {
                aux[node-1].push(myq[node-1].front());
                myq[node-1].pop();
            }

            solve(myq);
            for (auto node : it.first) {
                myq[node-1].push(aux[node-1].front());
            }
        }
    }
}

int main()
{
    int n;
    int a, b, c;
    while (cin >> n) {
        if (n == 0) return 0;
        queue<int> myq[3];
        for (int i=0; i < n; ++i) {
            cin >> a >> b >> c;
            myq[0].push(a);
            myq[1].push(b);
            myq[2].push(c);
        }

        possible = false;
        solve(myq);

        if (possible)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
