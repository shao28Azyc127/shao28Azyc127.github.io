#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll N=8;
const ll M=5;
ll n,sz[N+5][M+5],ans[M+5],cnt[N+5],res,c,x1,x2;
bool cal(ll x,ll y,ll xx,ll yy)
{
    while(x!=xx&&y!=yy)
    {
        x=(x+1)%10,y=(y+1)%10;
    }
    if(x!=xx||y!=yy) return false;
    else return true;
}
ll cp(ll a)
{
    c=0,x1=x2=0;
    for(ll i=1;i<=M;i++)
    {
        if(sz[a][i]!=ans[i])
        {
            if(c==2) return 3;
            else
            {
                c++;
                if(c==1) x1=i;
                else x2=i;
            }
        }
    }
    return c;
}
bool Check()
{
    for(ll i=1;i<=n;i++)
    {
        ll t=cp(i);
        if(t==0||t>2) return false;
        if(t==2)
        {
            if(abs(x1-x2)!=1) return false;
            if(cal(sz[i][x1],ans[x1],sz[i][x2],ans[x2])==false) return false;
        }
    }
    return true;
}
void dfs(ll now)
{
    if(now==M+1)
    {
        if(Check()==true)
        {
            res++;
        }
         //   for(ll i=1;i<=M;i++) cout<<ans[i]<<" ";
          //  cout<<endl;
    //cout<<res<<endl;
        return ;
    }
    for(ll i=0;i<=9;i++)
    {
        ans[now]=i;
        dfs(now+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=M;j++)
            scanf("%lld",&sz[i][j]);
    dfs(1);
    printf("%lld",res);
    return 0;
}
