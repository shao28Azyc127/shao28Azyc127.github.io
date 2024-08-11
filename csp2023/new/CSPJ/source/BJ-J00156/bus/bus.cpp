#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define IO_ON_FILE
int n,m,k;
int maxa;
struct Edge
{
    int v,a;
};
vector<Edge> e[10005];
struct Point
{
    int p,t;
};
int bfs(int s,int en)
{
    queue<Point> q;
    for(int i=0;i<=maxa;i+=k)
        q.push((Point){s,i});
    while(!q.empty())
    {
        Point now=q.front();
        q.pop();
        if(now.p==en)
            if(now.t%k==0)
                return now.t;
        for(int i=0;i<e[now.p].size();i++)
        {
            int v=e[now.p][i].v;
            int a=e[now.p][i].a;
            if(now.t>=a)
            {
                q.push((Point){v,now.t+1});
                clog<<now.p<<"->"<<v<<" "<<now.t<<endl;
            }
        }
    }
    return -1;
}
int main()
{
    #ifdef IO_ON_FILE
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    #endif // IO_ON_FILE
    cin>>n>>m>>k;
    maxa=0xc0c0c0c0;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        e[u].push_back((Edge){v,a});
        maxa=max(maxa,a);
    }
    cout<<bfs(1,n);
    return 0;
}
