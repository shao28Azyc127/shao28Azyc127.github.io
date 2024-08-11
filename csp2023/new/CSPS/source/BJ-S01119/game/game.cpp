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
#define maxn 2000010
#define mod 998244353
#define modd (int)(1e9+7)
#define x first
#define y second
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

int n;
char s[maxn];
int p[maxn][2];
map<pii,int> hsh;
stack<int> stk;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read(),scanf("%s",s+1);
    p[0][0]=p[0][1]=1;
    fup(i,1,n) p[i][0]=p[i-1][0]*131ll%mod,p[i][1]=p[i-1][1]*13331ll%modd;
    int sz=0,m[2]={0,0};
    hsh[{0,0}]++;
    fup(i,1,n)
    {
        char c=s[i];
        int d=c-'a'+1;
        if(stk.empty()||stk.top()!=c)
        {
            m[0]=(m[0]+1ll*p[sz][0]*d%mod)%mod,m[1]=(m[1]+1ll*p[sz][1]*d%modd)%modd;
            stk.push(c),sz++;
        }
        else
        {
            stk.pop(),sz--;
            m[0]=(m[0]+mod-1ll*p[sz][0]*d%mod)%mod,m[1]=(m[1]+modd-1ll*p[sz][1]*d%modd)%modd;
        }
        //cout<<m[0]<<' '<<m[1]<<endl;
        hsh[mp(m[0],m[1])]++;
    }

    ll ans=0;
    for(auto p:hsh) ans+=1ll*(p.y-1)*(p.y)/2;
    printf("%lld\n",ans);

    return 0;
}
