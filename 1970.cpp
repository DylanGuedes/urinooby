#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define repd(i, j)for(int i=j;i>=0;i--)
int arr[110];
int dp[3][55][55][55];

int n, k;

int main()
{
        ios::sync_with_stdio(false);
        cin >> n>> k;
        repi(i, 0, n)
                cin >> arr[i];

        memset(dp, 0, sizeof dp);
        int hav[3];

        repi(i, 0, 3)
                hav[i]=0;

        repi(i,0,k)
                cin >> hav[i];

        repd(i, n-1) {
                repd(r0, hav[0]+1) {
                        bool skip_r1 = false;
                        repd(r1, hav[1]+1) {
                                repd(r2, hav[2]+1) {
                                        vector<int> myv;
                                        myv.push_back(dp[1][r0][r1][r2]);

                                        if (r0>=arr[i])
                                                myv.push_back(arr[i]+dp[1][r0-arr[i]][r1][r2]);

                                        if (r1>=arr[i])
                                                myv.push_back(arr[i]+dp[1][r0][r1-arr[i]][r2]);
                                        else {
                                                skip_r1 = true;
                                        }

                                        if (r2>=arr[i])
                                                myv.push_back(arr[i]+dp[1][r0][r1][r2-arr[i]]);
                                        else {
                                                dp[0][r0][r1][r2] = *max_element(myv.begin(), myv.end());
                                                if (skip_r1) {
                                                        repi(k, 0, r1+1)
                                                                dp[0][r0][k][r2] = dp[0][r0][r1][r2];
                                                }
                                                break;
                                        }

                                        dp[0][r0][r1][r2] = *max_element(myv.begin(), myv.end());
                                        if (skip_r1 && r2==0) {
                                                if (skip_r1) {
                                                        repi(k, 0, r1+1)
                                                                dp[0][r0][k][r2] = dp[0][r0][r1][r2];
                                                }
                                        }
                                }
                                if (skip_r1) {
                                        break;
                                }
                        }
                }
                swap(dp[0], dp[1]);
        }


        cout << dp[1][hav[0]][hav[1]][hav[2]] << "\n";

        return 0;
}
