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
#define fup(i,l,r) for(int i=l;i<=r;i++)
#define fdn(i,l,r) for(int i=r;i>=l;i--)
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define maxn 300010
#define mod 998244353
using namespace std;

bool up(int &x,int y) { return (x<y?x=y,1:0); }
bool down(int &x,int y) { return (x>y?x=y,1:0); }
void add(int &x,int y) { x=(x+y)%mod; }
int ksm(int a,int b) { int r=1; for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) r=1ll*r*a%mod; return r; }

int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,a[20][5];
set<int> s[20];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    fup(i,1,n) fup(j,0,4) a[i][j]=read();
    fup(i,1,n) fup(j,1,9)
    {
        int b[5]={a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]};
        fup(k,0,4)
        {
            b[k]=(b[k]+j)%10;
            s[i].insert(b[0]*10000+b[1]*1000+b[2]*100+b[3]*10+b[4]);
            b[k]=(b[k]+10-j)%10;
        }
        fup(k,0,3)
        {
            b[k]=(b[k]+j)%10,b[k+1]=(b[k+1]+j)%10;
            s[i].insert(b[0]*10000+b[1]*1000+b[2]*100+b[3]*10+b[4]);
            b[k]=(b[k]+10-j)%10,b[k+1]=(b[k+1]+10-j)%10;
        }
    }
    int ans=0;
    fup(o,0,99999)
    {
        int cnt=0;
        fup(i,1,n) if(s[i].count(o)) cnt++;
        if(cnt==n) ans++;
    }
    printf("%d\n",ans);

    return 0;
}
