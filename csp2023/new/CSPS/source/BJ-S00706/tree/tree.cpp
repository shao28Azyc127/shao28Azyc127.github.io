#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005],b[100005],c[100005];
bool f[100005][100005];
bool v[100005];
int h[100005];
bool dn[100005];

int ans=0;

bool check()
{
    for(int i=1;i<=n;++i)
    {
        if(dn[i]==false)
        {
            return false;
        }
    }

    return true;
}

void DFS(int x,int d)
{
    v[x]=true;//!

    if(dn[x]==false)
    {
        h[x]+=max(b[x]+d*c[x],1);
        if(h[x]>=a[x])
        {
            dn[x]=true;
        }
    }

    if(d>=n)
    {
        if(check()==true)
        {
            ans=min(ans,d);
        }
    }

    for(int i=1;i<=n&&f[x][i]==true;++i)
    {
        if(i!=x&&v[x]==false)
        {
            DFS(i,d+1);
        }
    }

    v[x]=false;
}

int i,j;
int x,y;

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    memset(f,false,sizeof(f));
    memset(v,false,sizeof(v));
    memset(h,0,sizeof(h));
    memset(dn,false,sizeof(dn));

    scanf("%d",&n);

    for(i=1;i<=n;++i)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    for(i=1;i<=n-1;++i)
    {
        scanf("%d%d",&x,&y);
        f[x][y]=true;
        f[y][x]=true;
    }

    DFS(1,1);

    printf("%d\n",ans);

    return 0;
}
