#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],head[N],tong[N],cnt,ans=2147483647,n,h[N];
struct node
{
    int v,next;
}edge[N*2];
void add(int x,int y)
{
    edge[++cnt]=(node){y,head[x]};
    head[x]=cnt;
}
bool fl[N];
void dfs(int d)
{
    for(int i=1;i<=n;i++)
        if(fl[i])
            h[i]+=max(b[i]+(d-1)*c[i],1);
    if(d>n)
    {
        for(;;d++)
        {
            bool flag=1;
            if(d>=ans) return ;
            for(int i=1;i<=n;i++)
            {
                h[i]+=max(b[i]+d*c[i],1);
                if(h[i]<a[i]) flag=0;
            }
            if(flag)
            {
                ans=d;
                return ;
            }
        }

    }
    for(int i=1;i<=n;i++)
        if(fl[i])
        {
            for(int j=head[i];j!=-1;j=edge[j].next)
                if(!fl[edge[j].v])
                {
                    fl[edge[j].v]=1;
                    dfs(d+1);
                    fl[edge[j].v]=0;
                }
        }
    for(int i=1;i<=n;i++)
        if(fl[i])
            h[i]-=max(b[i]+(d-1)*c[i],1);
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(head,-1,sizeof(head));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    fl[1]=1;
    dfs(2);
    cout<<ans;
    return 0;
}
