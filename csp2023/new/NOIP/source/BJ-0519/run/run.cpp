#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int C,T,N,M,K;
long long D,f[1001][1001],g[1001],val[1001][1001];
struct Challenge
{
    int x,y;
    long long v;
    bool operator<(const Challenge &t)const
    {
        if(x==t.x) return y<t.y;
        return x<t.x;
    }
}t[100001];
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&C,&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d%d%lld",&N,&M,&K,&D);
        for(int j=1;j<=M;j++) scanf("%d%d%lld",&t[j].x,&t[j].y,&t[j].v);
        sort(t+1,t+M+1);
        for(int j=0;j<=N;j++)
            for(int k=0;k<=K;k++)
            {
                f[j][k]=g[j]=-0x3f3f3f3f3f3f3f3f;
                val[j][k]=0;
            }
        f[0][0]=g[0]=0;
        for(int j=1;j<=M;j++)
        {
            val[t[j].x][t[j].y]=max(val[t[j].x][t[j].y],val[t[j].x][t[j].y-1]);
            val[t[j].x][t[j].y]=max(val[t[j].x][t[j].y],t[j].v);
            if(j==M||t[j].x<t[j+1].x)
            {
                for(int k=t[j].y+1;k<=min(t[j].x,K);k++) val[t[j].x][k]=val[t[j].x][k-1];
            }
            else
            {
                for(int k=t[j].y+1;k<t[j+1].y;k++) val[t[j].x][k]=val[t[j].x][k-1];
            }
        }
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=min(j,K);k++)
            {
                f[j][k]=f[j-1][k-1]-D+val[j][k];
                g[j]=max(g[j],f[j][k]);
            }
            f[j][0]=g[j-1];
            g[j]=max(g[j],f[j][0]);
        }
        printf("%lld\n",g[N]);
    }
    return 0;
}