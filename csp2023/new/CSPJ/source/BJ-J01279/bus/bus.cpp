//#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n,m,k;
vector<int> g[1000005],w[1000005];
long long dis[1000005];
long long _used[1000005];
struct node
{
    int pos;
    long long used;
    long long early;
};
queue<node> q;
long long bfs()
{
    q.push(node{1,0,0});
    memset(dis,0x3f,sizeof(dis));
    memset(_used,0x3f,sizeof(_used));
    dis[1]=0;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        //if(u.pos==n) return u.early+u.used;
        //cout<<"pos="<<(u.pos-1)%n+1<<" level="<<(u.pos-1)/n<<" used="<<u.used<<" early="<<u.early<<'\n';
        for(int i=0;i<g[u.pos].size();i++)
        {
            int j=g[u.pos][i];
            int early=u.early;
            while(early+u.used<w[u.pos][i]) early+=k;
            int used=u.used+1;
            if(dis[j]+_used[j]>early+used)
            {
                dis[j]=early;
                _used[j]=used;
                q.push(node{j,used,early});
            }
        }
    }
    if(dis[n]!=0x3f3f3f3f3f3f3f3f) return dis[n]+_used[n];
    return -1ll;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        for(int lev=0;lev<=k-2;lev++)
        {
            g[lev*n+u].push_back((lev+1)*n+v);
            w[lev*n+u].push_back(a);
        }
        g[(k-1)*n+u].push_back(v);
        w[(k-1)*n+u].push_back(a);
    }
    cout<<bfs();
    return 0;
}

