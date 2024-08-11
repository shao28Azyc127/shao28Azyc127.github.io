#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector <long long> v[10010],v2[10010];
int vis[10010][110];
struct A
{
    long long ti,pos;
};
bool operator <(A x,A y)
{
    return x.ti>y.ti;
}
priority_queue <A> pq;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(vis,0x3f,sizeof(vis));
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        v2[i].push_back(0);
        v[i].push_back(0);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(y);
        v2[x].push_back(z);
    }
    pq.push((A){0,1});
    while(!pq.empty())
    {

        A nx=pq.top();
        pq.pop();
        if(nx.pos==n)
        {
            if(nx.ti%k==0)
            {
                cout<<nx.ti<<endl;
                return 0;
            }
        }
        if(vis[nx.pos][nx.ti%k]<=nx.ti)continue;
        vis[nx.pos][nx.ti%k]=nx.ti;
        if(v[nx.pos].size()==1)continue;
        for(int i=1;i<v[nx.pos].size();i++)
        {
            long long tim;
            if(nx.ti<v2[nx.pos][i])tim=nx.ti+1ll*ceil(1.0*(v2[nx.pos][i]-nx.ti)/k)*k;
            else tim=nx.ti;
            pq.push((A){tim+1,v[nx.pos][i]});
        }
    }
    cout<<-1<<endl;
    return 0;
}