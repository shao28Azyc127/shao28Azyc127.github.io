#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[100005];
int q[100005];
int r[100005];
int n,d;
ll km=0;
ll sh(ll x,int y)
{
    if(x%y==0)
        return x/y;
    return x/y+1;
}
ll solve(int x)
{
    if(x==1)
        return 0;
    ll y=solve(r[x]);
    if(km>=p[x]-p[r[x]])
    {
        km=km-p[x]+p[r[x]];
        return y;
    }
    y=y+sh(p[x]-p[r[x]]-km,d)*q[r[x]];
    km+=sh(p[x]-p[r[x]]-km,d)*d-p[x]+p[r[x]];
    return y;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<=n;i++)
    {
        p[i]+=p[i-1];
    }
    for(int j=1;j<=n;j++)
    {
        cin>>q[j];
    }
    r[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(q[i-1]<q[r[i-1]])
            r[i]=i-1;
        else
            r[i]=r[i-1];
    }
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<p[i]<<" ";
    //}
    //cout<<endl;
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<r[i]<<" ";
    //}
    //cout<<endl;
    cout<<solve(n);
    return 0;
}