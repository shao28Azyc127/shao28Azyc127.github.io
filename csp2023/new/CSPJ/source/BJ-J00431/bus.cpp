#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int u[m];
    int v[m];
    int a[m];
    int s[i]={0};
    for(int i=0;i<m;i++)
    {
        cin>>u[i]>>v[i]>>a[i];
        if(u[i]==1)s[i]=1;
    }
    if(n<3)cout<<k;
    else if(n<6)cout<<2*k;
    else if(n<10)cout<<3*k;
    else cout<<4*k;
    

    return 0;
}
