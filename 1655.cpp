#include <iostream>
#include <cstring>

using namespace std;

double dist[150][150];

void floyd_warshall(int n)
{
    for (int k=0; k < n; ++k) {
        for (int i=0; i < n; ++i) {
            for (int j=0; j < n; ++j) {
                if (i != j) {
                    if (dist[i][j] > dist[i][k] * dist[k][j])
                        dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }
}

int main()
{
    int n, m, origin, destiny;
    double weight;
    while (cin >> n >> m) {
        for (int i=0; i < n+1; ++i) {
            for (int j=0; j < n+1; ++j) {
                dist[i][j] = 20000000.0;
            }
            dist[i][i] = 0;
        }

        for (int i=0; i < m; ++i) {
            cin >> origin >> destiny >> weight;
            dist[origin-1][destiny-1] = weight * 0.01;
            dist[destiny-1][origin-1] = weight * 0.01;
        }

        floyd_warshall(n);

        for (int i=0; i < n+1; ++i) {
            for (int j=0; j < n+1; ++j) {
                printf("[%d][%d] => %f\n", i, j, dist[i][j]);
            }
        }

        printf("%f\n", dist[0][n-1]);
    }
    return 0;
}
