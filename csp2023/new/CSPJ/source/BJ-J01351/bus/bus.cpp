#include<bits/stdc++.h>
using namespace std;
vector<int> e[20000];
vector<int> w[20000];
bool book[2000];
long long dis[2000];
int n,m,k;
int ans=0x7fffffff;
int tok(int a)
{
    if((a%k)!=0)
    {
        a+=k;
        a-=a%k;
    }
    return a;
}
void dfs(int use,int wait,int x)
{
    if(x==n)
    {
        if(use%k==0)
        {
            ans=min(tok(wait)+use,ans);
        }
    }
    for(int i=0;i<e[x].size();i++)
    {
        if(!book[e[x][i]])
        {
            book[e[x][i]]=1;
            dfs(use+1,max(wait,w[x][i]-(use+1)),e[x][i]);
            book[e[x][i]]=0;
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        e[x].push_back(y);
        w[x].push_back(z);
    }
    if(k==1)
    {
        book[1]=1;
        dis[0]=0x7fffffff;
        for(int i=1;i<=n;i++)
        {
            dis[i]=0x7fffffff;
        }
        dis[1]=0;
        for(int i=0;i<e[1].size();i++)
        {
            dis[e[1][i]]=w[1][i];
        }
        for(int i=1;i<=n;i++)
        {
            int mini=0;
            for(int j=1;j<=n;j++)
            {
                if(!book[j])
                {
                    if(dis[mini]>dis[j]) mini=j;
                }
            }
            book[mini]=1;
            for(int j=0;j<e[mini].size();j++)
            {
                dis[e[mini][j]]=min(dis[e[mini][j]],dis[mini]+w[mini][j]);
            }
        }
        cout<<dis[n];
        return 0;
    }
    book[1]=1;
    dfs(0,0,1);
    if(ans==0x7fffffff)
    {
        ans=-1;
    }
    cout<<ans;
    return 0;
}
