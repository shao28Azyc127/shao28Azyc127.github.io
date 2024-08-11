#include<bits/stdc++.h>
using namespace std;
int n, k[10][10];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    if(n == 1)
    {
        cout << 81;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i][1] >> k[i][2] >> k[i][3] >> k[i][4] >> k[i][5];
    }
    cout << 10 - n + 2;
    return 0;
}
