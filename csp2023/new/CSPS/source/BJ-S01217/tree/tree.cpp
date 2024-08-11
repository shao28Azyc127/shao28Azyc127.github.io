#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],b[N],c[N];
long long d[N],e[N],dep[N];
vector<int> v[N];
long long calc(long long x,long long y){return (x+y)*(y-x+1)/2ll;}
long long get(int x,int y)
{
    long long l=1,r=1ll*y,mid,best=-1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(b[x]*mid+c[x]*calc(1ll*x,1ll*y)<a[i])r=mid-1;
        else l=mid+1,best=mid;
    }
}
int check2(int nw,long long x,long long y)
{
    long long z=b[nw]/(-c[nw]);
    if(b[nw]+z*c[nw]>1ll)z++;
    return b[nw]*(z-x)+c[nw]*calc(x,z-1)+y-z+1<a[i];

}
long long get2(int x,int y)
{
    long long l=1,r=1ll*y,mid,best=-1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check2(x,mid,y))r=mid-1;
        else l=mid+1,best=mid;
    }
}
//void dfs2(int x,int lst)
//{
//    if()
//}
int check(int x)
{
    d[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(c[i]>=0)
        {
            d[i]=get(i,x);
            if(d[i]==-1)return 0;
        }
        else d[i]=get2(i,x);
    }
    for(int i=1;i<=n;i++)
    {
        e[i]=d[i]-dep[i];
        if(e[i]<0)return 0;
    }
    return 1;
//    dfs2(1,0);
}
int ask()
{
    int l=0,r=1e9,mid,best;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))r=mid-1;
        else l=mid+1,best=mid;
    }
    return best;
}
void dfs(int x,int lst)
{
    dep[x]=dep[lst]+1;
    for(int i=0;i<v[x].size();i++)if(v[x][i]!=lst)dfs(v[x][i],x);
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
    int x,y;
    for(int i=1;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
    dfs(1,0);
    if(n<=500)cout<<ask()<<endl;
    return 0;
}
