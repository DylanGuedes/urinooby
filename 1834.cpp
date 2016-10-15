#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
int n;

using ll = long long;

class Point {
public:
        ll x, y;
        Point(ll d1, ll d2) : x(d1), y(d2) { }
};

class Planet {
public:
        ll x, y;
        ll h;
        Planet() : x(0),y(0),h(0) { }
};

Planet plan[1010];

ll D(Point A, Point B, Point C)
{
        return (A.x*B.y + A.y*C.x + B.x*C.y - (C.x*B.y + C.y*A.x + B.x*A.y));
}

int main()
{
        ios::sync_with_stdio(false);
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1);
        Point p2(x2, y2);
        cin >> n;
        FOR(i, 0, n) {
                cin >> plan[i].x >> plan[i].y >> plan[i].h;
        }
        cout << "Relatorio Vogon #35987-2" << "\n";
        double dist = hypot(p1.x-p2.x, p1.y-p2.y);
        cout << "Distancia entre referencias: " << fixed << setprecision(2) << dist+1e-10 << " anos-luz\n";
        pair<ll, ll> west;
        pair<ll, ll> east;
        west.first = 0;
        west.second = 0;
        east.first = 0;
        east.second = 0;

        int casu = 0;
        FOR(i, 0, n) {
                ll myd = D(p1, p2, Point(plan[i].x, plan[i].y));
                if (myd == 0)
                        casu++;
                else if (myd > 0) {
                        west.first++;
                        west.second+=plan[i].h;
                } else if (myd < 0) {
                        east.first++;
                        east.second+=plan[i].h;
                }
        }
        cout << "Setor Oeste:\n";
        cout << "- " << west.first << " planeta(s)\n";
        cout << "- " << west.second << " bilhao(oes) de habitante(s)\n";

        cout << "Setor Leste:\n";
        cout << "- " << east.first << " planeta(s)\n";
        cout << "- " << east.second << " bilhao(oes) de habitante(s)\n";
        cout << "Casualidades: " << casu << " planeta(s)\n";
        return 0;
}
