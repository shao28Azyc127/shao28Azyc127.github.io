#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
struct Sub1{
    int n,m,k,d;
    void main(){
        while(t--){
            scanf("%d%d%d%d",&n,&m,&k,&d);
            ll ans=0;
            for(int i=1;i<=m;i++){
                int x,y,v;
                scanf("%d%d%d",&x,&y,&v);
                int l=x-y+1,r=x;
                l=max(l,1);
                r=min(r,n);
                if(y<=k) ans+=max(0ll,v-1ll*d*(r-l+1));
            }
            printf("%lld\n",ans);
        }
    }
} subtask1;
struct Expe{
    int x,y,v;
};
bool cmp(Expe x,Expe y){
    return x.x<y.x;
}
struct Sub2{
    int n,m,k,d;
    ll dp[105][262150];
    Expe es[105];
    void main(){
        while(t--){
            memset(dp,0,sizeof(dp));
            scanf("%d%d%d%d",&n,&m,&k,&d);
            for(int i=1;i<=m;i++){
                scanf("%d%d%d",&es[i].x,&es[i].y,&es[i].v);
            }
            sort(es+1,es+m+1,cmp);
            for(int i=0;i<(1<<n);i++) dp[0][i]=-1ll*__builtin_popcount(i)*d;
            for(int i=1;i<=m;i++){
                memcpy(dp[i],dp[i-1],sizeof(dp[i-1]));
                for(int j=0;j<(1<<n);j++){
                    int o=__builtin_popcount(j);
                    int ns=((j|(((1<<es[i].y)-1)<<(es[i].x-es[i].y)))&((1<<n)-1));
                    int D=__builtin_popcount(ns)-o;
                    dp[i][ns]=max(dp[i][ns],dp[i-1][j]+es[i].v-1ll*D*d);
                }
            }
            ll ans=0;
            for(int i=0;i<(1<<n);i++){
                int mx=0,l=0;
                for(int j=0;j<=n;j++){
                    if((i&(1<<j))!=0){
                        l++;
                    }
                    else{
                        mx=max(mx,l);
                        l=0;
                    }
                }
                if(mx<=k) ans=max(ans,dp[m][i]);
            }
            printf("%lld\n",ans);
        }
    }
} subtask2;
int main(){
    #ifndef JZQ
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    #endif
    scanf("%d%d",&c,&t);
    if(c==17||c==18){
        subtask1.main();
    }
    if(c==1||c==2){
        subtask2.main();
    }
    return 0;
}