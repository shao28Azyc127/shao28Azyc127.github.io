#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1145141919810;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline char readc()
{
    char ch=getchar();
    while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-'){ch=getchar();}
    return ch;
}
ll id;
ll n,m,k,d;
vector<vector<pll> >v(100005);
ll c[1005][1005],f[1005][1005];
void solve()
{
    n=read(),m=read(),k=read(),d=read();
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=1;i<=m;i++)
    {
        ll x=read(),y=read(),val=read();
        v[x].push_back({y,val});
    }
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        ll p=0,sz=v[i].size();
        for(int j=1;j<=k;j++)
        {
            c[i][j]=c[i][j-1];
            while(p<sz&&v[i][p].first<=j)c[i][j]+=v[i][p].second,p++;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            f[i][j]=-inf;
        }
    }
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)
            {
                for(int p=0;p<=k;p++)f[i][j]=max(f[i][j],f[i-1][p]);
                continue;
            }
            f[i][j]=f[i-1][j-1]-d+c[i][j];
        }
    }
    ll res=-inf;
    for(int i=0;i<=k;i++)res=max(res,f[n][i]);
    cout<<res<<'\n';
    return;
}
void solve1()
{
    n=read(),m=read(),k=read(),d=read();
    ll res=0;
    for(int i=1;i<=m;i++)
    {
        ll x=read(),y=read(),val=read();
        if(y>k)continue;
        res=max(res,res+val-y*d);
    }
    cout<<res<<'\n';
    return;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
//    clock_t start=clock();
    id=read();
    ll t=read();
    while(t--)
    {
        if(id>=17)solve1();
        else solve();
    }
//    clock_t end=clock();
//    cout<<'\n'<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}