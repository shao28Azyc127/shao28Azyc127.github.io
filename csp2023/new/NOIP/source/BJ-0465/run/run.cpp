#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int M=1e5+10,N=1010;
struct node {int l,r,v;} a[M];
int dp[N][N];
vector<int> op[N];
inline int read()
{
    int S=0,W=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') W=-1; ch=getchar();}
    while(ch>='0' && ch<='9') S=(S<<1)+(S<<3)+(ch^48),ch=getchar();
    return S*W;
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c=read(),t=read(),x,y,tmp;
    while(t--)
    {
        int n=read(),m=read(),k=read(),d=read();
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            x=read(),y=read(),a[i].v=read();
            a[i].l=x-y+1,a[i].r=x;
        }
        memset(dp,-0x3f,sizeof(dp)); 
        for(int i=0;i<=n;i++) vector<int>().swap(op[i]);
        for(int i=1;i<=m;i++) op[a[i].r].pb(i);
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int p=0;p<=k;p++) 
            {
                dp[i][0]=max(dp[i][0],dp[i-1][p]);
                if(p) dp[i][p]=max(dp[i][p],dp[i-1][p-1]-d);
                // ans=max(ans,dp[i][p]);
            }
            tmp=op[i].size();
            for(int j=0;j<tmp;j++)
            {
                x=op[i][j],y=a[x].r-a[x].l+1;
                for(int p=y;p<=k;p++)
                    dp[i][p]=max(dp[i][p],dp[i][p]+a[x].v);
            }
        }
        for(int i=0;i<=k;i++) ans=max(ans,dp[n][i]);
        printf("%lld\n",ans);
    }
    return 0;
}