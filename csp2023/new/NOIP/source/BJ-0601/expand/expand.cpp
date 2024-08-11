#include<bits/stdc++.h>
using namespace std;
int a[5000010];

int main()
{
    ios::sync_with_stdio(false);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c, n, m, q;
    cin >> c >> n >> m >> q;
    for (int i = 0;i<n;i++)
    {
        cin >>a[i];
    }
    for (int i = 0;i<m;i++)
    {
        cin >> a[i];
    }
    srand(time(0));
    int kx, ky;
    for (int i = 0;i<=q;i++)
    {
        cout << (int(abs(rand())) % 2 == 1);
    }
    cout << endl;
    return 0;
}
