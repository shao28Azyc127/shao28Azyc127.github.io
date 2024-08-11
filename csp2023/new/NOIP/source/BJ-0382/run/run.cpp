#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1010,N=100010;
int c,t,n,m,k,d,f[MAXN][MAXN],tz[MAXN][MAXN];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(c<=9&&t--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++)tz[i][j]=0,f[i][j]=0;
        }
        for(int i=1;i<=m;i++){
            int x,y,v;
            scanf("%lld%lld%lld",&x,&y,&v);
            tz[x][y]+=v;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(k,i);j++){
                tz[i][j]+=tz[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(i,k);j++){
                f[i][0]=max(f[i][0],f[i-1][j-1]);
                f[i][j]=f[i-1][j-1]-d+tz[i][j];
                //cout<<f[i][j]<<" ";
            }
            if(k<=i-1)f[i][0]=max(f[i][0],f[i-1][k]);
            //cout<<f[i][0]<<endl;
        }
        int ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,f[n][i]);
        }
        printf("%lld\n",ans);
    }
    while((c>=17&&c<=18)&&t--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);int ans=0;
        for(int i=1;i<=m;i++){
            int x,y,v;
            scanf("%lld%lld%lld",&x,&y,&v);
            if(v>=y*d){
                ans+=v-y*d;
            }
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//lylakioi