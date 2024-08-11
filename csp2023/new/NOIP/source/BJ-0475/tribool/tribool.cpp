#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e5+10;

int n,m,x[N];//i,i+(n+1),-1
int fa[N<<1];
bool tag[N<<1];

int find(int i)
{
    return i==fa[i]? i:fa[i]=find(fa[i]);
}

int g(int k)
{
    if(k==-1) return k;
    if(k>n+1) return k-(n+1);
    return k+n+1;
}

void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+1;i++) x[i]=i;
    for(int i=1;i<=m;i++)
    {
        char op[2];
        int u,v;
        scanf("%s",op);
        if(op[0]=='+')
        {
            scanf("%d%d",&u,&v);
            x[u]=x[v];
        }
        else if(op[0]=='-')
        {
            scanf("%d%d",&u,&v);
            x[u]=g(x[v]);
        }
        else
        {
            scanf("%d",&u);
            if(op[0]=='T') x[u]=n+1;
            else if(op[0]=='F') x[u]=2*(n+1);
            else x[u]=-1;
        }
    }
//    for(int i=1;i<=n;i++) cout<<x[i]<<' ';
//    puts("");
    for(int i=1;i<=2*(n+1);i++) fa[i]=i,tag[i]=false;
    for(int i=1;i<=n;i++)
    {
        if(x[i]==-1) continue;
        fa[find(i)]=find(x[i]);
        fa[find(g(i))]=find(g(x[i]));
    }
    for(int i=1;i<=n+1;i++)
    {
        if(x[i]==-1) fa[find(i)]=find(g(i)),tag[find(i)]=true;
        else if(find(i)==find(g(i))) tag[find(i)]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=tag[find(i)];
    printf("%d\n",ans);
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T;
    scanf("%d%d",&C,&T);
    while(T--) solve();

    return 0;
}
