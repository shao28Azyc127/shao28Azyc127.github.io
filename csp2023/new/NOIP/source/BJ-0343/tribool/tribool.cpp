#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=1e5+5;

int c,t,n,m,x[N],y[N],ans;
struct op
{
    char f;
    int x,y;
}a[N];

bool check()
{
    for(int i=1;i<=n;i++)
        y[i]=x[i];
    for(int i=1;i<=m;i++)
    {
        if(a[i].f=='T')
            y[a[i].x]=1;
        if(a[i].f=='F')
            y[a[i].x]=-1;
        if(a[i].f=='U')
            y[a[i].x]=0;
        if(a[i].f=='+')
            y[a[i].x]=y[a[i].y];
        if(a[i].f=='-')
            y[a[i].x]=-y[a[i].y];
    }
    for(int i=1;i<=n;i++)
        if(y[i]!=x[i])
            return 0;
    return 1;
}

void dfs(int step)
{
    if(step==n+1)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
            if(x[i]==0)
                sum++;
        if(sum>=ans)
            return;
        if(check())
            ans=sum;
        return;
    }
    for(int i=-1;i<=1;i++)
    {
        x[step]=i;
        dfs(step+1);
    }
}

void solve1()//dfs
{
    ans=2e9;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].f>>a[i].x;
        if(a[i].f=='+'||a[i].f=='-')
            cin>>a[i].y;
    }
    dfs(1);
    cout<<ans<<endl;
}

void solve2()//TFU
{
    memset(x,0,sizeof(x));
    char f;
    int k;
    for(int i=1;i<=m;i++)
    {
        cin>>f>>k;
        if(f=='T')
            x[k]=1;
        else if(f=='U')
            x[k]=-1;
        else
            x[k]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(x[i]==-1)
            ans++;
    cout<<ans<<endl;
}

void solve3()
{
    memset(x,0,sizeof(x));
    char f;
    int k,k2,T,lastans=0;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].f>>a[i].x;
        if(a[i].f=='+')
            cin>>a[i].y;
    }
    if(c==5)
        T=max(n,m);
    else
        T=300;
    while(T--)
    {
        for(int i=1;i<=m;i++)
        {
            if(a[i].f=='+')
                x[a[i].x]=x[a[i].y];
            else
                x[a[i].x]=-1;
        }
        if(T%10==0)
        {
            ans=0;
            for(int i=1;i<=n;i++)
                if(x[i]==-1)
                    ans++;
            if(ans==lastans)
                break;
            lastans=ans;
        }

    }
    ans=0;
    for(int i=1;i<=n;i++)
        if(x[i]==-1)
            ans++;
    cout<<ans<<endl;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        if(c==1||c==2||c==7||c==8||c==9||c==10)
            solve1();
        else if(c==3||c==4)
            solve2();
        else if(c==5||c==6)
            solve3();
    }
    return 0;
}
