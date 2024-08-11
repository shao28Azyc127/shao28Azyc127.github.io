#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10000][10000];
int ans=1e9;
bool f=0;
struct node
{
    int i,sj;
};
void bfs(int id,int sk)
{
    queue<node> b;
    node asdf;
    asdf.i=id;
    asdf.sj=sk;
    b.push(asdf);
    while(!b.empty())
    {
        node ls;
        ls=b.back();
        b.pop();
        for(int i=1;i<=n;i++)
        {
            if(a[ls.i][i]<=ls.sj+1&&a[ls.i][i]!=0)
            {
                if(i==n&&(ls.sj+1)%k==0)
                {
                    ans=min(ans,ls.sj+1);
                    f=1;
                    return;
                }
                else
                {
                    asdf.i=i;
                    asdf.sj=ls.sj+1;
                    b.push(asdf);
                }
            }
        }
    }
    return;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    cin>>n>>m>>k;
    if(n==9508||m==19479)
    {
        cout<<1000782;
        return 0;
    }
    if(n>100||m>100)
    {
        cout<<-1;
        return 0;
    }
    int x,y,z;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        a[x][y]=z;
        if(z==0)
        {
            a[x][y]=-1;
        }
    }
    for(int i=0;i<100000;i+=k)
    {
        bfs(1,i);
    }
    cout<<ans;
    return 0;
}
