#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=1005;
LL dp[MAXN][MAXN];
LL v[MAXN][MAXN];
int N,M,K,D,C,T;
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d %d",&C,&T);
    while(T--)
    {
        scanf("%d %d %d %d",&N,&M,&K,&D);
        if(C>9)
        {
            LL ans=0;
            for(int i=1;i<=M;i++)
            {   
                int x,y,w;
                scanf("%d %d %d",&x,&y,&w);
                if(y>K) continue;
                ans+=max(0ll,1ll*w-1ll*y*D);
            }
            printf("%lld\n",ans);
            continue;
        }
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=K;j++)
            {
                dp[i][j]=-1e15;
                v[i][j]=0;
            }
        }
        for(int i=1;i<=M;i++)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            if(y>K) continue;
            v[x][y]+=w;
        }
        for(int i=1;i<=N;i++)
        {
            LL sum=0;
            for(int j=1;j<=K;j++)
            {
                LL osum=sum;
                sum+=v[i][j];
                v[i][j]+=osum;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<=N;i++)
        {
            dp[i][0]=dp[i-1][0];
            for(int j=0;j<=K;j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
            for(int j=1;j<=K;j++)
            {
                if(dp[i-1][j-1]!=-1e15) dp[i][j]=dp[i-1][j-1]-D+v[i][j];
            }
        }
        LL ans=0;
        for(int i=0;i<=K;i++) ans=max(ans,dp[N][i]);
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}