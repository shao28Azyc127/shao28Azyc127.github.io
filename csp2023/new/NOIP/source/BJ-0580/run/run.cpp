#include <iostream>
#include <cstdio>
#define MAXN 50
using namespace std;
int c,t,n,m,k,d;
int x[MAXN],y[MAXN],v[MAXN];
bool flag[MAXN];
int ans=-1;

void dfs(int pos)
{
    if (pos>n)
    {
        int ret=0,tmp=0;
        for (int i=1;i<=n;i++)
        {
            if (flag[i]==1)
            {
                tmp++;
                ret-=d;
            }
            else
                tmp=0;
            if (tmp>k)
                return ;
        }
        for (int i=1;i<=m;i++)
        {
            if (x[i]-y[i]+1<0) continue;
            int f=1;
            for (int j=x[i]-y[i]+1;j<=x[i];j++)
            {
                if (flag[j]==0)
                {
                    f=0;
                    break;
                }
            }
            if (f)
                ret+=v[i];
        }
        ans=max(ans,ret);
    }
    else
    {
        flag[pos]=0;
        dfs(pos+1);
        flag[pos]=1;
        dfs(pos+1);
    }
    return ;
}

void solve()
{
    ans=-1;
    cin>>n>>m>>k>>d;
    for (int i=1;i<=m;i++)
        cin>>x[i]>>y[i]>>v[i];
    dfs(1);
    cout<<ans<<endl;
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while (t--)
        solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}