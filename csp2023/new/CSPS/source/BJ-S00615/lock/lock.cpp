#include <bits/stdc++.h>
#define rfor(i,l,r) for(int i=l;i<=r;i++)
#define irfor(i,r,l) for(int i=r;i>=l;i--)
#define ls(p) p<<1
#define rs(p) p<<1|1
#define y0 qwrgshsjglarahfkagr
#define y1 soighsodighslighddd
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int> pii;
inline ll read()
{
    ll x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}
inline void gmin(int &a,int b){if(b<a)a=b;}inline void gmax(int &a,int b){if(b>a)a=b;}
inline void gmin(ll &a,ll b){if(b<a)a=b;}inline void gmax(ll &a,ll b){if(b>a)a=b;}
inline int min(int a,int b){return a<b?a:b;}inline int max(int a,int b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}inline ll max(ll a,ll b){return a>b?a:b;}
const int N = 1e5+5,mod = 1e9+7;
int n,a[10][6],ans;
int chs[6];
bool checki(int x)
{
    int tag = 0;
    rfor(i,1,5) if(chs[i]!=a[x][i]) tag++;
    if(tag > 2 || tag == 0) return false;
    if(tag == 1) return true;
    rfor(i,1,5) if(chs[i]!=a[x][i])
    {
        if(chs[i+1] == a[x][i+1]) return false;
        int d1 = a[x][i]-chs[i];
        int d2 = a[x][i+1]-chs[i+1];
        d1 = (d1+10)%10;
        d2 = (d2+10)%10;
        return d1==d2;
    }
    return false;
}
void check()
{
    rfor(i,1,n) if(!checki(i)) return;
    ans++;
}
void dfs(int x)
{
    if(x == 6) return check();
    rfor(i,0,9)
    {
        chs[x] = i;
        dfs(x+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    n = read();
    rfor(i,1,n) rfor(j,1,5) a[i][j]=read();
    dfs(1);
    cout << ans;
    return 0;
}
//10^5 * 8 * 5
