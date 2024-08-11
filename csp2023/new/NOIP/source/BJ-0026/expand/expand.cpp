#include <bits/stdc++.h>
#define rfor(i,l,r) for(int i=l;i<=r;i++)
#define irfor(i,r,l) for(int i=r;i>=l;i--)
#define ls(p) p<<1
#define rs(p) p<<1|1
#define mkp make_pair
#define x0 aiklsfhlasdkfghlkadrfhgasdfg
#define y0 zsfdkgjhlksdfhglksfdhglkasdf
#define y1 sklrluhgklahrgklsedrhgklfdhg
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
const int N = 5e5+5,mod = 1e9+7;
int n,m,q,x[N],y[N],tx[N],ty[N];
inline bool solve(int n,int *x,int m,int *y)
{
    int xmax = 0;
    rfor(i,1,n) gmax(xmax,x[i]);
//    cout << "max:" <<xmax <<endl;
    rfor(i,1,m) if(y[i] >= xmax) return false;
//    cout << "PASS1\n";
    int np = 1,nmin = y[1];
    rfor(i,1,n)
    {
        if(x[i] <= nmin) return false;
        while(np < m && x[i] > y[np+1])
        {
            np++;
            gmin(nmin,y[np]);
        }
    }
  //  cout << "PASS2\n";
    np = m,nmin = y[m];
    irfor(i,n,1)
    {
        if(x[i] <= nmin) return false;
        while(np > 1 && x[i] > y[np-1])
        {
            np--;
            gmin(nmin,y[np]);
        }
    }
   // cout << "PASS3\n";
    return true;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read();
    n = read(),m =read(),q = read();
    rfor(i,1,n) x[i]=read();
    rfor(i,1,m) y[i]=read();
    cout << (solve(n,x,m,y)||solve(m,y,n,x));
    int kx,ky,p,v;
    while(q--)
    {
        rfor(i,1,n) tx[i]=x[i];rfor(i,1,m) ty[i]=y[i];
        kx = read(),ky = read();
        rfor(i,1,kx) p=read(),v=read(),tx[p]=v;
        rfor(i,1,ky) p=read(),v=read(),ty[p]=v;
        cout << (solve(n,tx,m,ty)||solve(m,ty,n,tx));
    }
    return 0;
}
