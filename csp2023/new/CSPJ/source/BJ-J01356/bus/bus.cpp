#include <bits/stdc++.h>
using namespace std;
int a[20001][20001]={1<<30},n,m,k,ui,vi,ai;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        cin>>ui>>vi>>ai;
        a[ui][vi]=1;
    }
    for (int l=1;l<=n;l++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (a[i][l]+a[l][j]<a[i][j])
                    a[i][j]=a[i][l]+a[l][j];
    if (a[1][n]>=1<<30)
    {
        cout<<-1;
        return 0;
    }
    cout<<a[1][n]+(k-a[1][n]%k);
}
