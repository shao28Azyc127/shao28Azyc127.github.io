#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#define fup(i,l,r) for(int i=l;i<=r;i++)
#define fdn(i,l,r) for(int i=r;i>=l;i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 998244353
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define maxn 500010
using namespace std;

bool up(int &x,int y) { return (x<y?x=y,1:0); }
bool down(int &x,int y) { return (x>y?x=y,1:0); }
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,m,q,x[maxn],y[maxn],xx[maxn],yy[maxn],ans[maxn];
bool f[2010][2010];

bool chk()
{
    if(x[1]==y[1]) return 0;
    fup(i,1,n) fup(j,1,m) f[i][j]=0;
    f[1][1]=1;
    fup(i,1,n) fup(j,1,m) if(f[i][j])
    {
        if(i<n&&1ll*(x[1]-y[1])*(x[i+1]-y[j])>0) f[i+1][j]=1;
        if(j<m&&1ll*(x[1]-y[1])*(x[i]-y[j+1])>0) f[i][j+1]=1;
    }
    return f[n][m];
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int jkdj=read();
    n=read(),m=read(),q=read();
    fup(i,1,n) x[i]=read();
    fup(j,1,m) y[j]=read();
    ans[0]=chk();

    fup(o,1,q)
    {
        int kx=read(),ky=read();
        fup(i,1,n) xx[i]=x[i];
        fup(i,1,m) yy[i]=y[i];
        while(kx--) { int p=read(),v=read(); x[p]=v; }
        while(ky--) { int p=read(),v=read(); y[p]=v; }
        ans[o]=chk();
        fup(i,1,n) x[i]=xx[i];
        fup(i,1,m) y[i]=yy[i];
    }
    fup(o,0,q) printf("%d",ans[o]);
    puts("");

    return 0;
}
