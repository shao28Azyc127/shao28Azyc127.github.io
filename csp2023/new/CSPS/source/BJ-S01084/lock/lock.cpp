#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1145141919810;
const ll mod=998244353;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n;
ll a[11][5];
ll x[5];
ll ans=0;
void check()
{
    for(int i=1;i<=n;i++)
    {
        ll cnt=0,pos1=0,pos2=0;
        for(int j=0;j<=4;j++)
        {
            if(x[j]!=a[i][j])
            {
                cnt++;
                if(cnt==1)pos1=j;
                if(cnt==2)pos2=j;
            }
        }
        if(cnt==0)return;
        if(cnt>2)return;
        if(cnt==1)continue;
        if(cnt==2)
        {
            ll x1=(x[pos1]-a[i][pos1]+10)%10;
            ll x2=(x[pos2]-a[i][pos2]+10)%10;
            if(x1!=x2)return;
            if(pos1!=pos2-1)return;
        }
    }
    ans++;
}
void dfs(ll pos)
{
    if(pos>=5){check();return;}
    for(int i=0;i<=9;i++)
    {
        x[pos]=i;
        dfs(pos+1);
    }
}
void solve()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=4;j++)a[i][j]=read();
    }
    dfs(0);
    cout<<ans<<'\n';
    return;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
//    clock_t start=read();
    ll t=1;
    while(t--)solve();
//    clock_t end=read();
//    cout<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}