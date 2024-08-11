#include <bits/stdc++.h>
using namespace std;

const int NR1=1e3+100;
const int MR=1e5+100;
long long f[NR1][NR1];
long long num[NR1][NR1];
long long dp[2][110];
struct node
{
    long long l,r,v;
}q[MR];

bool cmp(node x,node y)
{
    return x.r<y.r;
}

void solve1()
{
    int n,m,k,d;
    scanf("%d%d%d%d",&n,&m,&k,&d);
    memset(num,0,sizeof(num));
    memset(f,-999999,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        num[x][y]+=v;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            num[i][j]+=num[i][j-1];
        }
    }
    f[0][0]=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            f[i][j+1]=max(f[i][j+1],f[i-1][j]-d+num[i][j+1]);
        }
        for(int j=0;j<=k;j++) f[i][0]=max(f[i][0],f[i-1][j]);
        for(int j=0;j<=k;j++) ans=max(ans,f[i][j]);
    }
    printf("%lld\n",ans);
}

void solve2()
{
}

void solve3()
{
    long long n,m,k,d;
    scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
    for(int i=1;i<=m;i++)
    {
        long long x,y,v;
        scanf("%lld%lld%lld",&x,&y,&v);
        long long l=x-y+1,r=x;
        q[i]=(node){l,r,v};
    }
    sort(q+1,q+m+1,cmp);
    q[0].l=0,q[0].r=0;
    long long now=0;
    for(int i=1;i<=m;i++)
    {
        if(q[i].r-q[i].l+1>k) continue;
        long long delta=q[i].v-d*(q[i].r-q[i].l+1);
        if(delta>0) now=now+delta;
    }
    printf("%lld\n",now);
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if(c<=9){
        while(t--) solve1();
    }
    if(c>=15&&c<=16)
    {
        while(t--) solve2();
    }
    if(c>=17&&c<=18)
    {
        while(t--) solve3();
    }
    return 0;
}
