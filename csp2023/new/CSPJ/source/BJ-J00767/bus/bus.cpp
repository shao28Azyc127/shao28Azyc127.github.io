#include<cstdio>
#include<algorithm>
const int N=1e4+5;
int G[N][N],n,m,k,vis[N],minn=2e9;
void dfs(int x,int cnt)
{
    if(x==n)
    {
        if(cnt%k==0) minn=std::min(minn,cnt);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&G[x][i]!=-1&&cnt+1>=G[x][i])
        {
            vis[i]=true;
            dfs(i,cnt+1);
            vis[i]=false;
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int curu,curv,cura;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++) G[i][j]=-1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&curu,&curv,&cura);
        G[curu][curv]=cura;
    }
    for(int i=0;;i+=k)
    {
        dfs(1,i);
        if(minn==2e9) continue;
        else if(minn%k==0)
        {
            printf("%d",minn);
            return 0;
        }
        else if(vis[n]==false)
        {
            printf("-1\n");
            return 0;
        }
    }
    return 0;
}