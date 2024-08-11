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
const int N = 3005,mod = 1e9+7;
int n,m;
string s[N],mx[N];
struct dict{int i;string s;}dic[N];
bool cmp1(char a,char b){return a>b;}
bool cmp(dict x,dict y){return x.s < y.s;}
bool cani[N];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    rfor(i,1,n)
    {
        cin >>s[i];
        dic[i].i = i;dic[i].s = s[i];
        sort(s[i].begin(),s[i].end());
        sort(dic[i].s.begin(),dic[i].s.end(),cmp1);
    }
    sort(dic+1,dic+n+1,cmp);
    rfor(i,1,n)
    {
        if(i == dic[1].i) cani[i] = 1;
        else if(s[i] < dic[1].s) cani[i] = 1;
    }
    rfor(i,1,n) cout <<cani[i];
    return 0;
}
