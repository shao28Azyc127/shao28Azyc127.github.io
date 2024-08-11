#include<cstdio>
using namespace std;

const int N = 2e4;
int a[N + 5],u[N + 5],v[N + 5];
int n,m,k;
int ans = 1e9;

void dfs(int pos,int t);
bool is_ok(int pos);

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&a[i]);
    }
    if(!is_ok(n)) printf("%d",-1);
    dfs(1,0);
    for(int i = 3;i <= ans;i += 3)
    {
        dfs(1,i);
    }
    printf("%d",ans);
    return 0;
}
void dfs(int pos,int t)
{
    if(pos == n && t % k == 0)
    {
        if(ans > t) ans = t;
        return ;
    }
    if(t > ans) return ;
    for(int i = 1;i <= n;i++)
    {
        if(u[i] == pos && t >= a[i]) dfs(v[i],t + 1);
    }
    return ;
}
bool is_ok(int pos)
{
    if(pos == 1) return true;
    for(int i = 1;i <= n;i++)
    {
        if(v[i] == pos && is_ok(u[i])) return true;
    }
    return false;
}
