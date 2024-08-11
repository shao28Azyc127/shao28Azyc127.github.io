#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
    int c,t;
};
vector<node> bi[10010];
int way[10010],cnt=0;
bool inque[10010];
queue<int> q;
void dfs()
{
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        inque[x]=false;
        for(int i=0;i<bi[x].size();i++)
        {
            int v=bi[x][i].t,co=bi[x][i].c;
            if(!inque[v])
            {
                inque[v]=true;
                if(v==n && (way[x]+co)%k==0)
                    way[v]=min(way[v],way[x]+co);
                q.push(v);
            }
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
        int a,b,v;
        scanf("%d%d%d",a,b,v);
        node d;
        d.c=1,d.t=b;
        bi[a].push_back(d);
    }
    for(int i=1;i<=n;i++)way[i]=0x3f3f3f;
    q.push(1);
    dfs();
    cout<<way[n]<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}