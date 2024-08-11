#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int c,T;
int n,k,m,d;
int l[N],r[N],val[N],sum[N];
int run[N],qans=-0x3f3f3f3f,ans=-0x3f3f3f3f;
void dfs(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+run[i];
        for(int i=1;i<=n-k+1;i++) if(sum[i+k-1]-sum[i-1]>k) return ;
        for(int i=1;i<=m;i++) if(sum[r[i]]-sum[l[i]-1]==r[i]-l[i]+1) ans+=val[i]-(r[i]-l[i]+1)*d; 
        qans=max(qans,ans);
        return ;
    }
    run[x]=0;
    dfs(x+1);
    run[x]=1;
    dfs(x+1);
}
void work1(){
    while(T-->0){
        ans=qans=-0x3f3f3f3f;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=n;i++) run[i]=sum[i]=0;
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&l[i],&r[i],&val[i]);
            int x=l[i],y=r[i];
            l[i]=x-y+1,r[i]=x;
        }
        dfs(1);
        printf("%lld\n",qans);
    }
    return ;
}
void work2(){
     while(T-->0){
        ans=qans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&l[i],&r[i],&val[i]);
            int x=l[i],y=r[i];
            l[i]=x-y+1,r[i]=x;
            if((r[i]-l[i]+1)*d<val[i]&&r[i]-l[i]+1<=k) qans+=val[i]-(r[i]-l[i]+1)*d;
        }
        printf("%lld\n",qans);
    }
    return ;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    if(c==1||c==2) work1();
    else if(c==17||c==18) work2();
    else work1();
}