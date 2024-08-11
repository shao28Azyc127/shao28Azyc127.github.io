#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
const int N=1e3+10;

int C,T,n,m,k,d;
LL f[N][N];
vector<PII> V[N];

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=n;++i) V[i].clear();
        for(int i=1;i<=m;++i){
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
            V[x].push_back({y,v});
        }
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                f[i][j]=-1e18;
        f[0][0]=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<=min(i-1,k);++j)
                f[i][0]=max(f[i][0],f[i-1][j]);
            for(int j=1;j<=min(i,k);++j){
                LL t=0;
                for(int p=0;p<V[i].size();++p)
                    if(j>=V[i][p].first) t+=V[i][p].second;
                f[i][j]=max(f[i][j],f[i-1][j-1]-d+t);
            }
        }
        LL res=0;
        for(int i=0;i<=k;++i) res=max(res,f[n][i]);
        printf("%lld\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}