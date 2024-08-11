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
    while(ch<'a'||ch>'z'){ch=getchar();}
    return ch;
}
ll n,m;
char c[3005][3005];
ll tmp[3005];
char tmpc[3005];
bool cmp(ll x,ll y)
{
    for(int i=1;i<=m;i++)
    {
        if(c[x][i]<c[y][i])return 1;
        if(c[x][i]>c[y][i])return 0;
    }
    return 0;
}
void solve()
{
    n=read(),m=read();
    if(n==1){cout<<1;return;}
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            c[i][j]=readc();
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)tmp[c[i][j]-'a'+1]++;
        ll pos=0;
        for(int j=26;j>=1;j--)
        {
            while(tmp[j])tmp[j]--,c[i][++pos]=(char)(j-1+'a');
        }
    }
    ll max1=0,max2=0;
    for(int i=1;i<=n;i++)
    {
        if(max1==0){max1=i;continue;}
        if(cmp(i,max1))max2=max1,max1=i;
        else
        {
            if(max2==0){max2=i;continue;}
            if(cmp(i,max2))max2=i;
        }
    }
//    for(int j=1;j<=m;j++)cout<<c[max1][j];cout<<'\n';
//    for(int j=1;j<=m;j++)cout<<c[max2][j];cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            c[0][j]=c[i][m+1-j];
        }
        if(max1==i)cout<<cmp(0,max2);
        else cout<<cmp(0,max1);
    }
    cout<<'\n';
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ll t=1;
    while(t--)solve();
    return 0;
}