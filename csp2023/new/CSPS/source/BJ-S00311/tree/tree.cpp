#include <iostream>
#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
using namespace std;
struct place
{
    ll a,b,c,d;
}t[maxn];
int n,u,v;
ll ans;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].a>>t[i].b>>t[i].c;
        t[i].d=(ll)ceil((double)t[i].a/t[i].b);
    }
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
    }
    ans=n;
    for(int i=1;i<=n;i++) ans=max(ans,t[i].d);
    cout<<ans;
    return 0;
}
