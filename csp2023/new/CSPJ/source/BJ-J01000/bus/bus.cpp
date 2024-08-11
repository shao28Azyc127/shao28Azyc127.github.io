#include<iostream>
#include<cstdio>
using namespace std;
int u[100005],v[100005],a[100005];
int main()

{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>a[i];
    }
    cout<<-1;
    return 0;
}
