#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int C,N,M,Q;
int a[MAXN],b[MAXN],na[MAXN],nb[MAXN],sa[MAXN],sb[MAXN],ea[MAXN],eb[MAXN];
bool flag=0;
void dfsb(int p,int t)
{
    if(flag) return;
    if(p==M)
    {
        int ind=0;
       /* for(int i=1;i<=N;i++) printf("[%d]",sa[i]);
        for(int i=1;i<=M;i++) printf("{%d}",sb[i]);
        puts("---");
        printf("nextS%d %d\n",sa[N+1],sb[M+1]);*/
        for(int i=1;i<=N;i++)
        {
            for(int j=sa[i];j<sa[i+1];j++) ea[++ind]=na[i];
        }
        ind=0;
        for(int i=1;i<=M;i++)
        {
            for(int j=sb[i];j<sb[i+1];j++) eb[++ind]=nb[i];
        }
        for(int i=2;i<=N+M;i++)
        {
            if(1ll*(ea[i]-eb[i])*(ea[1]-eb[1])<=0ll) return;
        }
      /*  for(int i=1;i<=N+M;i++) printf("[%d]",ea[i]);
        puts("----");
        for(int i=1;i<=M+M;i++) printf("{%d}",eb[i]);
        puts("---");*/
        flag=1;
        return;
    }
    for(int i=t+1;i<=N+M;i++)
    {
        sb[p+1]=i;
        dfsb(p+1,i);
    }
    return;
}
void dfsa(int p,int t)
{
    if(flag) return;
    if(p==N)
    {
        dfsb(1,1);
        return;
    }
    for(int i=t+1;i<=N+M;i++)
    {
        sa[p+1]=i;
        dfsa(p+1,i);
    }
    return;
}
void Solve()
{
    sa[1]=1,sb[1]=1;
    flag=0;
    if(C>4) 
    {
        if(1ll*(na[1]-nb[1])*(na[N]-nb[M])<=0ll) 
        {
            printf("0");
            return;
        }
        printf("1");
        return;
    }
    dfsa(1,1);
    printf(flag?"1":"0");
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d %d %d %d",&C,&N,&M,&Q);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=1;i<=M;i++) scanf("%d",&b[i]);
    for(int i=1;i<=N;i++) na[i]=a[i];
    for(int i=1;i<=M;i++) nb[i]=b[i];
    sa[N+1]=N+M+1,sb[M+1]=N+M+1;
    Solve();
    while(Q--)
    {
        int kx,ky;
        for(int i=1;i<=N;i++) na[i]=a[i];
        for(int i=1;i<=M;i++) nb[i]=b[i];
        scanf("%d %d",&kx,&ky);
        for(int i=1;i<=kx;i++)
        {
            int p,v;
            scanf("%d %d",&p,&v);
            na[p]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            int p,v;
            scanf("%d %d",&p,&v);
            nb[p]=v;
        }
        Solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}