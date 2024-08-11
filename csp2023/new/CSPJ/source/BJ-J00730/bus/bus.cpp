#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m,k;
struct edge{int x,t;};
vector<edge>v[10010];
bool flag[10010][110];
struct node{int x,t;};
void bfs(int mid)
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++)
            flag[i][j]=0;
    flag[n][0]=1;
    queue<node>q;
    q.push({n,mid});
    while(!q.empty())
    {
        int x=q.front().x;
        int t=q.front().t;
        q.pop();
        for(auto e:v[x])
            if(t>e.t&&!flag[e.x][(t-1)%k])
            {
                flag[e.x][(t-1)%k]=1;
                q.push({e.x,t-1});
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
        int x,y,t;
        cin>>x>>y>>t;
        v[y].push_back({x,t});
    }
    int l=1,r=(1e6+n*k+k)/k,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2*k;
        bfs(mid);
        mid/=k;
        if(flag[1][0])r=mid-1,ans=mid;
        else l=mid+1;
    }
    if(ans>-1)cout<<ans*k<<endl;
    else cout<<-1<<endl;
    return 0;
}