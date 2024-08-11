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
ll C;
ll n,m,q;
ll tmpx[500005],tmpy[500005];
ll px[500005],py[500005];
ll f[2005][2005];
void calc()
{
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((px[i]-py[j])*(px[1]-py[1])<=0){f[i][j]=0;continue;}
            f[i][j]=max(max(f[i][j-1],f[i-1][j]),f[i-1][j-1]);
        }
    }
    cout<<f[n][m];
}
void solve()
{
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)tmpx[i]=read();
    for(int i=1;i<=m;i++)tmpy[i]=read();
    for(int i=1;i<=n;i++)px[i]=tmpx[i];
    for(int i=1;i<=m;i++)py[i]=tmpy[i];
    calc();
    while(q--)
    {
        for(int i=1;i<=n;i++)px[i]=tmpx[i];
        for(int i=1;i<=m;i++)py[i]=tmpy[i];
        ll kx=read(),ky=read();
        for(int i=1;i<=kx;i++)
        {
            ll p=read(),x=read();
            px[p]=x;
        }
        for(int i=1;i<=ky;i++)
        {
            ll p=read(),y=read();
            py[p]=y;
        }
        calc();
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
//    clock_t start=clock();
    C=read();
    solve();
//    clock_t end=clock();
//    cout<<'\n'<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}