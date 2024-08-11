#include <iostream>
#include <algorithm>
using namespace std;
struct rd
{
    int u,v,a;
}r[20005];
int g[20005],m2=10000000,n,k,i;
bool b[200005];
bool cmp(rd x,rd y)
{
    return x.u<y.u;
}
void d(int w,int z,int s)
{
    if(w==n)
    {
        if(s%k==0)
            m2=min(m2,z);
        return;
    }
    int i;
    for(i=g[w];i<g[w+1];i++)
    {
        if(r[i].u==r[i].v||b[r[i].v])continue;
        b[r[i].v]=1;
        d(r[i].v,max(z,r[i].a)+1,s+1);
        b[r[i].v]=0;
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int m,j=1;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
        cin>>r[i].u>>r[i].v>>r[i].a;
    sort(r+1,r+m+1,cmp);
    for(i=1;i<=m;i++)
        if(r[i].u!=r[i-1].u)
            g[r[i].u]=i;
    for(i=n-1;i>=1;i--)
        if(g[i]==0)
            g[i]=g[i+1];
    g[n]=m+1,b[1]=1;
    d(1,0,0);
    if(m2==10000000)
        cout<<-1;
    else
    {
        if(m2%k!=0)
            m2=(m2/k+1)*k;
        cout<<m2;
    }
    return 0;
}