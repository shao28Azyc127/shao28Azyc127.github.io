#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e18, maxn = 8005;
int n,dp[maxn][maxn];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    int n=rand()*rand()%mod*rand()*rand()%mod;
    for(int i=1;i<=114;i*=rand())
    {
        n=rand()*i%mod;
    }
    n=(n+mod)%mod;
    cout<<n<<"\n";
    return 0;
}
