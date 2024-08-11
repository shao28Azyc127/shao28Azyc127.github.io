#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,k,t[10005][10005],mni=2147483647;
void dfs(int p,int tim)
{
    if(p==n)
    {
        if(tim%k==0)
            mni=min(mni,tim);
        return;
    }
    for(int i=1;i<=n;i++)
        if(a[p][i]&&tim>=t[p][i])
        {
            a[p][i]=0;
            dfs(i,tim+1);
        }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int x,b,c;
        scanf("%d%d%d",&x,&b,&c);
        a[x][b]=1;
        t[x][b]=c;
    }
    dfs(1,k);
    if(mni=2147483647)
        mni=-1;
    printf("%d",mni);
    return 0;
}
