#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,ans=0;
    cin>>t>>m;
    int a[t][3];
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    if(m<=1)
    {
        for(int i=1;i<=t;i++)
        {
            ans=0/a[i][1];
            cout<<sqrt(ans);
        }
    }

    return 0;
}
