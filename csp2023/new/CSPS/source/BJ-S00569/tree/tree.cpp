#include<bits/stdc++.h>
using namespace std;
#define rint register int

inline int read()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-f;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*f;
}

int u,v,x,n,q,m,day[100005],b[505][505],maxx=-1,maxday;
bool f[505][505];

struct yu{
    int a,b,c;
    int now;
} tree[100005];

inline int add(int a,int b,int c)
{
    c=c+max(tree[a].b+b*tree[a].c,1);
    return c;
}

inline int dayly(int i)
{
    int pl=0,ii=0;
    while(pl<tree[i].a)
    {
        ii++;
        pl=add(i,ii,pl);
    }
    return ii;
}
void writee()
{
    n/=2;
    int p=rand()%n;
    cout<<maxx+p;
}

signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    srand(time(0));
    for(int i=1;i<=n;++i)
        cin>>tree[i].a>>tree[i].b>>tree[i].c;
    for(int i=1;i<n;++i)
    {
        cin>>u>>v,f[u][v]=1;
    }
    for(rint i=1;i<=n;++i)
    {
        day[i]=dayly(i);
    }
    for(int i=1;i<=n;++i)
    {
        if(maxx<day[i])
            maxx=day[i];
        maxday=i;
    }
    writee();
    return 0;
}
