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
const int N = 2e6+5,mod = 1e9+7;
int n,tor[N];
char s[N];
char q[N];int pos[N],cnt;
void solve(int x)
{
    cnt = 0;
    rfor(i,x,n)
    {
        if(s[i] == s[x])
        {
            if(q[cnt] == s[i]) tor[pos[cnt]] = i,cnt--;
            else q[++cnt] = s[i],pos[cnt] = i,tor[i]=-1;
        }
        else
        {
            if(q[cnt] == s[i]) tor[pos[cnt]] = i,cnt--;
            else if(tor[i]!=0)
            {
                if(tor[i] == -1) return;
                i = tor[i];
            }
            else q[++cnt] = s[i],pos[cnt] = i,tor[i]=-1;
        }
    }
}
ll ans,dp[N];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s+1;
    rfor(i,1,n)
        if(tor[i]==0) solve(i);
    irfor(i,n,1)
    {
        if(tor[i] > 0) dp[i] = dp[tor[i]+1]+1;
        ans += dp[i];
    }
    cout << ans;
//    rfor(i,1,n) cout << tor[i] << ' ';
    return 0;
}
