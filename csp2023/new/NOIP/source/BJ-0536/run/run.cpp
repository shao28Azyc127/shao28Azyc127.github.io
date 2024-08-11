#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long c,t,n,m,k,d,ans=-9e18,r[1000005],rl[1000005],x[1000005],y[1000005],v[1000005];
void dfs(long long p,long long con){
    if(p>n){
        long long cnt=0;
        for(int i=1;i<=n;i++){
            if(r[i]){
                cnt-=r[i]*d;
            }
        }
        for(int i=1;i<=m;i++){
            if(rl[x[i]]>=y[i]){
                cnt+=v[i];
            }
            /*
            bool flag=1;
            for(int j=x[i];j>=x[i]-y[i]+1;j--){
                if(j<=0){
                    flag=0;
                    break;
                }
                if(!r[j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cnt+=v[i];
            }*/
        }
        ans=max(cnt,ans);
        return;
    }
    if(con<k){
        r[p]=1;
        rl[p]=con+1;
        dfs(p+1,con+1);
    }
    r[p]=0;
    rl[p]=0;
    dfs(p+1,0);

}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    for(int dnm=1;dnm<=t;dnm++){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            //cout<<1;
            cin>>x[i];
            //cout<<1;
            cin>>y[i];
            //cout<<1;
            cin>>v[i];
            //cout<<1;
            //cout<<endl;
        }//cout<<1;
        ans=-9e18;
        //cout<<1;
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
