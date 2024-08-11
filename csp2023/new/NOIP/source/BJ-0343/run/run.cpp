#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=1e3+5;

int c,t,n,m,k,d,ans,ty[N],tv[N];

struct challenge
{
    int x,y,v;
}a[N];

struct finishcha
{
    int cnt,y[N],v[N];
}x[N];

void dfs(int step,int sum,int keep)
{
    if(step==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    //rest
    dfs(step+1,sum,0);
    //run
    if(keep+1<=k)
    {
        int dsum=0;
        for(int i=1;i<=x[step].cnt;i++)
            if(keep+1>=x[step].y[i])
                dsum+=x[step].v[i];
        dfs(step+1,sum+dsum-d,keep+1);
    }
}

void solve1()
{
    ans=0;
    dfs(1,0,0);
    cout<<ans<<endl;
}

void solve2()
{
    ans=0;
    for(int i=1;i<=m;i++)
        ans+=max(a[i].v-d*a[i].y,0);
    cout<<endl;
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
            cin>>a[i].x>>a[i].y>>a[i].v;
        for(int i=1;i<=m;i++)
        {
            x[a[i].x].cnt++;
            x[a[i].x].y[x[a[i].x].cnt]=a[i].y;
            x[a[i].x].v[x[a[i].x].cnt]=a[i].v;
        }
        if(c==1||c==2)
            solve1();
        else
            solve2();
    }
    return 0;
}
