#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll v[N],c[N];
ll n,d;
ll hao(ll x)
{
    if(x<0)
        return 0;
    else if(x%d==0)
        return x/d;
    else
        return x/d+1;
}
void test_hao();
ll dfs(ll p,ll s,ll o)
{
    //cout<<p<<" "<<s<<" "<<o<<endl;
    if(p==n)
        return s;
    for(ll i=p+1;i<=n;i++)
    {
        if(c[i]<c[p])
        {
            ll h=hao(v[i]-v[p]-o);
            return dfs(i,s+h*c[p],h*d+o-(v[i]-v[p]));
        }
    }
    ll h=hao(v[n]-v[p]-o);
    return dfs(n,s+h*c[p],h*d+o-(v[n]-v[p]));
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(ll i=1;i<n;i++)
    {
        ll x;
        cin>>x;
        v[i+1]=v[i]+x;
        //cout<<v[i]<<" ";
    }
    //cout<<endl;
    for(ll i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    cout<<dfs(1,0,0);
    return 0;
}
void test_hao()
{
    assert(hao(16)==4);
    assert(hao(17)==5);
    assert(hao(0)==0);
    cout<<"hao ok!"<<endl;
}
