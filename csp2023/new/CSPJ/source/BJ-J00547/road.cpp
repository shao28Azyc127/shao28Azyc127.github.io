#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100001];
int a[100001];
int f[10000][10000];
int dis;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i = 1;i < n;i++)
    {
        cin >> v[i];
        dis += v[i];
    }
    for (int i = 1;i < n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= dis;j++)
        {
            for (int k = 0;k <= 9;k++)
            {
                f[i][j] = max(f[i-1][j],f[i][j-k*v[i]]+k*a[i]);
            }
        }
    }
    cout << f[n][dis] - 2;
    return 0;
}