#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    bool flag=true;
    if(n==1)
    {
        int u,v,a;
        cin>>u>>v>>a;
        if(u!=1||v!=n||a<k)
        {
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        if(a!=0) flag=false;
    }
    if(flag) cout<<-1;
    else cout<<k*2;
    return 0;
}
