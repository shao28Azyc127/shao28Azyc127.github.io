#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int C,T;
int n,m;

//////
int a[12],ans;
char opt[12];
int x[12],y[12];

bool chk()
{
    int b[12];
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=1;i<=m;i++)
    {
        if(opt[i]=='+')
            b[x[i]]=b[y[i]];
        else if(opt[i]=='-')
        {
            if(b[y[i]]==2) b[x[i]]=2;
            else b[x[i]]=!b[y[i]];
        }
        else if(opt[i]=='T')
            b[x[i]]=1;
        else if(opt[i]=='F')
            b[x[i]]=0;
        else if(opt[i]=='U')
            b[x[i]]=2;
    }
    for(int i=1;i<=n;i++) if(b[i]!=a[i]) return false;
    return true;
}

void dfs(int nw,int cnt)
{
    if(nw==n)
    {
        if(chk()) ans=min(ans,cnt);
        return;
    }
    for(int i=0;i<=2;i++)
    {
        a[nw+1]=i;
        if(i==2) dfs(nw+1,cnt+1);
        else dfs(nw+1,cnt);
    }
}

void solve1()
{
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%c%c",&opt[i],&opt[i]);
            if(opt[i]=='+'||opt[i]=='-')
                scanf("%d%d",&x[i],&y[i]);
            else scanf("%d",&x[i]);
        }
        ans=inf;
        dfs(0,0);
        printf("%d\n",ans);
    }
}

/////

int a2[maxn];

void solve2()
{
    int opt2,xx;
    int ans2;
    while(T--)
    {
        memset(a2,0,sizeof(a2));
        ans2=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%c%c%d",&opt2,&opt2,&xx);
            if(opt2=='T') a2[xx]=1;
            if(opt2=='F') a2[xx]=0;
            if(opt2=='U') a2[xx]=2;
        }
        for(int i=1;i<=n;i++) if(a2[i]==2) ans2++;
        printf("%d\n",ans2);
    }
}

/////

struct node3
{
    int rec;
    int fa;
}a3[maxn];

int findf3(int x3)
{
    if(a3[x3].fa==x3) return x3;
    int f=findf3(a3[x3].fa);
    a3[x3].rec=a3[x3].rec;
    return a3[x3].fa=f;
}

void solve3()
{
    char opt3;
    int x3,y3;
    int ans3;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            a3[i].fa=i;
            a3[i].rec=0;
        }
        ans3=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%c%c",&opt3,&opt3);
            if(opt3=='U')
            {
                scanf("%d",&x3);
                a3[x3].rec=3;
            }
            if(opt3=='+')
            {
                scanf("%d%d",&x3,&y3);
                a3[x3].fa=findf3(y3);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a3[i].rec==3) ans3++;
        }
        printf("%d\n",ans3);
    }
}

///

struct node4
{
    int fa,rel;
}a4[maxn];

int findf4(int x4)
{
    if(a4[x4].fa==x4) return x4;
    int f=findf4(a4[x4].fa);
    a4[x4].rel=(a4[x4].rel==a4[f].rel);
    return a4[x4].fa=f;
}

void solve4()
{
    char opt4;
    int x4,y4;
    int ans4;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            a4[i].fa=i;
            a4[i].rel=1;
        }
        ans4=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%c%c",&opt4,&opt4);
            scanf("%d%d",&x4,&y4);
            if(opt4=='+')
            {
                a4[x4].fa=findf4(y4);
                a4[x4].rel=a4[y4].rel;
            }
            if(opt4=='-')
            {
                a4[x4].fa=findf4(y4);
                a4[x4].rel=(!a4[y4].rel);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!a4[findf4(i)].rel) ans++;
        }
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&C,&T);
    if(C==1||C==2) solve1();
    if(C==3||C==4) solve2();
    if(C==5||C==6) solve3();
    if(C==7||C==8) solve4();
    return 0;
}
