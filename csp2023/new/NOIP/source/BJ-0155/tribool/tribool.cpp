#include<bits/stdc++.h>
using namespace std;

struct op
{
    char v;
    int i,j;
}s[100005];
int a[100005];
int b[100005];
bool vis[100005];
vector<int> v[100005];
int n,m;
int ans;
void dfs(int k,int last)
{
    vis[k]=1;
    if(b[k]==114514)b[k]=b[last];
    else if(b[k]==-114514)b[k]=-b[last];
    for(auto to:v[k])
    {
        dfs(to,k);
    }
}
void dfs2(int k,int last)
{
    if(vis[k])return ;
    vis[k]=1;
    if(last)
    {
        a[k]=a[last];
        if(b[k]==114514)b[k]=b[last];
        else if(b[k]==-114514)b[k]=-b[last];
        if(a[k]==k)
        {
            if(b[k]==114514)b[k]=1;
            else b[k]=0;
            return ;
        }
    }
    for(auto to:v[k])
    {
        dfs2(to,k);
    }
}
void dfs3(int k,int last)
{
    if(last)
    {
        if(b[k]==114514)b[k]=b[last];
        else if(b[k]==-114514)b[k]=-b[last];
        else return ;
    }
    for(auto to:v[k])
    {
        dfs3(to,k);
    }
}
namespace force
{
    int x[30];
    int tmp[30];
    void dfs(int k)
    {
        if(k>n)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)tmp[i]=x[i];
            for(int i=1;i<=n;i++)if(tmp[i]==0)cnt++;
            for(int i=1;i<=m;i++)
            {
                int ii=s[i].i,jj=s[i].j;
                if(s[i].v=='T')tmp[ii]=1;
                if(s[i].v=='F')tmp[ii]=-1;
                if(s[i].v=='U')tmp[ii]=0;
                if(s[i].v=='+')tmp[ii]=tmp[jj];
                if(s[i].v=='-')tmp[ii]=-tmp[jj];
            }
            int flag=1;
            for(int i=1;i<=n;i++)if(tmp[i]!=x[i]){
                flag=0;
            }
            if(flag)ans=min(ans,cnt);
            return ;
        }
        x[k]=1;
        dfs(k+1);
        x[k]=-1;
        dfs(k+1);
        x[k]=0;
        dfs(k+1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>s[i].v;
            if(s[i].v=='T'||s[i].v=='F'||s[i].v=='U')cin>>s[i].i;
            else cin>>s[i].i>>s[i].j;
        }
        if(c<=2)
        {
            ans=1e9;
            force::dfs(1);
            cout<<ans<<'\n';
        }
        else if(c==3||c==4)
        {
            for(int i=1;i<=n;i++)a[i]=1;
            for(int i=1;i<=m;i++)
            {
                if(s[i].v=='T')a[s[i].i]=1;
                if(s[i].v=='F')a[s[i].i]=-1;
                if(s[i].v=='U')a[s[i].i]=0;
            }
            int cnt=0;
            for(int i=1;i<=n;i++)if(a[i]==0){
                cnt++;
            }
            cout<<cnt<<'\n';
        }
        else
        {
            for(int i=1;i<=n;i++)a[i]=i,b[i]=114514,v[i].clear(),vis[i]=0;
            for(int i=1;i<=m;i++)
            {
                if(s[i].v=='T')
                {
                    int x=s[i].i;
                    a[x]=x;
                    b[x]=1;
                }
                else if(s[i].v=='F')
                {
                    int x=s[i].i;
                    a[x]=x;
                    b[x]=-1;
                }
                else if(s[i].v=='U')
                {
                    int x=s[i].i;
                    a[x]=x;
                    b[x]=0;
                }
                else if(s[i].v=='+')
                {
                    int x=s[i].i,y=s[i].j;
                    b[x]=b[y];
                    if(b[y]==114514||b[y]==-114514)
                    {
                        a[x]=a[y];
                    }
                    else
                    {
                        a[x]=x;
                    }
                }
                else if(s[i].v=='-')
                {
                    int x=s[i].i,y=s[i].j;
                    b[x]=-b[y];
                    if(b[y]==114514||b[y]==-114514)
                    {
                        a[x]=a[y];
                    }
                    else
                    {
                        a[x]=x;
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]!=i)
                {
                    v[a[i]].push_back(i);
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]==i)
                {
                    if(b[i]==-114514)b[i]=0;
                    else if(b[i]==114514)b[i]=1;
                    dfs(i,0);
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(!vis[i])
                {
                    dfs2(i,0);
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]==i)
                {
                    dfs3(i,0);
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++)if(b[i]==0)
            {
                cnt++;
            }
            cout<<cnt<<'\n';
        }
    }
    return 0;
}