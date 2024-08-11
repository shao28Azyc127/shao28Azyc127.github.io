# include <bits/stdc++.h>
# define N 100005
using namespace std;
int n,m;
char op;
int fa[N<<1];
bool type[N];
int num[N];
int getfa(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
    fa[getfa(x)]=getfa(y);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        type[i]=0,num[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf(" %c",&op);
        int x,y;
        if(op=='+')
        {
            scanf("%d%d",&x,&y);
            num[x]=num[y];
            type[x]=type[y];
        }
        else if(op=='-')
        {
            scanf("%d%d",&x,&y);
            num[x]=num[y];
            type[x]=!type[y];
        }
        else if(op=='T')
        {
            scanf("%d",&x);
            type[x]=0;
            num[x]=-1;
        }
        else if(op=='F')
        {
            scanf("%d",&x);
            type[x]=1;
            num[x]=-1;
        }
        else
        {
            scanf("%d",&x);
            type[x]=0;
            num[x]=-2;
        }
    }
    for(int i=1;i<=2*n+1;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(num[i]>0)
        {
            if(type[i]==0)
                merge(i,num[i]),merge(n+i,n+num[i]);
            else
                merge(i,n+num[i]),merge(n+i,num[i]);
        }
        else if(num[i]==-2)
            merge(i,2*n+1),merge(n+i,2*n+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(getfa(i)==getfa(n+i) || getfa(i)==getfa(2*n+1))
            ans++;
    printf("%d\n",ans);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
        solve();
    return 0;
}