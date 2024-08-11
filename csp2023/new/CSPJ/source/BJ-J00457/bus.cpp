#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct edge
{
    int v,w;
    edge() {v=w=0;}
};
int n,m,k;
int mina=1919810;
edge a[100005];
vector<edge> t[100005];
edge make(int v,int w)
{
    edge e;
    e.v=v,e.w=w;
    return e;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        t[u].push_back(make(v,w));
        if(u==1 && v==n)
            mina=min(mina,w);
    }
    if(k==1)
        cout << (mina==1919810?-1:mina+1);
    else
        cout << -1;
    return 0;
}
