#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,i,j,k,fans=1e9;
struct tree
{
    ll a,b,c;
}x[100009];
bool check(ll xx)
{
    for(i=1;i<=n;i++)
    {
        ll grow=x[i].b*xx+(i*xx+xx*(xx-1)/2)*x[i].c;
        if(grow<x[i].a) return 0;
    }
    return 1;
}
void solve2()
{
    ll ans=0,l=1,r=1e9;
    while(l<=r)
    {
        ll mid=l+r>>1;
     //   cout<<l<<" "<<r<<endl;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    fans=min(fans,ans);
}
bool cmp(tree x,tree y)
{
    return x.c<y.c;
}
bool cmp2(tree x,tree y)
{
    return x.a<y.a;
}
bool cmp3(tree x,tree y)
{
    return x.b<y.b;
}
void solve1()
{
    sort(x+1,x+n+1,cmp);
    solve2();
    sort(x+1,x+n+1,cmp2);
    solve2();
    sort(x+1,x+n+1,cmp3);
    solve2();
    cout<<fans;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    bool flg1,flg2;
    flg1=flg2=1;
    for(i=1;i<=n;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        x[i]={u,v,w};
    }
    for(i=1;i<n;i++)
    {
        ll u,v,w;
        cin>>u>>v;
        flg1&=(u==1);
        flg2&=(u==i&&v==i+1);
    }
    if(flg2)
    {
        solve2();
        cout<<fans;
    }
    else if(flg1) solve1();
    return 0;
}
