#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
   freopen("road.out", "w", stdout);

    int n, d, money=0, i=0;
    double oil=0;
    cin >> n >> d;

    int len[n-1], v[n], sum[n-1];
    for (int i=0; i<n-1; i++)
        cin >> len[i];
    for (int i=0; i<n; i++)
        cin >> v[i];

    sum[n-2] = len[n-2];
    for (int i=n-3; i>=0; i--)
        sum[i] = sum[i+1] + len[i];

    while (i < n-1) {
        int r=0;
        if (v[i] < v[i+1] && i+1<n-1) {
            int j=i+1;
            while (v[i]<v[j] && j<n-1) {
                r += len[j-1];
                j++;
            }

            if (r % d == 0) {
                money += (r)/d * v[i];

            }
            else {
                money += ((r)/d+1) * v[i];

            }

            i = j-1;
        }
        else {
            if (len[i] % d == 0) {
                money += len[i]/d * v[i];

            }
            else {
                money += (len[i]/d+1) * v[i];

            }
            i++;
        }
        //cout << i << ' ' << money << '\n';
    }

    cout << money;
    return 0;
}
