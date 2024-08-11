#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int l,r;
    long long v;
} a[100001];
bool cmp(node x,node y)
{
    if(x.l != y.l) return x.l < y.l;
    return x.r < y.r;
}
int cnt,nxt[200001],to[200001],head[100001];
void add(int x,int y)
{
    to[++cnt] = y;
    nxt[cnt] = head[x];
    head[x] = cnt;
}
bool vis[100001];
long long dp[100001][2];
void dfs(int x)
{
    dp[x][1] = a[x].v;
    vis[x] = 1;
    for(int i = head[x];i;i = nxt[i])
        if(!vis[to[i]])
        {
            dfs(to[i]);
            dp[x][0] += max(dp[to[i]][0],dp[to[i]][1]);
            dp[x][1] += dp[to[i]][0];
        }
    //cout << x << " " << dp[x][0] << " " << dp[x][1] << endl;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)
    {
        cnt = 0;
        memset(head,0,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        int n,m,k,d,tmp;
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i = 1;i <= m;i++)
        {
            //cout << i << endl;
            scanf("%d%d%lld",&a[i].r,&tmp,&a[i].v);
            a[i].l = a[i].r-tmp+1;
            a[i].v -= 1ll*d*tmp;
        }
        sort(a+1,a+1+m,cmp);
        for(int i = 1;i <= m;i++)
            for(int j = i+1;j <= m;j++)
            {
                if(a[j].l > a[i].r+1) break;
                if(a[j].r-a[i].l+1 > k) {add(i,j); add(j,i);}
            }
        long long ans = 0;
        for(int i = 1;i <= m;i++)
            if(!vis[i])
            {
                dfs(i);
                ans += max(dp[i][0],dp[i][1]);
            }
        printf("%lld\n",ans);
    }
    return 0;
}
