#include <iostream>
using namespace std;
int a[10],b[10],c[10],d[10],e[10];
bool chk1(int i,int j,int k,int l,int m,int o)
{
    if ((i == a[o]) + (j == b[o]) + (k == c[o]) + (l == d[o]) + (m == e[o]) == 4)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }
    if (n == 1)
    {
        cout << 81;
        return 0;
    }
    int cnt = 0;
    for (int i = 0;i <= 9;i++)
    for (int j = 0;j <= 9;j++)
    for (int k = 0;k <= 9;k++)
    for (int l = 0;l <= 9;l++)
    for (int m = 0;m <= 9;m++)
    {
        bool f = 1;
        for (int x = 1;x <= n;x++)
        {
            if (!chk1(i,j,k,l,m,x)) f = 0;
        }
        cnt += f;
    }
    cout << cnt;
    return 0;
}