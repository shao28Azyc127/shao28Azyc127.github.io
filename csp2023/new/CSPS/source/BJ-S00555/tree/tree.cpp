#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
long long n,f[100010];
vector<int>tu[100010];
long long a[100010],b[100010],c[100010];
bool vis[100010];
void dfs(int x,int fa)
{
    for (int i = 0;i<tu[x].size();i++)
    {
        int y = tu[x][i];
        if(y == fa) continue;
        f[y] = x;
        dfs(y,x);
    }
}
struct Shu
{
    long long now,zhi;
};
Shu s[100010];
bool cmp(Shu x,Shu y)
{
    return x.zhi < y.zhi;
}
bool check(int mid)
{
    memset(vis,false,sizeof(vis));

    for (int i = 1;i<=n;i++)
    {
        long long sum = 0;
        for (int j = mid;j>=1;j--)
        {
            sum = sum+max(1ll*b[i]+1ll*j*c[i],1ll);
            if(sum >= a[i])
            {
                s[i].now = i,s[i].zhi = j;
                break;
            }
        }
        //printf("%d %d %d  ",mid,sum,a[i]);
        if(sum < a[i]) return false;
    }
    sort(s+1,s+1+n,cmp);
    long long nw = 1;
    vis[1] = true;
    for (int i = 1;i<=n;i++)
    {
        int nn = s[i].now;
        long long jia = 0;
        if(vis[nn]) continue;
        while(!vis[nn])
        {
            nn = f[nn];
            jia++;
        }
        if(jia+nw > s[i].zhi) return false;
        nn = s[i].now;
        nw += jia;
        while(!vis[nn])
        {
            vis[nn] = true;
            nn = f[nn];
        }
    }
    return true;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for (int i = 1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        tu[u].push_back(v),tu[v].push_back(u);
    }
    dfs(1,0);
    int l = 0,r = 1e9;
    while(l < r)
    {
        int mid = (l+r)/2;
        //printf("%d ",mid);
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d\n",l);
    return 0;
}