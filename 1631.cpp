#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
using dd = pair<double, double>;

dd cer[110];
#define x first
#define y second

#define EPS 0.000001

bool equals(double a, double b)
{
        return abs(a-b) < EPS;
}

double D(dd a, dd b, dd c)
{
        return (a.x*b.y + a.y*c.x + b.x*c.y - c.x*b.y - c.y*a.x - b.x*a.y);
}

int main()
{
        int n;
        while (scanf("%d", &n)!=EOF) {
                if (not n)
                        return 0;
                FOR(i, 0, n) {
                        scanf("%lf", &cer[i].x);
                        scanf("%lf", &cer[i].y);
                }

                double diff = 1000000000.0;
                double a, b, c;
                FOR(i, 0, n) {
                        FOR(j, i+1, n) {
                                dd P = cer[i];
                                dd Q = cer[j];

                                a = P.y - Q.y;
                                b = Q.x - P.x;
                                c = P.x * Q.y - P.y * Q.x;
                                auto k = equals(a, 0) ? b : a;
                                a = a/k;
                                c = c/k;
                                b = b/k;
                                double dir = 0.0, esq = 0.0;
                                FOR(z, 0, n) {
                                        if (z==i || z==j)
                                                continue;
                                        dd R = cer[z];
                                        double val = D(P, Q, R);
                                        double dist = fabs(a*R.x+b*R.y+c)/hypot(a,b);
                                        if (equals(val, 0.0))
                                                continue;
                                        else if (val < 0)
                                                dir += dist;
                                        else if (val > 0+EPS)
                                                esq += dist;
                                }
                                diff = min(diff, fabs(dir-esq));
                        }
                }
                printf("%.3lf\n", diff);
        }
        return 0;
}

