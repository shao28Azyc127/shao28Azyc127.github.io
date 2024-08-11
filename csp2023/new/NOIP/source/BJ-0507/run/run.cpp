#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010,M=100010;
int cas,T,n,m,K,d;
int r[M],y[M],idx[M]; ll v[M];
ll f[M][N],ans;
bool cmp(int a,int b)
{
    if(r[a]<r[b]) return 1;
    return 0;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&cas,&T);
    if(cas>=12)
    {
        while(T--)
        {
            scanf("%d%d%d%d",&n,&m,&K,&d);
            //for(int i=1;i<=m;i++)
            //    for(int j=0;j<=K;j++) f[i][j]=0;
            for(int i=1;i<=m;i++) scanf("%d%d%lld",&r[i],&y[i],&v[i]),idx[i]=i;
            sort(idx+1,idx+1+m,cmp); ans=0;
            for(int i=1;i<=m;i++)
                if(1ll*y[i]*d<v[i]) ans+=v[i]-1ll*y[i]*d;
            printf("%lld\n",ans);
        }
        return 0;
    }
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&K,&d);
        for(int i=1;i<=m;i++)
            for(int j=0;j<=K;j++) f[i][j]=0;
        for(int i=1;i<=m;i++) scanf("%d%d%lld",&r[i],&y[i],&v[i]),idx[i]=i;
        sort(idx+1,idx+1+m,cmp); f[0][0]=0; //r[0]=1;
        for(int i=1;i<r[1];i++) f[0][i]=-1ll*i*d;
        for(int i=1;i<=m;i++)
        {
            /*
            for(int j=0;j<=K;j++)
            {
                if(j<=r[i]-r[i-1])
                    f[i][j]=max(f[i][j],f[i-1][0]-1ll*j*d);
                if(j>r[i]-r[i-1])
                    f[i][j]=max(f[i][j],f[i-1][j-(r[i]-r[i-1])]-1ll*(r[i]-r[i-1])*d);
                if(j>=y[i]) f[i][j]+=v[i];
            }
            */
            for(int j=0;j<=K;j++)
                f[i][0]=max(f[i][0],f[i-1][j]);
            for(int j=1;j<=min(r[i]-r[i-1],y[i]-1);j++)
                f[i][j]=max(f[i][j],f[i-1][0]-1ll*j*d);
            if(y[i]<r[i]-r[i-1]+1)
                for(int j=min(r[i]-r[i-1]+1,y[i]);j<=r[i]-r[i-1];j++)
                    f[i][j]=max(f[i][j],f[i-1][0]-1ll*j*d+v[i]);
            if(y[i]>r[i]-r[i-1]+1)
                for(int j=r[i]-r[i-1]+1;j<y[i];j++)
                    f[i][j]=max(f[i][j],f[i-1][j-(r[i]-r[i-1])]-1ll*(r[i]-r[i-1])*d);
            if(y[i]==r[i]-r[i-1]+1) f[i][y[i]]=max(f[i][y[i]],f[i-1][1]-1ll*(r[i]-r[i-1])*d+v[i]);
            for(int j=max(y[i],r[i]-r[i-1]);j<=K;j++)
                f[i][j]=max(f[i][j],f[i-1][j-(r[i]-r[i-1])]-1ll*(r[i]-r[i-1])*d+v[i]);
            /*
            for(int j=0;j<y[i]-1;j++)
                f[i][j+1]=max(f[i][j+1],f[i-1][j-(r[i]-r[i-1])]-d);
            for(int j=y[i]-1;j<K;j++)
                f[i][j+1]=max(f[i][j+1],f[i-1][j]-d+v[i]);*/
        }
        ans=-0x3f3f3f3f3f3f;
        for(int i=0;i<=K;i++) ans=max(ans,f[m][i]);
        printf("%lld\n",ans);
    }
    return 0;
}
