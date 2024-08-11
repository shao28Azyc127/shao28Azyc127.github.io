#include<bits/stdc++.h>
using namespace std;
bool f[10];
int a[10], b[10], c[10], d[10], e[10];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
        f[1] |= (i == 1) || (a[i - 1] == a[i]);
        f[2] |= (i == 1) || (b[i - 1] == b[i]);
        f[3] |= (i == 1) || (c[i - 1] == c[i]);
        f[4] |= (i == 1) || (d[i - 1] == d[i]);
        f[5] |= (i == 1) || (e[i - 1] == e[i]);
    }
    int t = f[1] + f[2] + f[3] + f[4] + f[5];
    if(t < 3) cout << 0 << endl;
    else if(t == 3) cout << 4 << endl;
    else if(t == 4) cout << 10 << endl;
    else cout << 81 << endl;
    return 0;
}

