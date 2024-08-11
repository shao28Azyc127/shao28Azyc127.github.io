#include<bits/stdc++.h>
using namespace std;
struct road
{
    int v,a;
};
bool vis[10010],vis2[10010];
int ma[10010],n,m,k,ans=-1,maxn;
vector<road>vec[10010];
priority_queue<pair<int ,int > ,vector< pair<int ,int > >,greater< pair<int ,int > >>que;
void bfs(road x)
{
    if(ans!=-1)
        return;
    if(x.v==n&&x.a%k==0)
    {
        ans=x.a;
        return;
    }
    if(vis[x.v]||vis2[x.v])
        return;
    if(x.a-k-1>=ma[x.v])
        vis[x.v]=true;
    vis2[x.v]=true;
    for(int i=0;i<vec[x.v].size();i++)
    {
        if(x.a<vec[x.v][i].a)
            continue;
        que.push(make_pair(x.a+1,vec[x.v][i].v));
    }
    return;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    road x;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        x.v=v,x.a=a;
        vec[u].push_back(x);
        ma[u]=max(ma[u],a);
        maxn=max(maxn,a);
    }
    for(int i=0;i<=maxn;i+=k)
        que.push(make_pair(i,1));
    int f=0;
    while(!que.empty())
    {
        if(ans!=-1)
            break;
        x.a=que.top().first,x.v=que.top().second;
        //cout<<x.v<<" "<<x.a<<endl;
        if(x.a!=f)
        {
            f=x.a;
            memset(vis2,false,sizeof(vis2));
        }
        que.pop();
        bfs(x);
    }
    cout<<ans;
    return 0;
}