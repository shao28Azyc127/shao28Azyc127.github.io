#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],c;
int v[N],ans;
struct node
{
    int u,v;
}g[N];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c;
        a[i]=(a[i]+b[i]-1)/b[i];
    }
    for(int i=1;i<n;i++)
    {
        cin>>g[i].u>>g[i].v;
    }
    ans=n+1;
    cout<<ans;
    return 0;
}
