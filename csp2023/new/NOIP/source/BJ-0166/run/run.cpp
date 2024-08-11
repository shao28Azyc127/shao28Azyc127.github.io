#include<bits/stdc++.h>
using namespace std;
long long x[100005],y[100005],v[100005];
long long dk[100005],S[100005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long n,m,k,d;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
        }
        if(n<=18){
            long long ful=(1<<n)-1;
            long long ans=-1e17;
            for(int i=1;i<=ful;i++){
                for(int j=0;j<=n;j++){
                    S[j]=0;
                }
                long long p=i,f=1;
                for(int j=1;j<=n;j++){
                    if(p&1) dk[j]=1;
                    else dk[j]=0;
                    p/=2;
                }
                for(int j=1;j<=n;j++) S[j]=S[j-1]+dk[j];
                for(int i=1;i<=n-k;i++){
                    if(S[i+k]-S[i-1]==k+1){
                        f=0;
                        break;
                    }
                }
                if(f==0) continue;
                long long res=0;
                for(int j=1;j<=n;j++){
                    if(dk[j]){
                        res-=d;
                    }
                }
                for(int j=1;j<=m;j++){
                    if(S[x[j]]-S[x[j]-y[j]]==y[j]){
                        res+=v[j];
                    }
                }
                ans=max(ans,res);
            }
            printf("%lld\n",ans);
        }else{
            long long ans=0;
            for(int i=1;i<=m;i++){
                int l=x[i]-y[i]+1,r=x[i];
                if(r-l+1>k) continue;
                if(v[i]>(r-l+1ll)*d){
                    ans+=v[i]-(r-l+1ll)*d;
                }
            }
            printf("%lld\n",ans);
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
