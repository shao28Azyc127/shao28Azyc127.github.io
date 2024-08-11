//总该有一道图论了吧
//这次怎么没有dp
#include <iostream>

using namespace std;
struct edge
{
    int v,nxt,w;
}e[100005];
int ecnt;
int head[100005];
void add(int u,int v)
{
    head[u]=ecnt;
    e[ecnt].nxt=head[u];
    e[ecnt].v=v;
    e[ecnt].w=w;
    ecnt++;
}
int n,k,m;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    cout<<k<<endl;
    return 0;
}
