#include<iostream>
#include<stdio.h>
#include<cmath>
#define int long long
using namespace std;
int t, m, a, b, c;
signed main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        int d = b * b - 4 * a * c;
        if(d < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << (sqrt(d) - b) / (2 * a) << endl;
    }
    return 0;
}
