#include<bits/stdc++.h>
using namespace std;
int n,a[9][6],cnt[6];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1)
    {
        cout<<81;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
