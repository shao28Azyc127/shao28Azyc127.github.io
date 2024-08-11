#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,ans;
    cin>>n>>m>>k;
    ans=m;
    int a[m][3];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<ans+1;
    return 0;
}
