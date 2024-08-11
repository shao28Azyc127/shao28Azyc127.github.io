//Please let me AC testcase 8~9
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int id,t,n,m,k,d;
long long f[1010][1010],ans;
long long g[100010][110];
struct chl{int id,x,w;};
vector<chl>v[1010];

chl c[100010];
bool cmp(const chl &x,const chl &y){
    return x.id<y.id;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&id,&t);
    if(id<=9)
    {
        while(t--)
        {
            scanf("%d%d%d%d",&n,&m,&k,&d);
            for(int i=1;i<=n;i++)
                v[i].clear();
            for(int i=1;i<=m;i++)
            {
                int x,y,w;
                scanf("%d%d%d",&x,&y,&w);
                v[x].push_back({x,y,w});
            }
            memset(f,-999999,sizeof(f));
            f[0][0]=0,ans=0;
            for(int i=1;i<=n;i++)
                for(int j=0;j<=k;j++)
                {
                    if(j>0)f[i][j]=f[i-1][j-1]-d;
                    else for(int p=0;p<=k;p++)
                            f[i][j]=max(f[i][j],f[i-1][p]);
                    for(auto p:v[i])
                        if(j>=p.x)f[i][j]+=p.w;
                    if(i==n)ans=max(ans,f[i][j]);
                }
            printf("%lld\n",ans);
        }
    }
    else if(id==15||id==16)
    {
        while(t--)
        {
            scanf("%d%d%d%d",&n,&m,&k,&d);
            for(int i=1;i<=m;i++)
                scanf("%d%d%d",&c[i].id,&c[i].x,&c[i].w);
            c[++m]={n,0,0};
            sort(c+1,c+m+1,cmp);
            memset(g,-999999,sizeof(g));
            g[0][0]=0,ans=0;
            for(int i=1;i<=m;i++)
            {
                int dis=c[i].id-c[i-1].id;
                for(int j=0;j<=k;j++)
                {
                    if(j>0)g[i][j]=g[i-1][max(0,j-dis)]-1ll*min(j,dis)*d;
                    else if(dis>0)
                        for(int p=0;p<=k;p++)
                            g[i][j]=max(g[i][j],g[i-1][p]);
                    else g[i][j]=g[i-1][j];
                    if(j>=c[i].x)g[i][j]+=c[i].w;
                    if(i==m)ans=max(ans,g[i][j]);
                }
            }
            /*for(int i=1;i<=m;i++)
            {
                for(int j=0;j<=k;j++)
                    cout<<g[i][j]<<" ";
                cout<<endl;
            }*/
            printf("%lld\n",ans);
        }
    }
    return 0;
}